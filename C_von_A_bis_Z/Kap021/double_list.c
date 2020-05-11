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
						struct angestellt *next;   /* Nachfolger */
						struct angestellt *previous;  /* Vorgänger */
					  };


/*Globale Variablen*/
struct angestellt *next, *anfang, *ende;
static int counter=0;
static char datname[] = "personal.dat";


/*Prototypen der Funktionen*/
void start(void);
void anhaengen(char *,char *,int,int,int,int,int,int,long);
void loesche(char *);
void ausgabe(void);
void eingabe(void);
void loesche_alles(void);
void sortiert_eingeben(char *,char *,int,int,int,int,int,int,long);
int vergleiche(struct angestellt *, struct angestellt *);
int laden(FILE *);
void speichern(FILE *);
int datei_oeffnen_lesen(FILE **);
int datei_oeffnen_erstellen(FILE **);
int datei_oeffnen_lesen_schreiben(FILE **);


/*Startadressen für die Zeiger next,anfang und ende*/
void start(void)
{
 next=anfang=ende=NULL;
}

/*Wir hängen einen Datensatz an oder geben eine neuen ein
  n=name,v=vornam,at=alter.tage,am=alter.monat,aj=alter.jahr
  eint=eigestellt tag,einm=eingestellt monat,einj=eingest. jahr
  g=gehalt*/
void anhaengen(char n[],char v[],int at,int am,int aj,
					int eint,int einm,int einj,long g)
{
/*Zeiger zum Zugriff auf die einzelnen Elemente der Struktur*/
 struct angestellt *zeiger, *zeiger1;
 
    /* Wurde schon Speicher für den ende-Zeiger bereitgestellt */
   if(ende == NULL)
      {
         if((ende = malloc(sizeof(struct angestellt))) == NULL)
            {
	           printf("Konnte keinen Speicherplatz für ende reservieren\n");
	           exit(0);
		    }
      }

/*Wir fragen ab ob es schon ein Element in der List gibt. Wir
  suchen das Element auf dem unser Zeiger *anfang zeigt.
  Falls *anfang immer noch auf NULL zeigt bekommt *anfang die
  Adresse unseres 1.Elementes und ist somit der Kopf (Anfang)
  unserer Liste*/
 if(anfang == NULL)
  {
	/*Wir reservieren Speicherplatzt für unser Struktur für das
	  erste Element der Liste*/
	if((anfang = malloc(sizeof(struct angestellt))) == NULL)
	  fprintf(stderr,"Kein Speicherplatz vorhanden für anfang\n");
	counter++;
	strcpy(anfang->name,strtok(n, "\n"));
	strcpy(anfang->vorname,strtok(v, "\n") );
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
  anfang auf den Zeiger next. next zeigt am Ende immer wieder
  NULL. Da es das erste Element der Liste ist zeigt somit auf
  das Ende auf das selbe Element wie anfang. Und das Element vor dem
  1. Element ist somit NULL*/
  anfang->next=NULL;
  ende=anfang;
  ende->previous=NULL;
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
  if((zeiger->next = malloc(sizeof(struct angestellt))) == NULL)
	 fprintf(stderr,"Kein Speicherplatz für letztes Element\n");

  zeiger1=zeiger;
  zeiger=zeiger->next; /* zeiger auf neuen Speicherplatz */
  counter++;
  strcpy(zeiger->name, strtok(n, "\n") );
  strcpy(zeiger->vorname,strtok(v, "\n") );
  zeiger->alter.tag=at;
  zeiger->alter.monat=am;
  zeiger->alter.jahr=aj;
  zeiger->eingest.tag=eint;
  zeiger->eingest.monat=einm;
  zeiger->eingest.jahr=einj;
  zeiger->gehalt=g;
  zeiger->next=NULL;
  ende=zeiger;
  zeiger->previous=zeiger1;
  zeiger1->next=zeiger;
 }
}



/*Funktion zum löschen einer Datei*/
void loesche(char wen[])
{
 struct angestellt *zeiger ,*zeiger1, *zeiger2;

/*Ist überhaupt ein Element vorhanden?*/
 if(anfang != NULL)
 {
  /*Ist unser 1.Element das von uns gesuchte (wen[]) ?*/
  if(strcmp(anfang->name,wen) == 0)
	{
	 zeiger=anfang->next;
	 if(zeiger == NULL)
	  {
		free(anfang);
		anfang=NULL;
		ende=NULL;
		counter--;
		return;
	  }
	 zeiger->previous=NULL;
	 free(anfang);
	 counter--;
	 anfang=zeiger;
	}
  /*Ist das letzte Element das von uns gesuchte ? */
  else if(strcmp(ende->name,wen) == 0)
	{
	 zeiger=ende->previous;
	 zeiger->next=NULL;
	 zeiger1=ende;
	 ende=zeiger;
	 free(zeiger1);
	 counter--;
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
		 zeiger2=zeiger1->next;
		 zeiger2->previous=zeiger;
		 free(zeiger1);
		 counter--;
		 break;
		}
	  zeiger=zeiger1;
	 }/* Ende while */
	}/* Ende else */
  }/* Ende if(anfang != NULL) */
 else
  {
	printf("Es sind keine Daten zum löschen vorhanden!!!\n");
  }
}



/*Funktion zum Ausgeben der Dateien*/
void ausgabe()
{
 struct angestellt *zeiger;

 zeiger=anfang;

 printf("||=======================================================||\n");
 printf("|%10cName%10c |Geburtsdatum|Eingestellt|Gehalt|\n",' ',' ');
 printf("||=======================================================||\n");

 while(zeiger != NULL)
  {
	printf("|%12s,%-12s|  %02d.%02d.%04d| %02d.%02d.%04d|%06ld|\n",
	zeiger->name,zeiger->vorname,zeiger->alter.tag,
	zeiger->alter.monat,zeiger->alter.jahr,zeiger->eingest.tag,
	zeiger->eingest.monat,zeiger->eingest.jahr,zeiger->gehalt);
	printf("|---------------------------------------------------------|\n");

	zeiger=zeiger->next;
  }
 printf("\n\nWeiter mit <ENTER>\n");
 getchar();
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
   sortiert_eingeben(nam, vorn, atag, amon, ajahr, eintag,
      einmon, einjahr, gehalt);
}



/*Funktion zum löschen der gesamten Liste*/
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
	  if(zeiger1 == NULL)
		 break;
	  anfang->next=zeiger1;
	  zeiger1->previous=anfang;
	  free(zeiger);
	  zeiger=zeiger1;
	 }
	/*Jetzt löschen wir erst den Anfang der Liste und das Ende der Liste*/
	free(anfang);
	free(ende);
	anfang=NULL;
	ende=NULL;
	counter=0;
	printf("Liste erfolgreich gelöscht!!\n");
  }
 else
  fprintf(stderr,"Keine Liste zum löschen vorhanden!!\n");
}




void sortiert_eingeben(char n[],char v[],int at,int am,int aj,
					   int et,int em,int ej,long geh)
{
 struct angestellt *zeiger, *zeiger1, *zeiger2;

  zeiger2=malloc(sizeof(struct angestellt));
  if(NULL == zeiger2)
     {
        fprintf(stderr, "Kein Speicher vorhanden\n");
        return;
     }
  strcpy(zeiger2->name,strtok(n, "\n"));
  strcpy(zeiger2->vorname,strtok(v, "\n"));
  zeiger2->alter.tag=at;
  zeiger2->alter.monat=am;
  zeiger2->alter.jahr=aj;
  zeiger2->eingest.tag=et;
  zeiger2->eingest.monat=em;
  zeiger2->eingest.jahr=ej;
  zeiger2->gehalt=geh;

 /*Ist es das 1.Element der Liste ? */
 if(anfang==NULL)
	anhaengen(n,v,at,am,aj,et,em,ej,geh);
 /*Es ist nicht das 1.Element. Wir suchen nun so lange bis das
	gesuchte Element gefunden wird oder wir auf NULL stossen*/
 else
  {
	zeiger=anfang;
	while(zeiger != NULL && (vergleiche(zeiger,zeiger2)<0))
	  zeiger=zeiger->next;

		/*Falls der Zeiger auf NULL zeigt können wir unser Element hinten
	  anhängen da unser neues Element das "grösste" zu sein scheint */
	if(zeiger==NULL)
	  anhaengen(n,v,at,am,aj,et,em,ej,geh);
	/*Ist unser neues Element das kleinste und somit kleiner als das
	  1.Element so müssen wir es an den Anfang hängen */
	else if(zeiger==anfang && (vergleiche(zeiger,zeiger2)))
	 {
	  anfang=malloc(sizeof(struct angestellt));
	  if(NULL == anfang)
	     {
	        fprintf(stderr, "Kein Speicher vorhanden\n");
	        return;
         }
	  counter++;
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
	  anfang->previous=NULL;
	 }
	/*Die letzt Möglichkeit ist das wir das Element irgendwo in der Mitte
	  einfügen müssen*/
	else if(vergleiche(zeiger, zeiger2))
	 {
	  zeiger1=anfang;
	  /*Wir suchen das Element das vor dem Zeiger zeiger steht*/
	  while(zeiger1->next != zeiger)
		 zeiger1=zeiger1->next;
	  zeiger=malloc(sizeof(struct angestellt));
	  if(NULL == zeiger)
	     {
	        fprintf(stderr, "Kein Speicherplatz vorhanden\n");
	        return;
	     }   
	  counter++;
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
	  zeiger->previous=zeiger1;
	  zeiger1->next=zeiger;
      zeiger1->next->previous=zeiger;
	 }/* Ende else */
   else
	 {
	  printf("Name wurde nicht eingefügt!!! (Weiter mit <ENTER>");
	  getchar();
	 }
	}/* Ende else if */
}



/*Funktion zum Vergleichen von Nachname und bei Gleichheit
  Vorname. Somit wird bei gleichem Nachnamen nach dem Anfangs-
  buchstaben des Vornamen sortiert.*/
int vergleiche(struct angestellt *n1, struct angestellt *n2)
{
 int z = strcmp(n1->name,n2->name);

 /*Falls z eine Wert ungleich 0 hat gibt es den Namen noch nicht.
	Somit können wir den Wert zurückgeben an die Funktion den wir
	durch strcmp erhalten haben.*/
 if(z)
	return z;
 /*Wenn diese ausgeführt wird, so existiert dieser Name schon einmal.
	Somit vergleichen wir die Vornamen*/
 return(strcmp(n1->vorname,n2->vorname));
}


/*Die gesamte Liste in der Datei "personal.dat" speichern */
void speichern(FILE *datei)
{
 struct angestellt *zeiger;

 /*Im "w+" - Modus oeffnen*/
 if(datei_oeffnen_lesen_schreiben(&datei))
 {
  zeiger=anfang;
  while(zeiger != NULL)
  {
	fwrite(zeiger,sizeof(struct angestellt),1,datei);
	zeiger=zeiger->next;
  }
 }
 fclose(datei);
}

/*Beim start des Programmes alle Elemente aus der Datei "personal.dat"
  laden. Laden ist nicht ganz richtig. Wir lesen zuerst die einzelnen
  Element aus der Datei "personal.dat" und übergeben jedes einzelne
  Element an die Funktion sortiert_eingeben.*/
int laden(FILE *datei)
{
 struct angestellt zeiger;
 if(datei_oeffnen_lesen(&datei))
  {
	while(fread(&zeiger,sizeof(struct angestellt),1,datei))
	{
	 sortiert_eingeben(zeiger.name,zeiger.vorname,zeiger.alter.tag,
	 zeiger.alter.monat,zeiger.alter.jahr,zeiger.eingest.tag,
	 zeiger.eingest.monat,zeiger.eingest.jahr,zeiger.gehalt);
	}
  return 1;
  }
 return 0;
}

/*Funktion zu oeffnen einer Datei im nur-lese-Modus "r" */
int datei_oeffnen_lesen(FILE **datei)
{
 if((*datei = fopen(datname,"r")) == NULL)
  {
	fprintf(stderr,"Konnte \"personal.dat\" nicht oeffnen!\n");
	printf("<ENTER>"); getchar();
	return 0;
  }
 return 1;
}

/*Falls Datei "personal.dat" noch nicht exisitiert wird diese
  erzeugt */
int datei_oeffnen_erstellen(FILE **datei)
{
 if((*datei = fopen(datname,"w+")) == NULL)
  {
	fprintf(stderr,"Konnte \"personal.dat\" nicht erstellen\n");
	return 0;
  }
 return 1;
}


/*Datei zum lesen und schreiben oeffnen. Der Inhalt der Datei wird
  dabei überschrieben*/
int datei_oeffnen_lesen_schreiben(FILE **datei)
{
 if((*datei = fopen(datname,"w+")) == NULL)
  {
	fprintf(stderr,"Kann \"personal.dat\" nicht zum beschreiben oeffnen!\n");
	printf("<ENTER>"); getchar();
	return 0;
  }
 return 1;
}


int main()
{
 int wahl;
 char dname[MAX];
 FILE *datei;

/* personal.dat laden falls vorhanden */
 if(laden(datei))
     ;
/* ... nicht vorhanden, dann erstellen */
 else if( datei_oeffnen_erstellen(&datei) )
  {
	start();
	printf("\"personal.dat\" neu erstellt\n");
	printf("<ENTER>"); getchar();
	fclose(datei);
  }
 else
  {
	fprintf(stderr,"Konnte \"personal.dat\" weder erstellen noch finden\n");
	exit (0);
  }

 do{
	 
	 printf("Personaldaten - Verwaltung\n");
	 printf("==========================\n");
	 printf("1 : Eingabe\n");
	 printf("2 : Ausgabe\n");
	 printf("3 : Namen löschen\n");
	 printf("4 : Alles löschen\n");
	 printf("5 : Speichern\n");
	 printf("0 : Ende\n");
	 printf("Sie haben %d Leute an Personal\n",counter);
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
				 fgets(dname,MAX,stdin);
				 loesche( strtok(dname, "\n") );
				 break;
		case 4 : loesche_alles();
				 break;
		case 5 : speichern(datei);
				 break;
		case 0 : break;
		default: printf("Falsche Eingabe!!!\n");
	  }
	 }while(wahl != 0);
 return 0;
}


