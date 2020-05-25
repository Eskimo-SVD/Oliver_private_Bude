#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
using std::vector;

class Tetromino
{
public:
	enum TETROMINO{ I, J, L, O, S, T, Z };

// Konstruktoren
	Tetromino( const TETROMINO type, char format = '#', char whitespace = ' ' );

// getter
	const char** getActualBrickTemplate() const;
	const char getFormat() const;

// Methoden
	void print() const;
	void printAllTemplates() const;
	void rotate( int key );

// Destruktor
	~Tetromino();

private:
// Eigenschaften
	const char format;
	const char whitespace;
	TETROMINO type;
	char **actualBrickTemplate;
	size_t actualBrickIndex;
	vector<char**> brickFormTemplate;

// Methoden
	void generateTemplate( const char t[4][4] );
};

#endif
