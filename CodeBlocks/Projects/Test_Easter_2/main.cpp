#include <stdio.h>
#include <time.h>

#define MAX_FTAGE 15    /* TODO: add all Feiertage */
#define MONAT 0         /* offset 2d array for month */
#define TAG 1           /* offset 2d array for day */

static int year = 2014; /* default, can be set by argument */

static char* gcFTage[] = {
    "Neujahr",
    "Erscheinungsfest",
    "Karfreitag",
    "Ostersonntag",
    "Ostermontag",
    "Maifeiertag",
    "ChrHimmelfahrt",
    "Pfingstmontag",
    "Fronleichnam",
    "MraHimmelfahrt",
    "DtEinheit",
    "Reformationstag",
    "Allerheiligen",
#if 0
    "BBtag",
#endif
    "Weihnacht1",
    "Weihnacht2"
};

enum Monat {
    Januar = 0,
    Februar,
    Maerz,
    April,
    Mai,
    Juni,
    Juli,
    August,
    September,
    Oktober,
    November,
    Dezember
};

enum Feiertag {
    Neujahr = 0,        /* FIX    */
    Erscheinungsfest,   /* FIX    */
    Karfreitag,         /* OS -2  */
    Ostersonntag,       /* GAUS   */
    Ostermontag,        /* OS +1  */
    Maifeiertag,        /* FIX    */
    ChrHimmelfahrt,     /* OS +39 */
    Pfingstmontag,      /* OS +50 */
    Fronleichnam,       /* OS +60 */
    MraHimmelfahrt,     /* FIX    */
    DtEinheit,          /* FIX    */
    Reformationstag,    /* FIX    */
    Allerheiligen,      /* FIX    */
#if 0
    BBtag,              /* TODO   */
#endif
    Weihnacht1,         /* FIX    */
    Weihnacht2          /* FIX    */
};

static int giFTage [MAX_FTAGE][2]; /* FEIERTAG, MONAT, TAG */
static int giNumFTagePMonth [12];  /* Anzahl Feiertage pro Monat */

void initFTage()
{
    int i=0;
    for(i; i<MAX_FTAGE; i++) {
        giFTage[i][MONAT] = -1;
        giFTage[i][TAG] = -1;
    }
}

/*
 *
 *  daysToAdvance can be negative to substract days
 *  resDay and resMonth are out parameters
 *  day, month and year are in paramters
 *
 */
void addDays(int daysToAdvance, int *resDay, int *resMonth,int day,int month, int year) {
        struct tm date = {0} ;
        time_t time ;
        date.tm_year = year;
        date.tm_mon = month;
        date.tm_mday = day + daysToAdvance ;
        time = mktime( &date ) ;
        date = *localtime( &time ) ;
        *resDay = date.tm_mday;
        *resMonth = date.tm_mon;
}

/*
 *  Setzt variable Feiertage
 */
void setVarFTage(int tagOS, int monatOS)
{
    int day, month;
    addDays(-2,&day,&month,tagOS,monatOS,year);
    giFTage[Karfreitag][MONAT] = month-1;
    giFTage[Karfreitag][TAG] = day;
    giFTage[Ostersonntag][MONAT] = monatOS-1;
    giFTage[Ostersonntag][TAG] = tagOS;
    addDays(1,&day,&month,tagOS,monatOS,year);
    giFTage[Ostermontag][MONAT] = month-1;
    giFTage[Ostermontag][TAG] = day;
    addDays(39,&day,&month,tagOS,monatOS,year);
    giFTage[ChrHimmelfahrt][MONAT] = month-1;
    giFTage[ChrHimmelfahrt][TAG] = day;
    addDays(50,&day,&month,tagOS,monatOS,year);
    giFTage[Pfingstmontag][MONAT] = month-1;
    giFTage[Pfingstmontag][TAG] = day;
    addDays(60,&day,&month,tagOS,monatOS,year);
    giFTage[Fronleichnam][MONAT] = month-1;
    giFTage[Fronleichnam][TAG] = day;
}

/*
 *  Setzt fixe Feiertage
 */
void setFixFTage()
{
    giFTage[Neujahr][MONAT] = Januar;
    giFTage[Neujahr][TAG] = 1;
    giFTage[Erscheinungsfest][MONAT] = Januar;
    giFTage[Erscheinungsfest][TAG] = 6;
    giFTage[Maifeiertag][MONAT] = Mai;
    giFTage[Maifeiertag][TAG] = 1;
    giFTage[MraHimmelfahrt][MONAT] = August;
    giFTage[MraHimmelfahrt][TAG] = 15;
    giFTage[DtEinheit][MONAT] = Oktober;
    giFTage[DtEinheit][TAG] = 3;
    giFTage[Reformationstag][MONAT] = Oktober;
    giFTage[Reformationstag][TAG] = 31;
    giFTage[Allerheiligen][MONAT] = November;
    giFTage[Allerheiligen][TAG] = 1;
    giFTage[Weihnacht1][MONAT] = Dezember;
    giFTage[Weihnacht1][TAG] = 25;
    giFTage[Weihnacht2][MONAT] = Dezember;
    giFTage[Weihnacht2][TAG] = 26;
}

/*
 *  Ostersonntag zur berechnung variabler Feiertage
 */
void getOsterdatum(const unsigned int uJahr, unsigned int *uTag, unsigned int *uMonat)
{
  // Berechnet für ein beliebiges Jahr das Osterdatum.

  // Quelle des Gauss - Algorithmus: Stefan Gerth,
  // "Die Gauß'sche Osterregel", Nürnberg, Februar 2003.
  // http://krapfen.org/content/paper/Schule/Facharbeit/Berechnung_des_Osterfestes.pdf

  unsigned int a = uJahr % 19;
  unsigned int b = uJahr %  4;
  unsigned int c = uJahr %  7;

  int k = uJahr / 100;
  int q = k / 4;
  int p = ((8 * k) + 13) / 25;
  unsigned int Egz = (38 - (k - q) + p) % 30; // Die Jahrhundertepakte
  unsigned int M = (53 - Egz) % 30;
  unsigned int N = (4 + k - q) % 7;

  unsigned int d = ((19 * a) + M) % 30;
  unsigned int e = ((2 * b) + (4 * c) + (6 * d) + N) % 7;

  // Ausrechnen des Ostertermins:
  if ((22 + d + e) <= 31)
  {
    *uTag = 22 + d + e;
    *uMonat = 3;
  }
  else
  {
    *uTag = d + e - 9;
    *uMonat = 4;

    // Zwei Ausnahmen berücksichtigen:
    if (uTag == 26)
      uTag = 19;
    else if ((uTag == 25) && (d == 28) && (a > 10))
      uTag = 18;
  }

  // Offsets für andere Feiertage:

  // Schwerdonnerstag / Weiberfastnacht -52
  // Rosenmontag -48
  // Fastnachtsdienstag -47
  // Aschermittwoch -46
  // Gründonnerstag -3
  // Karfreitag -2
  // Ostersonntag 0
  // Ostermontag +1
  // Christi Himmelfahrt +39
  // Pfingstsonntag +49
  // Pfingstmontag +50
  // Fronleichnam +60

  // Mariä Himmelfahrt ist stets am 15. August (Danke an Michael Plugge!)
}

/*
 *  Berechnet anzahl Feiertage per Monat
 */
void setNumFTagePMonth()
{
    int i,j,idx,month;
    idx = month = 0;
    for(i=0; i<12; i++)
        giNumFTagePMonth[i] = 0;

    i=0; j=0;
    while(i<12) {
        do {
            month = giFTage[j][MONAT]; /* j in 0 .. MAX_FTAGE*/
            giNumFTagePMonth[i]++; /* i in 0 .. 12 */
        }while(j < MAX_FTAGE -1 && month == giFTage[++j][MONAT]);
        if(-1 != giFTage[j][MONAT])
            i = giFTage[j][MONAT];
        if(j == MAX_FTAGE -1)
            break;
    }
}

/*
 *  Berechnet ob übergebener Tag ein Feiertag ist
 */
int isFTag(struct tm day)
{
    int offset, numDays;
    int i,j;
    for(i=0; i<MAX_FTAGE; i++)
    {
        /* ist der monat vorhanden? */
        if(giFTage[i][MONAT]+1 == day.tm_mon) {
            offset = giFTage[i][MONAT];
            /* anzahl feiertage in diesem monat? */
            numDays = giNumFTagePMonth[offset];
            for(j=i; j<i+numDays; j++){
                /* ist der tag vorhanden? */
                if(giFTage[j][TAG] == day.tm_mday){
                    return j;
                }
            }//tag?
        }//monat?
    }//alle ftage
    return -1;
}//isFTag


/*
 *  Einstiegspunkt
 */
int main(int argc, char *argv[])
{
    int i=0,sum=0, res=0;
    unsigned int day=0, month=0;

    struct tm testDay;
    /*
     *  ARGUMENTS:
     *
     *  $1  DAY, used as test day for a date
     *  $2  MONTH, used as test month for a date
     *  $3  YEAR, used as test year for a date AND as year for calendar
     */
    if(argc == 4) {
        testDay.tm_mday = atoi(argv[1]);
        testDay.tm_mon = atoi(argv[2]);
        testDay.tm_year = atoi(argv[3]);
        year = atoi(argv[3]);
    }
    else /* DEFAULT */
    {
        testDay.tm_mday = 31;
        testDay.tm_mon = 10;
        testDay.tm_year = 2014;
        year = 2014;
    }

    initFTage();
    setFixFTage();
    getOsterdatum(year, &day, &month);
    setVarFTage(day,month);
    setNumFTagePMonth();
#ifdef DDEBUG
    for(i; i<MAX_FTAGE; i++)
        printf("%s: %d %d \n",gcFTage[i],giFTage[i][MONAT]+1,giFTage[i][TAG]);

    for(i=0; i<12; i++){
        sum+=giNumFTagePMonth[i];
        printf("NUM days in %d are %d \n",i,giNumFTagePMonth[i]);
    }
    printf("SUM: %d\n",sum);
#endif
    res = isFTag(testDay);
    if(-1 == res)
        printf("TESTDAY is not a Feiertag");
    else
        printf("TESTDAY is %s\n",gcFTage[res]);

    return 0;
}//main


