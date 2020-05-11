#include <stdio.h>
#include <stdlib.h>

struct knoten{
               int wert;
               struct knoten *links;
               struct knoten *rechts;
             };

typedef struct knoten KNOTEN;
int zahl,hoch=1;
KNOTEN *globale_wurzel;

void suche_ersatz(int *, KNOTEN **);
KNOTEN *einordnen(KNOTEN *);
void loesche(KNOTEN **, int);
void loesche_knoten(KNOTEN **);


KNOTEN *einordnen(KNOTEN *zeiger)
{

 if(zeiger==NULL)
  {
   zeiger=malloc(sizeof(KNOTEN));
   if(zeiger==NULL)
    {
     printf("Konnte keinen Speichplatz reservieren!!!\n");
     exit (0);
    }
   zeiger->wert=zahl;
   zeiger->links=zeiger->rechts=NULL;
   }
 else if(zeiger->wert >= zahl)
           zeiger->links=einordnen(zeiger->links);
 else if(zeiger->wert < zahl)
   zeiger->rechts=einordnen(zeiger->rechts);

 return (zeiger);
}


void zeige_baum(KNOTEN *zeiger)
{
 if(zeiger != NULL)
 {
  zeige_baum(zeiger->rechts);
  printf("<-%d->",zeiger->wert);
  zeige_baum(zeiger->links);

 }
}

void suche(KNOTEN *zeiger,int such)
{
 if(zeiger==NULL)
   printf("%d ist in diesem Baum nicht vorhanden!\n",such);
 else if(zeiger->wert==such)
   printf("Gefunden! %d ist vorhanden!\n",such);
 else if(zeiger->wert >= such)
   suche(zeiger->links,such);
 else if(zeiger->wert<such)
   suche(zeiger->rechts,such);
}



int hoehe(KNOTEN *zeiger)
{
 int hlinks, hrechts;

 if(zeiger==NULL)
   return 0;
 else
  {
   hlinks= hoehe(zeiger->links);
   hrechts=hoehe(zeiger->rechts);
   if(hlinks>hrechts)
     return hlinks+1;
   else
     return hrechts+1;
  }
}

int anz_knoten(KNOTEN *zeiger)
{
 if(zeiger==NULL)
  return 0;
 else
  return anz_knoten(zeiger->links)+anz_knoten(zeiger->rechts)+1;
}

int anz_blatt(KNOTEN *zeiger)
{
 if(zeiger==NULL)
  return 0;
 else if(zeiger->links==NULL && zeiger->rechts==NULL)
  return 1;
 else
  return( anz_blatt(zeiger->links)+anz_blatt(zeiger->rechts) );
}

void loesche(KNOTEN **zeiger, int such)
{
 if((*zeiger) == NULL)
  printf("???????????\n");
 else if((*zeiger)->wert == such) //Gefunden!
  loesche_knoten(zeiger);
 else if((*zeiger)->wert >= such)
  loesche(&((*zeiger)->links),such);
 else
  loesche(&((*zeiger)->rechts),such);
}


void loesche_knoten(KNOTEN **zeiger)
{
 KNOTEN *temp;
 int tempwert;

 if(globale_wurzel==*zeiger)
  {
   printf("Kann die Wurzel nicht löschen!!\n");
   return;
  }

if((*zeiger)!=NULL)
 {
 if((*zeiger)->links==NULL && (*zeiger)->rechts==NULL) //Blatt!
  {
   free(*zeiger);
   *zeiger=NULL;
  }
 else if((*zeiger)->links==NULL) //Nur rechten Nachfolger
  {
   temp = *zeiger;
   *zeiger=(*zeiger)->rechts;
   free(temp);
  }
 else if((*zeiger)->rechts==NULL) //Nur linker Nachfolger
  {
   temp = *zeiger;
   *zeiger=(*zeiger)->links;
   free(temp);
  }
 else  //2 Nachfolger, wir suchen Ersatzelement
  {
   suche_ersatz(&tempwert, &((*zeiger)->rechts));
   (*zeiger)->wert=tempwert;
  }
 }
}

void suche_ersatz(int *neuwert, KNOTEN **zeiger)
{
 KNOTEN *temp;

 if(*zeiger != NULL)
  {
   if((*zeiger)->links==NULL)
    {
     neuwert=(int *)(*zeiger)->wert;
     temp=*zeiger;
     *zeiger=(*zeiger)->rechts;
     free(temp);
    }
   else
    suche_ersatz(neuwert, &((*zeiger)->links));
   }
}
 
 
int main()
{
 KNOTEN *wurzel;
 int such,wahl,anzahl,i;
 wurzel=NULL;
 do
 {
  printf("\tBINAERE BAEUME IN DER PRAXIS\n");
  printf("\t----------------------------\n");
  printf("\n -1- Zahlen hinzufügen\n");
  printf(" -2- Zahl suchen\n");
  printf(" -3- Zahl löschen\n");
  printf(" -4- Hoehe des Baumes ausgeben\n");
  printf(" -5- Anzahl der Knoten ausgeben\n");
  printf(" -6- Blattzahl des Baumes ausgeben\n");
  printf(" -7- Zeige mir die Zahlen\n");
  printf(" -8- Zeige mir die Wurzel\n");
  printf(" -0- PROGRAMMENDE\n\n");
  printf("Ihre Wahl : ");
  scanf("%d",&wahl);

  switch(wahl)
   {
    case 1:  printf("Wieviel Zahlen wollen sie hinzufügen : ");
             scanf("%d",&anzahl);
             for(i=0; i<anzahl; i++)
              {
               printf("\nBitte Zahl eingeben : ");
               scanf("%d",&zahl);
               wurzel=einordnen(wurzel);
               zeige_baum(wurzel);
              }
              break;
    case 2 : printf("Welchen Wert suchen sie : ");
             scanf("%d",&such);
             suche(wurzel,such);
             break;
    case 3 : printf("Welche Zahl wollen sie löschen : ");
             scanf("%d",&such);
             globale_wurzel=wurzel;
             loesche(&wurzel,such);
             break;
    case 4 : printf("\nHoehe des Baumes     = %d\n",hoehe(wurzel));
             break;
    case 5 : printf("Anzahl der Knoten    = %d\n",anz_knoten(wurzel));
             break;
    case 6 : printf("Blattzahl des Baumes = %d\n",anz_blatt(wurzel));
             break;
    case 7 : zeige_baum(wurzel);
             break;
    case 8 : if(wurzel!=NULL)
               printf("Wurzel = %d\n\n",wurzel->wert);
             else
               printf("Der Baum ist noch leer!!\n");
             break;
    default: break;
   }
   printf("\n");
  }while(wahl != 0);
 return 0;
}



