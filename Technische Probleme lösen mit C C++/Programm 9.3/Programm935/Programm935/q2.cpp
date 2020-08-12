#include "stdafx.h"
short int q2(short int a, short int b, short int c)
{
	return (a && b && c) || (a && b && !c) || (a && !b && c) || (!a && b && c);
}