#include "stdafx.h"

//---------------------------------------------------------------------------
// Koordinatentransformation Welt- in Screenkoordinaten
//---------------------------------------------------------------------------

int trans(int sa, int se, double wa, double we, double w)
{
   return ( (int) ((se-sa)/(we-wa)*(w-wa)+sa) );
}

//---------------------------------------------------------------------------