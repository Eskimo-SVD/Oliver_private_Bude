#include <Windows.h>
#include "game.h"
#include "field.h"
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

// Konstruktoren
Game::Game( const size_t HEIGHT, const size_t WIDTH )
:	isGameOver( false ),
	field( HEIGHT, WIDTH ),
	actualBrick( nullptr ),
	nextBrick( nullptr ),
	intervall( 1000 ),
	highscore( 0 )
{
	srand( static_cast<size_t>( time(NULL) ) );
}

// getter
Field& Game::getField()
{
	return this->field;
}

Tetromino* Game::getActualBrick() const
{
	return this->actualBrick;
}

const size_t& Game::getIntervall() const
{
	return this->intervall;
}

const size_t& Game::getHighscore() const
{
	return this->highscore;
}

// Methoden
void Game::action( int key )
{
	switch( key )
	{
		case 224: // Irgend eine Arrow Taste wurde eingetippt
			this->move();
			break;

		case 'a':
		case 'A':
			this->actualBrick->rotate( 'a' );
			if( !this->field.isFree( this->actualBrick ) )
			{
				this->actualBrick->rotate( 'd' );
			}
			break;

		case 'd':
		case 'D':
			this->actualBrick->rotate( 'd' );
			if( !this->field.isFree( this->actualBrick ) )
			{
				this->actualBrick->rotate( 'a' );
			}
			break;

		case ' ':
			system( "CLS" );

			PlaySound( nullptr, 0, 0 );

			cout << "PAUSE" << endl;
			cout << endl;

			cout << "..zum Weiterspielen beliebige Taste drücken!" << endl;

			system( "PAUSE" );
			system( "CLS" );

			PlaySound( "tetris.WAV", nullptr, SND_LOOP | SND_ASYNC | SND_FILENAME );
	}
}

void Game::move()
{
	int key = _getch();

	switch( key )
	{
	case 75: // Move Left
		this->field.setCursor( this->field.getCursor().getX(), this->field.getCursor().getY() - 1 );
		if( !this->field.isFree( this->actualBrick ) )
		{
			this->field.setCursor( this->field.getCursor().getX(), this->field.getCursor().getY() + 1 );
		}
		break;

	case 77: // Move Right
		this->field.setCursor( this->field.getCursor().getX(), this->field.getCursor().getY() + 1 );
		if( !this->field.isFree( this->actualBrick ) )
		{
			this->field.setCursor( this->field.getCursor().getX(), this->field.getCursor().getY() - 1 );
		}
		break;

	case 80: // Move Down
		this->field.setCursor( this->field.getCursor().getX() + 1, this->field.getCursor().getY() );
		if( !this->field.isFree( this->actualBrick ) )
		{
			this->field.setCursor( this->field.getCursor().getX() - 1 , this->field.getCursor().getY() );
		}
		break;
	}
}

bool Game::initializeNewBrick()
{
	if( this->actualBrick != nullptr )
		delete this->actualBrick;

	this->field.setCursor( 0, ( this->field.getWidth() / 2 ) - 1 );

	if( this->nextBrick != nullptr )
	{
		this->actualBrick = this->nextBrick;
	}
	else
	{
		this->actualBrick = getRandomBrick();
	}
	this->nextBrick = getRandomBrick();

	if( this->field.isFree( this->actualBrick ) )
	{
		return true;
	}
	else
	{
		this->isGameOver = true;
		return false;
	}
}

bool Game::run()
{
	return !this->isGameOver;
}

void Game::print() const
{
	this->field.print();
}

void Game::printNextBrick() const
{
	if( this->nextBrick != nullptr )
	{
		this->nextBrick->print();
	}
}

void Game::updateHighscore( const size_t &lines )
{
	switch( lines )
	{
	case 1: this->highscore += 100;
		break;

	case 2: this->highscore += 250;
		break;

	case 3: this->highscore += 500;
		break;

	case 4: this->highscore += 1000;
		break;
	}

	// 10
	if( this->highscore > 60000 )
	{
		this->intervall = 400;
	}
	// 9
	else if( this->highscore > 55000 )
	{
		this->intervall = 480;
	}
	// 8
	else if( this->highscore > 50000 )
	{
		this->intervall = 540;
	}
	// 7
	else if( this->highscore > 45000 )
	{
		this->intervall = 620;
	}
	// 6
	else if( this->highscore > 40000 )
	{
		this->intervall = 700;
	}
	// 5
	else if( this->highscore > 35000 )
	{
		this->intervall = 780;
	}
	// 4
	else if( this->highscore > 30000 )
	{
		this->intervall = 860;
	}
	// 3
	else if( this->highscore > 25000 )
	{
		this->intervall = 940;
	}
	// 2
	else if( this->highscore > 20000 )
	{
		this->intervall = 920;
	}
}

void Game::printGameStatus() const
{
	cout << "Highscore: " << this->highscore << endl;
}

//void Game::tampActualBrick( const Tetromino *brick )
//{
//	this->field.tamp( brick );
//}

Tetromino* Game::getRandomBrick()
{
	return new Tetromino( static_cast<Tetromino::TETROMINO>( rand() % 7 ) );
}