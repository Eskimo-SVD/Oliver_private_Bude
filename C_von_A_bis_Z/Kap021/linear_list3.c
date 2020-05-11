#include <stdio.h>
#include <string.h>   /* strcpy,strcmp */
#include <stdlib.h>   /* malloc,exit,free */
#define MAX 20

struct datum{
				 int tag;
				 int monat;
				 int jahr;
				};

struct angestellt{
						char name[MAX];
						char vorname[MAX];
						struct datum alter;
						struct datum eingest;
						long gehalt;
						struct angestellt *next;
					  };

struct angestellt *next = NULL;
struct angestellt *anfang=NULL;

/*Prototypen der Funktionen*/
void anhaengen(char *,char *,int,int,int,int,int,int,long);
void loesche(char *);
void ausgabe(void);
void eingabe(void);
void loesche_alles(void);
void sortiert_eingeben(char *,char *,int,int,int,int,int,int,long);


/*Wir hängen einen Datensatz an oder geben eine neuen ein
  n=name,v=vornam,at=alter.tage,am=alter.monat,aj=alter.jahr
  eint=eigestellt tag,einm=eingestellt monat,einj=eingest. jahr
  g=gehalt*/

void anhaengen(char n[],char v[],int at,int am,int aj,
					int eint,int einm,int einj,long g)
{
   /*Zeiger zum Zugriff auf die einzelnen Elemente der Struktur*/
   struct angestellt *zeiger;

   /*Wir fragen ab ob es schon ein Element in der List gibt.
     Wir suchen das Element auf dem unser Zeiger *anfang zeigt.
     Falls *anfang immer noch auf NULL zeigt bekommt *anfang 
     die Adresse unseres 1.Elementes und ist somit der Kopf
     (Anfang) unserer Liste*/
   if(anfang == NULL)
      {
	     /* Wir reservieren Speicherplatzt für unser Struktur
            für das erste Element der Liste*/
	     if((anfang = malloc(sizeof(struct angestellt))) == NULL)
	        fprintf(stderr,"Kein Speicherplatzt vorhanden"
                           " für anfang\n");
	     strcpy(anfang->name,strtok(n, "\n"));
	     strcpy(anfang->vorname,strtok(v, "\n"));
	     anfang->alter.tag=at;
	     anfang->alter.monat=am;
	     anfang->alter.jahr=aj;
         anfang->eingest.tag=eint;
	     anfang->eingest.monat=einm;
	     anfang->eingest.jahr=einj;
	     anfang->gehalt=g;

   /*Somit haben wir unseren Anfang der Liste. Von nun an zeigt
     der Zeiger anfang immer auf das Element vor ihm. Da dies
     aber jetzt das 1.Element der Liste war zeigt der Zeiger
     anfang auf den Zeiger next. next zeigt am Ende immer 
     wieder NULL*/
         anfang->next=NULL;
      }

/*Es scheint schon mindestens 1.Element in der Liste vorhanden
  zu sein da der Anfang nicht == NULL ist. Jetzt suchen wir
  so lange nach dem nächsten Element bis der *next - Zeiger
  auf NULL zeigt. Somit haben wir das Ende der Liste gefunden
  und können einen neuen Datensatz anhängen*/
   else
      {
	     zeiger=anfang; /* Wir zeigen auf das 1.Element */
	     while(zeiger->next != NULL)
	        zeiger=zeiger->next;

  /*Wir reservieren einen Speicherplatz für das letzte Element
    der Liste und hängen es an.*/
         if((zeiger->next =
                      malloc(sizeof(struct angestellt))) == NULL)
	         fprintf(stderr,"Kein Speicherplatz für letztes Element\n");

         zeiger=zeiger->next; /* zeiger auf neuen Speicherplatz */
         strcpy(zeiger->name,strtok(n, "\n"));
         strcpy(zeiger->vorname,strtok(v, "\n"));
         zeiger->alter.tag=at;
         zeiger->alter.monat=am;
         zeiger->alter.jahr=aj;
         zeiger->eingest.tag=eint;
         zeiger->eingest.monat=einm;
         zeiger->eingest.jahr=einj;
         zeiger->gehalt=g;
         zeiger->next=NULL; /* Wir terminieren wieder unsere Datenstruktur */
      }
}

/*Funktion zum löschen einer Datei*/
void loesche(char wen[])
{
   struct angestellt *zeiger ,*zeiger1;

  /*Ist überhaupt ein Element vorhanden?*/
  if(anfang != NULL)
     {
       /*Ist unser 1.Element das von uns gesuchte (wen[]) ?*/
       if(strcmp(anfang->name,wen) == 0)
	      {
	         zeiger=anfang->next;
	         free(anfang);
	         anfang=zeiger;
	      }
       else
	      {
	        /*Es ist nicht das 1.Element zu löschen. Wir suchen in
	          der weiteren Kette ob das zu löschende Element vor-
	          handen ist*/
	         zeiger=anfang;
	         while(zeiger->next != NULL)
	            {
	               zeiger1=zeiger->next;
	               /*Ist die Adresse von zeiger1 der gesuchte Namen?*/
	               if(strcmp(zeiger1->name,wen) == 0)
		              {
		                 /*Falls ja dann.....*/
		                 zeiger->next=zeiger1->next;
		                 free(zeiger1);
		                 break;
		              }
	               zeiger=zeiger1;
	            }/* Ende while */
	      }/* Ende else */
      }/* Ende if(anfang != NULL) */
   else
      printf("Es sind keine Daten zum löschen vorhanden!!!\n");
}

/*Funktion zum Ausgeben der Dateien*/
void ausgabe()
{
   struct angestellt *zeiger;
   zeiger=anfang;

   printf("||====================================="
          "==================||\n");
   printf("|%10cName%10c |Geburtsdatum|"
   "Eingestellt|Gehalt|\n",' ',' ');
   printf("||====================================="
   "==================||\n");

   while(zeiger != NULL)
      {
         printf("|%12s,%-12s| %02d.%02d.%04d|"
                "%02d.%02d.%04d|%06ld|\n",
               zeiger->name,zeiger->vorname,zeiger->alter.tag,
               zeiger->alter.monat,zeiger->alter.jahr,
               zeiger->eingest.tag,zeiger->eingest.monat,
               zeiger->eingest.jahr,zeiger->gehalt);
         printf("|-----------------------------------"
                "----------------------|\n");
         zeiger=zeiger->next;
      }
}


/* Funktion zur Eingabe der Daten */
void eingabe(void) {
   char nam[MAX],vorn[MAX];
   int atag,amon,ajahr,eintag,einmon,einjahr;
   long gehalt;
   char *ptr;
   printf("Name........................: ");
   fgets(nam, MAX, stdin);
   ptr = strrchr(nam, '\n');
   *ptr = '\0';
   printf("Vorname.....................: ");
   fgets(vorn, MAX, stdin);
   ptr = strrchr(vorn, '\n');
   *ptr = '\0';
   printf("Alter...........(tt.mm.jjjj): ");
   scanf("%2d.%2d.%4d",&atag,&amon,&ajahr);
   printf("Eingestellt am..(tt.mm.jjjj): ");
   scanf("%2d.%2d.%4d",&eintag,&einmon,&einjahr);
   printf("Monatsgehalt................: ");
   scanf("%ld",&gehalt);
   getchar();
   anhaengen(nam, vorn, atag, amon, ajahr, eintag,
      einmon, einjahr, gehalt);
}

void loesche_alles()
{
   struct angestellt *zeiger, *zeiger1;

   /*Ist überhaupt eine Liste zum löschen vorhanden*/
   if(anfang != NULL)
      {
	     /*Es ist eine vorhanden....*/
	     zeiger=anfang->next;
	     while(zeiger != NULL)
	        {
	           zeiger1=anfang->next->next;
	           anfang->next=zeiger1;
	           free(zeiger);
	           zeiger=zeiger1;
	        }
	     /*Jetzt löschen wir erst den Anfang der Liste*/
	     free(anfang->next);
	     free(anfang);
	     anfang=NULL;
         printf("Liste erfolgreich gelöscht!!\n");
      }
   else
      fprintf(stderr,"Keine Liste zum löschen vorhanden!!\n");
}

void sortiert_eingeben(char n[],char v[],int at,int am,int aj,
                       int et,int em,int ej,long geh)
{
   struct angestellt *zeiger, *zeiger1;

   /*Ist es das 1.Element der Liste ? */
   if(anfang==NULL)
	  anhaengen(n,v,at,am,aj,et,em,ej,geh);
   /*Es ist nicht das 1.Element. Wir suchen nun so lange bis das
	 gesuchte Element gefunden wird oder wir auf NULL stossen*/
   else
      {
	     zeiger=anfang;
	     while(zeiger != NULL && (strcmp(zeiger->name,n)<0))
	     zeiger=zeiger->next;
	     /*Falls der Zeiger auf NULL zeigt können wir unser 
           Element hinten anhängen da unser neues Element das 
           "grösste" zu sein scheint */
	     if(zeiger==NULL)
	        anhaengen(n,v,at,am,aj,et,em,ej,geh);
	     /*Ist unser neues Element das kleinste und somit 
           kleiner als das 1.Element so müssen wir es an 
           den Anfang hängen */
	     else if(zeiger==anfang)
	        {
	           anfang = malloc(sizeof(struct angestellt));
	           if(NULL == anfang)
	              {
	                 fprintf(stderr, "Keine Speicher\n");
	                 return;
                  }
	           strcpy(anfang->name,strtok(n, "\n"));
	           strcpy(anfang->vorname,strtok(v, "\n"));
	           anfang->alter.tag=at;
	           anfang->alter.monat=am;
	           anfang->alter.jahr=aj;
	           anfang->eingest.tag=et;
	           anfang->eingest.monat=em;
	           anfang->eingest.jahr=ej;
               anfang->gehalt=geh;
	           anfang->next=zeiger;
	        }
	      /*Die letzt Möglichkeit ist das wir das Element
            irgendwo in der Mitte einfügen müssen*/
	     else
	        {
	           zeiger1=anfang;
	           /*Wir suchen das Element das vor dem 
                 Zeiger zeiger steht*/
	           while(zeiger1->next != zeiger)
		          zeiger1=zeiger1->next;
	           zeiger = malloc(sizeof(struct angestellt));
	           if(NULL == zeiger)
	              {
	                 fprintf(stderr, "Kein Speicher");
	                 return;
                  }
	           strcpy(zeiger->name,strtok(n, "\n"));
	           strcpy(zeiger->vorname,strtok(v, "\n"));
	           zeiger->alter.tag=at;
	           zeiger->alter.monat=am;
	           zeiger->alter.jahr=aj;
	           zeiger->eingest.tag=et;
	           zeiger->eingest.monat=em;
	           zeiger->eingest.jahr=ej;
	           zeiger->gehalt=geh;
	            /*Wir fügen das neue Element ein*/
	           zeiger->next=zeiger1->next;
	           zeiger1->next=zeiger;
	        }/* Ende else */
      }/* Ende else */
}


int main()
{
 int wahl;
 char dname[MAX];

 do{
	 printf("1 : Eingabe\n");
	 printf("2 : Ausgabe\n");
	 printf("3 : Namen löschen\n");
	 printf("4 : Alles löschen\n");

	 printf("9 : Ende\n");
	 printf("Ihre Wahl : ");
	 scanf("%d",&wahl);
	 getchar();
	 switch(wahl)
	   {
		  case 1 : eingabe();
		     	   break;
		  case 2 : ausgabe();
		   	 	   break;
		  case 3 : printf("Welchen Namen wollen sie löschen : ");
				   fgets(dname, MAX, stdin);
				   loesche(strtok(dname, "\n"));
				   break;
		  case 4 : loesche_alles();
                   break;
		  case 9 : break;
		  default: printf("Falsche Eingabe!!!\n");
	  }
	 }while(wahl != 9);

 return 0;
}


