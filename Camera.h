#include "Libraries\glew\glew.h"
#include "Libraries\freeglut\glut.h"

class Camera {

public:
	Camera(int winw, int winh);
	void moveCamera(int newX, int newY, int newZ);
	void rotateCamera(float xRot, float yRot);

	int coordX;
	int coordY;
	int coordZ;

	float acceleration;
	float velocity;

	float xRot;
	float yRot;
};