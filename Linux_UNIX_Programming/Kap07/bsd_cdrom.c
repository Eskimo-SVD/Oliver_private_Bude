/* bsd_cdrom.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/cdio.h>
#include <sys/ioctl.h>

/* Bitte anpassen */
#define DEVICE "/dev/rcd0c"

#define COMMAND(s) strncmp(cmd,s,strlen(s))==0

struct cd_toc_entry toc_buffer[100];
int cd_fd = -1;
int standalone;

char *cmd;

static int  pause (void), resume (void), 
      stop (void), eject (void),
      setvol (int, int),
      read_toc_header (struct ioc_toc_header *), 
      read_toc_entry (int), 
      play_msf (int, int, int, int, int, int),
      play_track (int, int),
      get_vol (int *, int *),
      status (int *, int *, int *, int *);
static void open_cd (void);
static int input (void);

int main (int argc, char **argv) {
  int rc;

  standalone = isatty (0);

  while (input ())  {
    rc = 0;
    open_cd ();

    if (COMMAND ("play")) {
      int start, end;
      sscanf (cmd+4, "%d %d", &start, &end);
      rc = play_track (start, end);
    } 
    else if (COMMAND ("help")) {
      printf("play, pause, resume, stop, eject, setvol, tochdr, msfplay, tocentry, status, quit\n");
    }
    else if (COMMAND ("pause"))
      rc = pause ();
    else if (COMMAND ("resume"))
      rc = resume ();
    else if (COMMAND ("stop"))
      rc = stop ();
    else if (COMMAND ("eject")) {
      rc = eject ();
      close (cd_fd);
      cd_fd = -1;
    }
    else if (COMMAND ("setvol")) {
      int l, r;
      sscanf (cmd+6, "%d %d", &l, &r);
      rc = setvol (l, r);
    } 
    else if (COMMAND ("tochdr")) {
      struct ioc_toc_header h;
      rc = read_toc_header (&h);
      printf ("%d %d %d\n", h.len, h.starting_track, h.ending_track);
    }
    else if (COMMAND ("msfplay")) {
      int m1, m2, s1, s2, f1, f2;
      sscanf(cmd+7, "%d%d%d%d%d%d", &m1, &s1, &f1, &m2, &s2, &f2);
      rc = play_msf (m1, s1, f1, m2, s2, f2);
    } 
    else if (COMMAND ("tocentry")) {
      struct ioc_toc_header h;
      int i, n;
      rc = read_toc_header (&h);
      n =  h.ending_track - h.starting_track + 1;
      rc = read_toc_entry ((n+2)*sizeof(struct cd_toc_entry));
      toc_buffer[n].track = 255;
      for (i = 0; i <= n; i++)
#ifdef __NetBSD__

        printf ("Track %d: %d %d %d\n",
                toc_buffer[i].track,
                toc_buffer[i].addr[1],
                toc_buffer[i].addr[2],
                toc_buffer[i].addr[3]);

#else

        printf ("%d %d %d %d\n",
                toc_buffer[i].track,
                toc_buffer[i].addr.msf.minute,
                toc_buffer[i].addr.msf.second,
                toc_buffer[i].addr.msf.frame);

#endif

    } 
    else if (COMMAND ("status")) {
      int trk, m, s, f;
      if (cd_fd < 0)
        rc = -1; /* assume ejected */
      else
        rc = status (&trk, &m, &s, &f);
      printf ("%d %02d %d %d %d\n", rc, trk, m, s, f);
    }
    else if (COMMAND("quit"))
      break;
    fflush (stdout);
    if (rc < 0 && standalone)
      perror("cdplayer");
  }
  exit (EXIT_SUCCESS);
}

static int play_track (int start, int end) {
  struct ioc_play_track t;
  
  t.start_track = start;
  t.start_index = 1;
  t.end_track = end;
  t.end_index = 1;
  return ioctl (cd_fd, CDIOCPLAYTRACKS, &t);
}

static int pause (void) {
  return ioctl (cd_fd, CDIOCPAUSE);
}

static int resume (void) {
  return (ioctl (cd_fd, CDIOCRESUME));
}

static int stop (void) {
  return ioctl (cd_fd, CDIOCSTOP);
}

static int eject (void) {
  int rc = ioctl (cd_fd, CDIOCALLOW);
  return rc ? rc : ioctl (cd_fd, CDIOCEJECT);
}

static int setvol (int l, int r) {
  struct ioc_vol v;

  v.vol[0] = l;
  v.vol[1] = r;
  v.vol[2] = 0;
  v.vol[3] = 0;
  return ioctl (cd_fd, CDIOCSETVOL, &v);
}

static int getvol (int  *l, int *r) {
  struct ioc_vol v;

  if (ioctl (cd_fd, CDIOCGETVOL, &v) < 0)
    return -1;
  *l = v.vol[0];
  *r = v.vol[1];
  return 0;
}

static int read_toc_header (struct ioc_toc_header *h) {
  return ioctl (cd_fd, CDIOREADTOCHEADER, (char *) h);
}

static int read_toc_entry (int len) {
  struct ioc_read_toc_entry t;

  t.address_format = CD_MSF_FORMAT;
  t.starting_track = 0;
  t.data_len = len;
  t.data = toc_buffer;
  return ioctl (cd_fd, CDIOREADTOCENTRYS, (char *) &t);
}

static int play_msf (int start_m, int start_s, int start_f,
          int end_m, int end_s, int end_f) {
  struct ioc_play_msf a;

  a.start_m = start_m;
  a.start_s = start_s;
  a.start_f = start_f;
  a.end_m = end_m;
  a.end_s = end_s;
  a.end_f = end_f;
  return ioctl (cd_fd, CDIOCPLAYMSF, (char *) &a);
}

static int status (int *trk, int *min, int *sec, int *frame) {
  struct ioc_read_subchannel s;
  struct cd_sub_channel_info data;
  bzero(&s, sizeof(s));
  s.data = &data;
  s.data_len = sizeof (data);
  s.address_format = CD_MSF_FORMAT;
  s.data_format = CD_CURRENT_POSITION;
  open_cd ();

  if (ioctl (cd_fd, CDIOCREADSUBCHANNEL, (char *) &s) < 0)
    return -1;
  *trk = s.data->what.position.track_number;
  
#ifdef __NetBSD__

  *min = s.data->what.position.reladdr[1];
  *sec = s.data->what.position.reladdr[2];
  *frame = s.data->what.position.reladdr[3];

#else

  *min = s.data->what.position.reladdr.msf.minute;
  *sec = s.data->what.position.reladdr.msf.second;
  *frame = s.data->what.position.reladdr.msf.frame;

#endif
  return s.data->header.audio_status;
}

static int input (void) {
  int    len;

  if (standalone)
    fprintf (stderr, "CD>");

#if defined(sun) || defined(__FreeBSD__) || defined(__OpenBSD__)

  cmd = fgetln (stdin, &len);

#else

  cmd = fgetline (stdin, 0);

#endif

  return cmd != 0;
}

static void open_cd (void) {
  int trk, m, s, f;
  extern int errno;

  if (cd_fd > -1)
    return;

  cd_fd = open (DEVICE, O_RDONLY);

  if (cd_fd < 0) {
    if (errno == ENXIO)
      return; /* open says 'Device not configured if there is no cd in */
    perror("open");
    exit (EXIT_FAILURE);
  }
  if (status (&trk, &m, &s, &f) < 0 ) {
    close (cd_fd);
    cd_fd = -1;
  }
}

