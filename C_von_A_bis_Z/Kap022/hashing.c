/* hashing.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_HASH 10
#define M 31

struct plz{
   char ort[255];
   unsigned int postleit;
   struct plz *next;
};

struct plz *hash_tabelle[MAX_HASH];

struct plz *insert(char *, unsigned int);
void search_in_hash(char *);
int hash_funktion(char *);

struct plz *insert(char *o, unsigned int p) {
   struct plz *pointer;
   /* Hashwert (bucket) an hash_adresse (0-9) */
   int hash_adresse = hash_funktion(o);

   /* printf("%d\n",hash_adresse); */

   /* Zeiger auf errechnete Tabellenadresse
    * durch hash_funktion    */
   pointer = hash_tabelle[hash_adresse];
   /* Wir suchen freien Platz für einen neuen Eintrag 
    * in hash_tabelle[hash_adresse]   */
   while(pointer != NULL) {
      if(strcmp(o, pointer->ort) == 0)  /* Stadt gleich? */
         if(pointer->postleit == p) {   
            /* Postleitzahlen gleich? */
            printf("%s mit PLZ %d ist bereits vorhanden\n",o,p);
            /* Doppelte Einträge vermeiden */
            return pointer;
         }
         pointer=pointer->next;
   }
   /* Speicher für neues Element allokieren */
   pointer = malloc(sizeof(struct plz));
   if(pointer == NULL) {
      printf("Kein Speicher für neue PLZ vorhanden\n");
      return NULL;
   }
   strcpy(pointer->ort, o);
   pointer->postleit = p;
   pointer->next = hash_tabelle[hash_adresse];
   hash_tabelle[hash_adresse] = pointer;
   return pointer;
}

/* Funktion zur Suche in der Hash-Tabelle */
void search_in_hash(char *o) {
   struct plz *pointer;
  /* Hashwert (bucket) an hash_adresse (0-9) */
   int hash_adresse = hash_funktion(o);

   /* printf("%d\n",hash_adresse); */

   /* Zeiger auf errechnete Tabellenadresse
    * durch hash_funktion   */
   pointer = hash_tabelle[hash_adresse];

   /* Jetzt wollen wir nachsehen, ob es für o einen 
    *  Eintrag in der Tabelle gibt   */
   while(pointer != NULL) {
      if(strcmp(pointer->ort, o) == 0)
         printf("PLZ für %s ist %d\n",o,pointer->postleit);
      pointer = pointer->next;
   }
}

/* Die Hash-Funktion zur Berechnung des Hashwerts 
 * eines Strings    */
int hash_funktion(char *string) {
   unsigned int hash_adresse;
   unsigned char *pointer;

   hash_adresse = 0;
   pointer = (unsigned char *)string;
   while(*pointer != '\0') {
      hash_adresse = M * hash_adresse + *pointer;
      pointer++;
   }
   return hash_adresse % MAX_HASH;
}

int main(void) {
   /* Einfügen */
   insert("Friedberg", 86316);
   insert("Augsburg", 86136);
   insert("Stuttgart", 71345);
   /* Suchen */
   search_in_hash("Augsburg");
   search_in_hash("Friedberg");
   search_in_hash("Stuttgart");
   return EXIT_SUCCESS;
}

