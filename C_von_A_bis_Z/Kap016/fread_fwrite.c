/* fread_fwrite.c */
#include <stdio.h>
#include <stdlib.h>

struct {
   char vorname[20];
   char nachname[30];
   char strasse[30];
   char hausnummer[5];
   char plz[7];
   char ort[30];
   char sternzeichen[30];
   char alter[3];
} adressen;

void speichern(void) {
   FILE *save = fopen("adressen.dat","r+b");
   if( NULL == save ) {
      save = fopen("adressen.dat","w+b");
      if( NULL == save ) {
         fprintf(stderr,"Kann \"adressen.dat\" nicht öffnen!\n");
         return;
      }
   }
   /* FILE-Zeiger save auf das Ende der Datei setzen */
   fseek(save, 0, SEEK_END);

   /* Wir schreiben eine Adresse ans Ende von "adressen.dat" */
   if(fwrite(&adressen, sizeof(adressen), 1, save) != 1) {
      fprintf(stderr, "Fehler bei fwrite...!!!\n");
      return;
   }
   /* Wir geben unseren FILE-Zeiger wieder frei */
   fclose(save);
}

void ausgabe(void) {
   FILE *output = fopen("adressen.dat","r+b");
   if( NULL == output ) {
      fprintf(stderr,"Kann \"adressen.dat\" nicht öffnen!\n");
      return;
   }
   /* Wir lesen alle Adressen aus "adressen.dat" */
   while(fread(&adressen, sizeof(adressen), 1, output) == 1) {
      printf("Vorname...........: %s",adressen.vorname);
      printf("Nachname..........: %s",adressen.nachname);
      printf("Strasse...........: %s",adressen.strasse);
      printf("Hausnummer........: %s",adressen.hausnummer);
      printf("Postleitzahl......: %s",adressen.plz);
      printf("Ort...............: %s",adressen.ort);
      printf("Sternzeichen......: %s",adressen.sternzeichen);
      printf("Alter.............: %s",adressen.alter);
      printf("\n\n");
   }
   fclose(output);
}

void eingabe(void) {
   printf("Vorname...........:");
   fgets(adressen.vorname, sizeof(adressen.vorname), stdin);
   printf("Nachname..........:");
   fgets(adressen.nachname, sizeof(adressen.nachname),stdin);
   printf("Strasse...........:");
   fgets(adressen.strasse, sizeof(adressen.strasse), stdin);
   printf("Hausnummer........:");
   fgets(adressen.hausnummer,sizeof(adressen.hausnummer),stdin);
   printf("Postleitzahl......:");
   fgets(adressen.plz, sizeof(adressen.plz), stdin);
   printf("Ort...............:");
   fgets(adressen.ort, sizeof(adressen.ort), stdin);
   printf("Sternzeichen......:");
   fgets(adressen.sternzeichen,sizeof(adressen.sternzeichen),
      stdin );
   printf("Alter.............:");
   fgets(adressen.alter, sizeof(adressen.alter), stdin);
   speichern();
}

int main(void) {
   int wahl;

   do {
      printf("Was wollen Sie machen:\n\n");
      printf("-1- Neuen Datensatz hinzufuegen\n");
      printf("-2- Alle Datensaetze ausgeben\n");
      printf("-3- Programm beenden\n\n");
      printf("Ihre Auswahl : ");
      do {
         scanf("%d",&wahl);
      } while(getchar() != '\n');       
      switch(wahl) {
         case 1 : eingabe();        break;
         case 2 : ausgabe();        break;
         case 3 : printf("...Programm wird beendet\n");
                  break;
         default: printf(">>%d<< ???\n",wahl);
      }
   } while(wahl != 3);
   return EXIT_SUCCESS;
}

