/* typedef1.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

static int x;

struct adres {
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
} adressen[100];

typedef struct adres ADRESSE;

void Eingabe(int nr, ADRESSE *neu) {
   printf("Vorname : ");
   fgets(neu[nr].vname, MAX, stdin);
   printf("Nachname : ");
   fgets(neu[nr].nname, MAX, stdin);
   printf("Postleitzahl: ");
   do {
      scanf("%5ld",&neu[nr].PLZ);
   } while(getchar()!= '\n');
   printf("Wohnort : ");
   fgets(neu[nr].ort, MAX, stdin);
   printf("Geburtsjahr : ");
   do {
      scanf("%4d",&neu[nr].geburtsjahr);
   } while(getchar()!= '\n');
}

void Suche(ADRESSE *search, char buchstabe, int nr) {
   int i;
   for(i = 0; i <= nr; i++)  {
      if(search[i].nname[0] == buchstabe) {
         printf("\n\nGefunden unter Buchstabe :\"%c\"\n\n",
            buchstabe);
         printf("Vorname.......:%s",search[i].vname);
         printf("Nachname......:%s",search[i].nname);
         printf("Postleitzahl..:%ld\n",search[i].PLZ);
         printf("Ort...........:%s",search[i].ort);
         printf("Geburtsjahr...:%d\n",search[i].geburtsjahr);
         printf("\n\tWeiter mit <ENTER>\n");
         getchar();
      }
   }
}

void Ausgabe(ADRESSE *all, int nr) {
   int i;

   for(i = 0; i < nr; i++) {
      printf("Vorname.........:%s",all[i].vname);
      printf("Nachname........:%s",all[i].nname);
      printf("Postleitzahl....:%ld\n",all[i].PLZ);
      printf("Ort.............:%s",all[i].ort);
      printf("Geburtsjahr.....:%d\n\n",all[i].geburtsjahr);

      if( (!(i%2)) && i!=0)  {
         //fflush(stdin);
         printf("\n\tWeiter mit <Enter>\n\n");
         getchar();
      }
   }
}

void Sort(ADRESSE *sort,int nr) {
   ADRESSE *temp;
   int i,j;

   temp = malloc(sizeof(ADRESSE));
   if(NULL == temp) {
      printf("Konnte keinen Speicher reservieren ...\n");
      return;
   }
   for(i = 0; i < nr; i++) {
      for(j=i+1;j<nr;j++) {
         if(strcmp(sort[i].nname, sort[j].nname)>0) {
            *temp=sort[j];
            sort[j]=sort[i];
            sort[i]=*temp;
         }
      }
   }
   printf("... sortiert!!\n");
}

int main(void) {
   int auswahl;
   char c;

   do {
      printf("-1- Neue Adresse eingeben\n");
      printf("-2- Bestimmte Adresse ausgeben\n");
      printf("-3- Alle Adressen ausgeben\n");
      printf("-4- Adressen sortieren\n");
      printf("-5- Programm beenden\n");
      printf("\nIhre Auswahl : ");
      scanf("%d",&auswahl);
      /* fflush(stdin); */
      getchar();
      switch(auswahl) {
         case 1 : Eingabe(x++,adressen);        break;
         case 2 : printf("Anfangsbuchstabe Nachnamen :");
                  do {
                     scanf("%c",&c);
                  } while(getchar()!= '\n');
                  Suche(adressen,c,x);
                  break;
         case 3 : Ausgabe(adressen,x);          break;
         case 4 : Sort(adressen,x);             break;
         default: break;
      }
   } while(auswahl < 5);
   return EXIT_SUCCESS;
}

