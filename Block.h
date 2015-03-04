#include "Libraries\glew\glew.h"
#include "Libraries\freeglut\glut.h"

class Block {

public:
	Block();
	Block(int edge);
	void drawBlock(int coordX, int coordY, int coordZ);

private:
	float edge;
};
