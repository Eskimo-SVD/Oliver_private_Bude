#include "field.h"

#include <iostream>
using std::endl;
using std::cout;

// Konstruktoren
Field::Field( const size_t HEIGHT, const size_t WIDTH )
: HEIGHT( HEIGHT ),
  WIDTH( WIDTH ),
  field( nullptr )
{
	this->field = new char*[this->HEIGHT];

	for( size_t i=0; i<this->HEIGHT; i++ )
	{
		this->field[i] = new char[this->WIDTH];

		for( size_t j=0; j<this->WIDTH; j++ )
			this->field[i][j] = ' ';
	}

	for( size_t i=0; i<this->HEIGHT-1; i++ )
	{
		this->field[i][0] = '|';
		this->field[i][this->WIDTH-1] = '|';
	}

	for( size_t i=0; i<this->WIDTH; i++ )
		this->field[this->HEIGHT-1][i] = '~';
}

// getter
size_t Field::getHeight() const
{
	return this->HEIGHT;
}

size_t Field::getWidth() const
{
	return this->WIDTH;
}

const Field::Point& Field::getCursor() const
{
	return this->cursor;
}

// Methoden
void Field::clear( const char format )
{
	for( size_t i=0; i<this->HEIGHT; i++ )
	{
		for( size_t j=0; j<this->WIDTH; j++ )
		{
			if( this->field[i][j] == format )
				this->field[i][j] = ' ';
		}
	}
}

//void Field::clear( const Field::Point cursor, const Tetromino *brick )
//{
//	const char **tmp = brick->getActualBrickTemplate();
//
//	for( size_t i=0; i<4; i++ )
//	{
//		for( size_t j=0; j<4; j++ )
//		{
//			if( tmp[i][j] == brick->getFormat() )
//				this->field[cursor.getX() + i][cursor.getY() + j] = ' ';
//		}
//	}
//}

void Field::setCursor( const unsigned short x, const unsigned short y )
{
	this->cursor.setX( x );
	this->cursor.setY( y );
}

void Field::print() const
{
	for( size_t i=0; i<this->HEIGHT; i++ )
	{
		for( size_t j=0; j<this->WIDTH; j++ )
			cout << this->field[i][j];

		cout << endl;
	}
}

bool Field::isFree( const Tetromino *brick )
{
	const char **tmp = brick->getActualBrickTemplate();

	const size_t x = this->cursor.getX();
	const size_t y = this->cursor.getY();

	if( x < 0 || x >= this->HEIGHT || y < 0 || y >= this->WIDTH )
		return false;

	for( size_t i=0; i<4; i++ )
	{
		for( size_t j=0; j<4; j++ )
		{
			if( tmp[i][j] == brick->getFormat() )
			{
				if( this->field[x+i][y+j] == 'X'
					|| this->field[x+i][y+j] == '|'
					|| this->field[x+i][y+j] == '~' )
					return false;
			}
		}
	}
	return true;
}

bool Field::drawBrick( const Tetromino *brick, const char format )
{
	const char **tmp = brick->getActualBrickTemplate();
	
	for( size_t i=0; i<4; i++ )
	{
		for( size_t j=0; j<4; j++ )
		{
			if( tmp[i][j] == brick->getFormat() )
				this->field[this->cursor.getX()+i][this->cursor.getY()+j] = format;
		}
	}

	return true;
}

size_t Field::clearCompleteLines()
{
	size_t lines = 0;

	vector<int> connectedLines;

	for( int i = this->HEIGHT - 2; i>=0; i-- )
	{
		if( this->field[i][1] == 'X' )
		{
			bool found = true;

			for( int j = 1; j < this->WIDTH - 1; j++ )
			{
				if( this->field[i][j] != 'X' )
				{
					found = false;
					break;
				}
			}

			if( found )
			{
				connectedLines.push_back( i );
			}
		}
	}

	if( connectedLines.size() < 1 )
	{
		return 0;
	}
	else
	{
		lines = connectedLines.size();

		for( int i = connectedLines.size() - 1; i >= 0; i-- )
		{
			// Allocate Momory for new Field
			char **tmp = new char*[this->HEIGHT];
			for( int j = 0; j < this->HEIGHT; j++ )
			{
				tmp[j] = new char[this->WIDTH];
			}
			//---

			for( int j = this->HEIGHT - 1; j > connectedLines[i]; j-- )
			{
				for( int k = 0; k < this->WIDTH; k++ )
				{
					tmp[j][k] = this->field[j][k];
				}
			}
			for( int j = connectedLines[i] - 1; j >= 0; j-- )
			{
				for( int k = 0; k < this->WIDTH; k++ )
				{
					tmp[j + 1][k] = this->field[j][k];
				}
			}
			for( int i = 1; i < this->WIDTH - 1; i++ )
			{
				tmp[0][i] = ' ';
			}
			tmp[0][0] = '|';
			tmp[0][this->WIDTH - 1] = '|';

			// switch fields
			char **del = this->field;
			this->field = tmp;

			for( int i = 0; i < this->WIDTH; i++ )
			{
				delete [] ( del[i] );
			}
			delete [] del;
		}
	}

	return lines;
}

//void Field::tamp( const Tetromino *brick )
//{
//	const char **tmp = brick->getActualBrickTemplate();
//
//	for( size_t i=0; i<4; i++ )
//	{
//		for( size_t j=0; j<4; j++ )
//		{
//			if( tmp[i][j] == brick->getFormat() )
//				this->field[this->cursor.getX()+i][this->cursor.getY()+j] = 'X';
//		}
//	}
//}

// Destruktor
Field::~Field()
{
	for( size_t i=0; i<this->HEIGHT; i++ )
		delete [] this->field[i];

	delete [] this->field;
}