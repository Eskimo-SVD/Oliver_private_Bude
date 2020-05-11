/* playing_bits.c */
#include <stdio.h>
#define BYTE unsigned char

/* Funktion : Bit_Test()
 * val  : der Wert, den es zu testen gilt
 * bit  : Bitnummer, die abgefragt wird, ob gesetzt (0-7)
 * R�ckgabewert :  (1)=Bit gesetzt; (0)=Bit nicht gesetzt
 */

int Bit_Test(BYTE val, BYTE bit) {
   BYTE test_val = 0x01;    /* dezimal 1 / bin�r 0000 0001 */
   /* Bit an entsprechende Pos. schieben */
   test_val = (test_val << bit);
   /* 0=Bit nicht gesetzt; 1=Bit gesetzt */
   if ((val & test_val) == 0)
      return 0;      /* Nicht gesetzt */ 
   else
      return 1;      /* gesetzt */ 
}

/* Funktion :  Bit_Set()
 * val  : Wert, bei dem Bit gesetzt werden soll
 * bit  : Bitnummer, die gesetzt werden soll (0-7)
 * R�ckgabewert : keiner
 */

void Bit_Set(BYTE *val, BYTE bit) {
   BYTE test_val = 0x01;      /* dezimal 1 / bin�r 0000 0001 */
   /* Bit an entsprechende Pos. schieben */
   test_val = (test_val << bit); 
   *val = (*val | test_val);     /* Bit an Pos bit setzen */
}

/* Funktion : Bit_Clear()
 * val  : Wert, bei dem Bit gel�scht werden soll
 * bit  : Bitnummer, die gel�scht werden soll (0-7)
 * R�ckgabewert :  keiner
 */

void Bit_Clear(BYTE *val, BYTE bit) {
   BYTE test_val = 0x01;        /* dezimal 1 / bin�r 0000 0001 */
   /* Bit an entsprechende Pos. schieben */
   test_val = (test_val << bit);
   *val = (*val & (~test_val));   /* Bit an Pos bit l�schen*/  
}

int main(void) {
   BYTE wert = 0;
   /* Test, ob Bit 0 gesetzt */
   printf("%s\n",Bit_Test(wert, 0)?"gesetzt":"nicht gesetzt"); 
   Bit_Set(&wert, 0);    /* Bit 0 setzen */ 
   /* Wieder testen, ob Bit 0 gesetzt */
   printf("%s\n",Bit_Test(wert, 0)?"gesetzt":"nicht gesetzt"); 
   Bit_Clear(&wert, 0);  /* Bit 0 wieder l�schen */
   /* Wieder testen ob Bit 0 gesetzt */
   printf("%s\n",Bit_Test(wert, 0)?"gesetzt":"nicht gesetzt"); 
   return 0;
}

