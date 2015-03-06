#include "Libraries\glew\glew.h"
#include "Libraries\freeglut\glut.h"

class Camera {

public:
	Camera();
	void moveCamera(int newX, int newY, int newZ);
	void rotateCamera(int xRot, int yRot);
	void checkCollision();

	int coordX;
	float coordY;
	int coordZ;

	float acceleration;
	float velocity;

	float xRot;
	float yRot;

	bool collision;
};