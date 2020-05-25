#ifndef GAME_H
#define GAME_H

#include "field.h"
#include <conio.h>

class Game
{
public:
// Konstruktoren
	Game( const size_t HEIGHT, const size_t WIDTH );

// getter
	Field& getField();
	Tetromino* getActualBrick() const;
	const size_t& getIntervall() const;
	const size_t& getHighscore() const;

// Methoden
	void action( int key );
	void move();
	bool initializeNewBrick();
	bool run();
	void print() const;
	void printNextBrick() const;
	void updateHighscore( const size_t &lines );
	void printGameStatus() const;

//	void tampActualBrick( const Tetromino *brick );

private:
// Eigenschaften
	bool isGameOver;
	Field field;
	Tetromino *actualBrick;
	Tetromino *nextBrick;
	size_t intervall; // milliseconds
	size_t highscore;

// Methoden
	Tetromino* getRandomBrick();
	
};

#endif