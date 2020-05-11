/* fibo.c */
#include <stdio.h>
#include <stdlib.h>

long fibo(long n) {
   if(n)
      return (n <= 2) ? n : fibo(n-2) + fibo(n-1);
	return 0;
}

int main(void) {
   long f;
   long i=0;

   printf("Wie viele Fibonacci-Zahlen wollen Sie ausgeben:");
   scanf("%ld",&f);
   while(i++ < f)
      printf("F(%ld) = %ld\n", i, fibo(i));
   return EXIT_SUCCESS;
}

