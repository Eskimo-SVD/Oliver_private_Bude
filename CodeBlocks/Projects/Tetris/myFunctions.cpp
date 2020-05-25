#include <Windows.h>

void clearScreen()
{
	HANDLE hOut;
	COORD position;

	position.X = 0;
	position.Y = 0;

	hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	SetConsoleCursorPosition( hOut, position );
}