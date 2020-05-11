/* bubblesort.c */
#include <stdio.h>
#include <stdlib.h>
/* 100000 Elemente */
#define MAX 100000

/* Ein Array von großen zu kleinen Werten */
int test_array1[MAX]; 
int test_array2[MAX]; 

/* In umgekehrter Reihenfolge erstellen */
void init_test_array(int *array) {
   int i, j; 
   for(i = MAX,j=0; i >= 0; i--,j++)
      array[j] = i; 
}

static void *bubble1(void* val) {
   int i, temp, elemente=MAX; 
   while(elemente--)
      for(i = 1; i <= elemente; i++)
         if(test_array1[i-1] > test_array1[i]) {
            temp=test_array1[i]; 
            test_array1[i]=test_array1[i-1]; 
            test_array1[i-1]=temp; 
         }
}

static void *bubble2(void* val) {
   int i, temp, elemente=MAX; 
   while(elemente--)
      for(i = 1; i <= elemente; i++)
         if(test_array2[i-1] > test_array2[i]) {
            temp=test_array2[i]; 
            test_array2[i]=test_array2[i-1]; 
            test_array2[i-1]=temp; 
         }
}

int main (void) {
   int i, j; 
   init_test_array(test_array1); 
   init_test_array(test_array2); 

   bubble1(NULL); 
   bubble2(NULL); 

   /* Ausgabe in eine Textdatei */
   freopen("myoutput.txt", "w+", stdout); 

   for(i = 0; i < MAX; i++)
      printf("[%d-%d]", test_array1[i], test_array2[i]); 
   return EXIT_SUCCESS; 
}
