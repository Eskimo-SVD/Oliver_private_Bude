/* mister_c1.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __unix__ 
   #define clrscr() printf("\x1B[2J")
#elif __BORLANDC__ && __MSDOS__
   #include <conio.h>
#elif __WIN32__ || _MSC_VER
#define clrscr() system("cls")
#else
   #define clrscr() printf("clrscr() - Fehler!!\n")
#endif

#define HINDERNISSE 100

char spielfeld[15][50];

void createspielfeld(void) {
   int i, j, x, y;
   for(i=0, j=0; j < 50; j++)
      spielfeld[i][j] = '#';

   for(i=1 ;i < 15; i++)
      for(j=0;j<50;j++) {
         if(j==0 || j==49)
            spielfeld[i][j] = '#';
         else
            spielfeld[i][j] = ' ';
         if(i==13 && j==48)
            spielfeld[i][j] = 'O';
      }
      for(i=14,j=0;j<50;j++)
         spielfeld[i][j] = '#';

      for(i=0;i<=HINDERNISSE;i++) {
         x=rand()%14;
         y=rand()%48;
         if(x<15&&y<50 && x>0&&y>0)
            spielfeld[x][y] = '*';
            
      }    
   spielfeld[1][1]=' ';
}

void showspielfeld(void) {
   int i, j;
   clrscr();
   for(i=0; i < 15; i++) 
      for(j=0;j<50;j++) {
         printf("%c",spielfeld[i][j]);
         if(j==49)
            printf("\n");
      }
}

int step(int x, int y, int xalt, int yalt) {
   printf("<ENTER>");  getchar();
   if(spielfeld[x][y] == 'O') { /* sind wir am Ziel? */
      spielfeld[x][y] = 'C';
      spielfeld[xalt][yalt] = ' ';
      showspielfeld();
      printf("Mister C ist zuhause!\n");
      exit (EXIT_SUCCESS);
   }
   else if(spielfeld[x][y] == ' ') {
      spielfeld[x][y] = 'C';
      spielfeld[xalt][yalt] = ' ';
      showspielfeld();
      /* ... nach rechts */
      if( y+1<49 && spielfeld[x][y+1] !='*' &&
          yalt!=y+1 && step(x,y+1,x,y) )
         return 1;
      /* ... nach unten */
      else if( x+1<14 && spielfeld[x+1][y] !='*' &&
               xalt!=x+1 && step(x+1,y,x,y) )
         return 1;
      /* ... nach oben */
      else if( x-1>0 && spielfeld[x-1][y] !='*' &&
               xalt!=x-1 && step(x-1,y,x,y) )
         return 1;
      /* ... nach links */
      else if( y-1>0 && spielfeld[x][y-1] !='*' && 
               yalt!=y-1 && step(x,y-1,x,y) )
         return 1;
   }
 return 0;
}

int main(void) {
   createspielfeld();
   step(1,1,1,1);
   return EXIT_SUCCESS;
}
