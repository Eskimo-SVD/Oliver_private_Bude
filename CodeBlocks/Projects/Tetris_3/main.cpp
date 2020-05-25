//Dark GDK - The Game Creators - www.thegamecreators.com

//the wizard has created a very simple project that uses Dark GDK
//it contains the basic code for a GDK application

//whenever using Dark GDK you must ensure you include the header file
#include "DarkGDK.h"


//Global
int Block_Size=20;
const DWORD Red = dbRGB(255,0,0);
const DWORD Green = dbRGB(0,255,0);
const DWORD Blue = dbRGB(0,0,255);
const DWORD Magenta = dbRGB(255,0,255);
const DWORD Black = dbRGB(0,0,0);
const DWORD White = dbRGB(255,255,255);
const DWORD Yellow = dbRGB(255,255,0);
const DWORD Cyan = dbRGB(0,255,255);
const DWORD Orange = dbRGB(255,165,0);

//end global

//Classes

class Block {
private:
	int x,y;
	DWORD color;
public:
	Block(int, int, DWORD);
	void draw();
	void move(int, int);
	void clear();

};

//Methods (Block)

Block::Block(int X, int Y, DWORD COLOR)
{
	x=X;
	y=Y;
	color=COLOR;
}

void Block::draw()
{
	int x1, y1, x2, y2;
	x1=x*Block_Size;
	y1=y*Block_Size;
	x2=x1+Block_Size;
	y2=y1+Block_Size;

	dbInk(color, Black);
	dbBox(x1,y1,x2,y2);
}

void Block::move(int dx, int dy)
{
	x=x+dx;
	y=y+dy;
	draw();
}
//End Method (Block)

class Shape {

private:
	Block blocks[4];
public:
	Shape(void);
	void move_shape(int,int);
	void clear_shape();
	void draw_shape();
};


class I_Shape: public Shape{
public:
	I_Shape(int,int);
private:
	DWORD color;
	int pos[8];
};

//Methods (I_Shape)
I_Shape::I_Shape(int x, int y):Shape()
{
	color=Blue;
	pos[0]=x-1;
	pos[1]=y;
	pos[2]=x;
	pos[3]=y;
	pos[4]=x+1;
	pos[5]=y;
	pos[6]=x+2;
	pos[7]=y;
}

// the main entry point for the application is this function
void DarkGDK ( void )
{
	// turn on sync rate and set maximum rate to 1 fps
	dbSyncOn   ( );
	dbSyncRate ( 1 );

	// our main loop
	while ( LoopGDK ( ) )
	{
		// update the screen
		dbSync ( );
	}

	// return back to windows
	return;
}
