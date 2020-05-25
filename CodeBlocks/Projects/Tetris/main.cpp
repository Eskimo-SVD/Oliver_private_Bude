#include <Windows.h>

#include "myFunctions.h"
#include "game.h"

#include <cstdlib>
#include <conio.h>
#include <iostream>
using std::cout;
using std::endl;

#include <time.h>

#pragma comment( lib, "winmm.lib" )

int main()
{
	setlocale( LC_ALL, "" );

	Tetromino ted( Tetromino::J );
	Game tetris( 18, 12 );

	PlaySound( "tetris.WAV", nullptr, SND_LOOP | SND_ASYNC | SND_FILENAME );

	tetris.initializeNewBrick();
	tetris.getField().drawBrick( tetris.getActualBrick() );
	tetris.print();

	int key;

	Field &feld = tetris.getField();
	int i=0;

	size_t actualTime = GetTickCount();

	long actualPlaytime = static_cast<size_t>( time( nullptr ) );

	while( tetris.run() )
	{	
		if( _kbhit() )
		{
			key = _getch();

			tetris.action( key );
			key = ' ';

			feld.clear( tetris.getActualBrick()->getFormat() );
			feld.drawBrick( tetris.getActualBrick() );
			clearScreen();
			tetris.print();
		}

		++i;

		bool tamp = false;

		if( tamp || actualTime + tetris.getIntervall() < GetTickCount() )
		{
			actualTime = GetTickCount();

			feld.setCursor( feld.getCursor().getX()+1, feld.getCursor().getY() );
			
			if( feld.isFree( tetris.getActualBrick() ) )
			{		
				tamp = false;

				feld.clear( tetris.getActualBrick()->getFormat() );
				feld.drawBrick( tetris.getActualBrick() );
				i=0;
				clearScreen();		
				tetris.print();
			}
			else // tamp
			{
				tamp = true;

				feld.setCursor( feld.getCursor().getX()-1, feld.getCursor().getY() );
				feld.drawBrick( tetris.getActualBrick(), 'X' ); // tamp!

				size_t lines = feld.clearCompleteLines();
				tetris.updateHighscore( lines );

				tetris.initializeNewBrick();
				clearScreen();		
				tetris.print();
			}

			std::cout << std::endl;
			std::cout << "Next Brick:";
			std::cout << std::endl;
			tetris.printNextBrick();

			std::cout << std::endl;
			std::cout << "Highscore:\t";
			std::cout << tetris.getHighscore() << std::endl;
		}
	}

	system( "CLS" );
	std::cout << "GAME OVER" << std::endl;

	tetris.printGameStatus();
	cout << "Playtime: " << static_cast<size_t>( time( nullptr ) ) - actualPlaytime << " Sec" << endl;

	system( "PAUSE" );
	return 0;
}