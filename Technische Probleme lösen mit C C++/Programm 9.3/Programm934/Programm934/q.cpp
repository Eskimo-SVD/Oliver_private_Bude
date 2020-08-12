#include "stdafx.h"
short int q(short int a, short int b, short int c)
{
	return (a || !b) && c;
}