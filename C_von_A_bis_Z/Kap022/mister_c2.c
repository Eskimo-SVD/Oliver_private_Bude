/* mister_c2.c */
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

#define HINDERNISSE 200

char spielfeld[15][50];
/* 1=besucht,0=nicht besucht */
int besucht[15][50]; 

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
   spielfeld[1][1] = ' ';
   
   for(i=0; i<15; i++)
      for(j=0; j<50; j++)
	     besucht[i][j] = 0;
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
   printf("<ENTER>");
   getchar();

   if(spielfeld[x][y] == 'O') { /* sind wir am Ziel? */
      spielfeld[x][y] = 'C';
      spielfeld[xalt][yalt] = ' ';
      showspielfeld();
      printf("Mister 'C' ist zuhause!\n");
      exit (EXIT_SUCCESS);
   }
   else if(spielfeld[x][y] == ' ') {
      besucht[x][y] = 1;
      spielfeld[x][y]='C';
      spielfeld[xalt][yalt]=' ';
      showspielfeld();
      /* rechts */
      if( y+1<49 && spielfeld[x][y+1] !='*' &&
          yalt!=y+1 &&besucht[x][y+1]!=1 && 
          step(x,y+1,x,y))   
         return 1;
      /* rechts unten */   
      else if( y+1<49 && x+1<14 && spielfeld[x+1][y+1] !='*'
               && xalt!=x+1 && yalt!=y+1 && besucht[x+1][y+1]!=1
               && step(x+1,y+1,x,y))
         return 1;
      /* rechts oben */  
      else if( x-1>0 && y+1<49 && spielfeld[x-1][y+1]!='*'
              && xalt!=x-1 && yalt!=y+1 && besucht[x-1][y+1]!=1
              && step(x-1,y+1,x,y) )
         return 1;
      /* nach unten */   
      else if( x+1<14 && spielfeld[x+1][y] !='*'
               && xalt!=x+1 && besucht[x+1][y]!=1 
               && step(x+1,y,x,y) )
         return 1;
      /* links unten */   
      else if( x+1<14 && y-1>0 && spielfeld[x+1][y-1]!='*'
               && xalt!=x+1 && yalt!=y-1 && besucht[x+1][y-1]!=1
               && step(x+1,y-1,x,y) )
         return 1;
      /* nach oben */  
      else if( x-1>0 && spielfeld[x-1][y] !='*'
               && xalt!=x-1 && besucht[x-1][y]!=1 
               && step(x-1,y,x,y) )
         return 1;
      /* nach links */   
      else if( y-1>0 && spielfeld[x][y-1] !='*'
               && yalt!=y-1 && besucht[x][y-1]!=1 
               && step(x,y-1,x,y) )
         return 1;
      /* links oben */ 
      else if( x-1>0 && y-1>0 && spielfeld[x-1][y-1] !='*'
               && xalt!=x-1 && yalt!=y-1 && besucht[x-1][y-1]!=1
               && step(x-1,y-1,x,y) )
         return 1;
   }
   spielfeld[x][y]=' ';
   return 0;
}


int main(void) {
   createspielfeld();
   step(1,1,1,1);
   return EXIT_SUCCESS;
}
