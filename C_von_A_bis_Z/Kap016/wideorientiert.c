/* wideorientiert.c */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main() {
   FILE *fp;
   int ret;
   wchar_t wStr[] = L"Ein einfaches Beispiel für Breitzeichen";
   
   fp = fopen("testfile.txt", "w+");
   if( NULL == fp ) {
      printf("Konnte Datei nicht öffnen\n");
      exit(EXIT_FAILURE);
   }
   // wide-orientiert setzen = 1
   ret = fwide( fp, 1 );
   if( ret <= 0 ) {
      fprintf(stderr, "Konnte nicht auf Breitzeichen umstellen\n");
      exit(EXIT_FAILURE);
   }
   // Die Breitzeichen schreiben
   fputws( wStr, fp );

   return EXIT_SUCCESS;
}
