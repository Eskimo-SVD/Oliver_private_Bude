/* read3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#ifdef __unix__
      #include <unistd.h>
      #include <sys/stat.h>
      #include <sys/types.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
      #include <sys\stat.h>
#endif
#define MAXADRESSEN 10
#define MAX 30

struct kunde  {
   char name[MAX];
   char vorname[MAX];
   int kundenummer;
   char ort[MAX];
   char strasse[MAX];
   int hausnummer;
   int vorwahl;
   int telefonnr;
};

struct kunde k[MAXADRESSEN];
static int counter=0;

void neukunde(void) {
   int fh;

   if(counter==MAXADRESSEN)
      printf("Kein Speicherplatz mehr frei!!!\n");
   else {
      printf("Name...................: ");
      fgets(k[counter].name, MAX, stdin);
      printf("Vorname................: ");
      fgets(k[counter].vorname, MAX, stdin);
      k[counter].kundenummer=counter;
      printf("Ort....................: ");
      fgets(k[counter].ort, MAX, stdin);
      printf("Strasse................: ");
      fgets(k[counter].strasse, MAX, stdin);
      printf("Hausnummer.............: ");
      do {
         scanf("%d",&k[counter].hausnummer);
      } while(getchar() != '\n');
      printf("Vorwahl................: ");
      do {
         scanf("%d",&k[counter].vorwahl);
      } while(getchar() != '\n');
      printf("Telefonnummer..........: ");
      do {
         scanf("%d",&k[counter].telefonnr);
      } while(getchar() != '\n');

      if((fh=open("kunden.dat",O_CREAT|O_RDWR)) == -1)
         printf("Konnte\"kunden.dat\" nicht öffnen\n");
      else if((write(fh,&k,sizeof(k))) == -1)
           printf("Konnte nicht in \"kunden.dat\" schreiben\n");
      else
         counter++;
   }
}

void lese(void) {
   int fh;
   int num;

   printf("Bitte geben Sie die Kundennummer ein : ");
   scanf("%d",&num);

   if( (fh = open("kunden.dat",O_RDONLY)) == -1) {
      perror("Kann Kundendatei nicht öffnen");
      exit(EXIT_FAILURE);
   }
   read(fh,&k,sizeof(k));
   printf("\n\n");
   printf("Name..........%s",k[num].name);
   printf("Vorname.......%s",k[num].vorname);
   printf("Kundennummer..%d\n",k[num].kundenummer);
   printf("Wohnort.......%s",k[num].ort);
   printf("Strasse.......%s",k[num].strasse);
   printf("Hausnummer....%d\n",k[num].hausnummer);
   printf("Vorwahl.......%d\n",k[num].vorwahl);
   printf("Telefonnum....%d\n",k[num].telefonnr);
}

int main(void) {
   int wahl;

   do {
      printf("\t1: Neuen Kunden eingeben\n\n");
      printf("\t2: Kunden ausgeben\n\n");
      printf("\t3: Programmende\n\n");
      printf("\tEingabe :> ");
      do {
         scanf("%d",&wahl);
      }while(getchar() != '\n');
      switch(wahl) {
         case 1 : neukunde(); break;
         case 2 : lese(); break;
         case 3 : printf("bye\n"); break;
         default: printf("Falsche Eingabe!!!\n");
      }
   } while(wahl != 3);
   return EXIT_SUCCESS;
}

