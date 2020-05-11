/* md_array2.c */
#include <stdio.h>
#include <stdlib.h>

#define ARBEITER 3
#define TAGE     5

int zeitkonto[ARBEITER][TAGE]; 

/* Fehlerausgabe */
void error(int n) {
   printf("%d (?) Falsche Eingabe!!\n",n);
}

/* -1- Ausgabe der Wochenarbeitszeit je Arbeiter */
void ArbeiterWochenStunden(void) {
   int i,j,tmp;

   for(i=0; i < ARBEITER; i++) {
      tmp=0;
      printf("Wochenarbeitszeit von Arbeiter Nr. %d\n", i+1);
      printf("-------------------------------------\n");
      for(j=0; j < TAGE; j++) {
         printf("|%d Std.", zeitkonto[i][j]);
         tmp += zeitkonto[i][j];
      }
      printf("| = Ges. %d Std.\n\n",tmp);
   }
}

/* -2- Durchschnittszeiten pro Tag in der Woche je Arbeiter */
void ArbeiterTagesDurchschnitt(void) {
   int i,j,tmp;

   for(i=0; i < ARBEITER; i++) {
      tmp=0;
      printf("Durchschn. pro Tag/Woche Arbeiter: %d\n",i+1);
      printf("-------------------------------------------\n");
      for(j=0; j < TAGE; j++) {
         tmp+=zeitkonto[i][j];
      }
      printf("Durchschn. v. Arbeiter %d p. Tag: %.1f " 
             "Std/Tag\n\n" , i+1, (float)tmp / TAGE);
   }
}

/* -3- Durchschnittszeit aller Arbeiter pro Tag */
void TeamTagesDurchschnitt(void) {
   int i,j,tmp;

   for(i=0; i < TAGE; i++) {
      tmp=0;
      printf("Durchschn. Arbeitszeit aller Mitarbeiter pro "
             "Tag %d = ", i+1);
      for(j=0; j < ARBEITER; j++) {
         tmp += zeitkonto[j][i];
      }
      printf("%.1f Std.\n\n",(float)tmp/ARBEITER);
   }
}

/* -4- Gesamtstunden aller Arbeiter in der Woche */
void TeamWochenStunden(void) {
   int i, j, tmp=0;

   printf("Gesamtstunden aller Arbeiter in der Woche\n");
   printf("-----------------------------------------\n");
   for(i=0; i < ARBEITER; i++) {
      for(j=0; j < TAGE; j++) {
         tmp+=zeitkonto[i][j];
      }
   }
   printf("Gesamtstunden aller Arbeiter i. d. Woche: "
          " %d Std.\n" , tmp);
}

/* Stundenübersicht eines einzelnen Arbeiters */
void ArbeiterStundenUebersicht(void) {
   int arb,tag;

   printf("Welcher Arbeiter: ");
   scanf("%d", &arb);
   printf("Welcher Tag: ");
   scanf("%d", &tag);
   if(arb > ARBEITER) {
      printf("Die Firma hat nur %d Arbeiter\n", ARBEITER);
      return;
   }
   else if(tag > TAGE) {
      printf("Es werden nur %d Tage gespeichert\n", TAGE);
      return;
   }
   printf("Arbeiter Nr.%d hat am Tag %d : ", arb, tag);
   printf("%d Stunden gearbeitet!\n\n", zeitkonto[arb-1][tag-1]);
}

int main(void) {
   int abfrage, i, j;

   for(i=0; i < TAGE; i++) {
      printf("\n\tTag %d in der Woche\n",i+1);
      printf("\t-------------------\n\n");
      for(j=0; j < ARBEITER; j++) {
         printf("Arbeiter Nr.%d in Std.: ",j+1);
         scanf("%d",&zeitkonto[j][i]);
         if(zeitkonto[j][i] > 24)
            printf("Ein Tag hat nur 24 Stunden?\n");
      }
   }
   do {
      printf("\n\n");
      printf("\t-1- Stundenwoche\n");
      printf("\t-2- Durchschnitt/Tag\n");
      printf("\t-3- Durchschnitt aller Arbeiter/Tag\n");
      printf("\t-4- Stunden aller Arbeiter/Woche\n");
      printf("\t-5- Einzelauswahl eines Arbeiters\n");
      printf("\t-6- ENDE\n");
      printf("\n\tIhre Wahl : ");
      scanf("%1d",&abfrage);
      printf("\n");

      switch(abfrage) {
         case 1  : ArbeiterWochenStunden();
                   break;
         case 2  : ArbeiterTagesDurchschnitt();
                   break;
         case 3  : TeamTagesDurchschnitt();
                   break;
         case 4  : TeamWochenStunden();
                   break;
         case 5  : ArbeiterStundenUebersicht();
                   break;
         case 6  : break;
         default : error(abfrage);
      }
   } while(abfrage != 6);
   return EXIT_SUCCESS;
}

