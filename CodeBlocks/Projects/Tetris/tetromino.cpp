#include "tetromino.h"

#include <iostream>
using std::endl;
using std::cout;

// Konstruktoren
Tetromino::Tetromino( const Tetromino::TETROMINO type, char format, char whitespace )
: format( format),
  whitespace( whitespace ),
  type( type ),
  actualBrickTemplate( nullptr )
{
	this->brickFormTemplate.resize( 0 );

	switch( type )
	{
		case I:
			{
				const char t1[4][4] = {
					this->whitespace, this->format, this->whitespace, this->whitespace,
					this->whitespace, this->format, this->whitespace, this->whitespace,
					this->whitespace, this->format, this->whitespace, this->whitespace,
					this->whitespace, this->format, this->whitespace, this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->whitespace, this->whitespace, this->whitespace, this->whitespace,
					this->format, this->format, this->format, this->format,
					this->whitespace, this->whitespace, this->whitespace, this->whitespace,
					this->whitespace, this->whitespace, this->whitespace, this->whitespace
				};
				this->generateTemplate( t2 );
			}
			break;

		case J:
			{
				const char t1[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->format,		this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t2 );

				const char t3[4][4] = {
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t3 );

				const char t4[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t4 );
			}
			break;

		case L:
			{
				const char t1[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->format,		this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t2 );

				const char t3[4][4] = {
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t3 );

				const char t4[4][4] = {
					this->whitespace,	this->whitespace,	this->format,		this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t4 );
			}
			break;

		case O:
			{
				const char t1[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );
			}
			break;

		case S:
			{
				const char t1[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->format,		this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t2 );
			}
			break;

		case T:
			{
				const char t1[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t2 );

				const char t3[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->format,		this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t3 );

				const char t4[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t4 );
			}
			break;

		case Z:
			{
				const char t1[4][4] = {
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->whitespace,	this->format,		this->format,		this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t1 );

				const char t2[4][4] = {
					this->whitespace,	this->format,		this->whitespace,	this->whitespace,
					this->format,		this->format,		this->whitespace,	this->whitespace,
					this->format,		this->whitespace,	this->whitespace,	this->whitespace,
					this->whitespace,	this->whitespace,	this->whitespace,	this->whitespace
				};
				this->generateTemplate( t2 );
			}
			break;
	}

	this->actualBrickIndex = 0;
	this->actualBrickTemplate = this->brickFormTemplate[0];
}

// getter
const char** Tetromino::getActualBrickTemplate() const
{
	return const_cast<const char**>( this->actualBrickTemplate );
}

const char Tetromino::getFormat() const
{
	return this->format;
}

// Methoden
void Tetromino::print() const
{
	for( size_t i=0; i<4; i++ )
	{
		for( size_t j=0; j<4; j++ )
		{
			cout << this->actualBrickTemplate[i][j];
		}
		cout << endl;
	}
}

void Tetromino::printAllTemplates() const
{
	for( size_t i=0; i<this->brickFormTemplate.size(); i++ )
	{
		for( size_t j=0; j<4; j++ )
		{
			for( size_t k=0; k<4; k++ )
			{
				cout << this->brickFormTemplate[i][j][k];
			}
			cout << endl;
		}
		cout << "\n" << endl;
	}
}

void Tetromino::rotate( int key )
{
	int index = this->actualBrickIndex;

	switch( key )
	{
	case 'a':
	case 'A':
		index = ( (index-1) + this->brickFormTemplate.size() ) % this->brickFormTemplate.size();
		this->actualBrickIndex = index;
		this->actualBrickTemplate = this->brickFormTemplate[index];
		break;

	case 'd':
	case 'D':
		index = ( (index+1) + this->brickFormTemplate.size() ) % this->brickFormTemplate.size();
		this->actualBrickIndex = index;
		this->actualBrickTemplate = this->brickFormTemplate[index];
		break;
	}
}

void Tetromino::generateTemplate( const char t[4][4] )
{
	this->brickFormTemplate.push_back( new char*[4] );

	for( size_t i=0; i<4; i++ )
	{
		this->brickFormTemplate[this->brickFormTemplate.size()-1][i] = new char[4];
	}

	for( size_t i=0; i<4; i++ )
	{
		for( size_t j=0; j<4; j++ )
		{	
			this->brickFormTemplate[this->brickFormTemplate.size()-1][i][j] = t[i][j];
		}
	}
}

// Destruktor
Tetromino::~Tetromino()
{
	for( size_t i=0; i<this->brickFormTemplate.size(); i++ )
	{
		for( size_t j=0; j<4; j++ )
		{
			delete [] ( this->brickFormTemplate[i][j] );
		}

		delete [] ( this->brickFormTemplate[i] );
	}
}