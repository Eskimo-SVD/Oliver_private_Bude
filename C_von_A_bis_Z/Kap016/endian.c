/* endian.c */
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int  WORD;
typedef unsigned char BYTE;

int main(void) {
   /* Word in den Speicher schreiben */
   WORD Word = 0x22CCDDEE;
   /* Zeiger auf ein Byte  */
   BYTE *Byte;

   /* Word-Zeiger auf Byte-Zeiger casten */
   Byte = (BYTE *) &Word;

/* Speicherinhalt nach Adressen von links nach rechts 
 * ausgeben. 
 * byte[0]byte[1]byte[2]byte[3]
 * 22     CC     DD     EE       Speicherinhalt bei Little-Endian
 * EE     DD     CC     22       Speicherinhalt bei Big-Endian
 */
   /* Ist Byte[0] == 11 */
   if(Byte[0] == ((Word >>  0) & 0xFF))
      printf("Little-Endian Architecture\n");
   /* oder ist Byte[0] == CC */
   if(Byte[0] == ((Word >> 24) & 0xFF))
      printf("Big-Endian Architecture\n");
   return EXIT_SUCCESS;
}

