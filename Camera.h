#include "Libraries\glew\glew.h"
#include "Libraries\freeglut\glut.h"

class Camera {

public:
	Camera();
	void moveCamera(int newX, int newY, int newZ);
	void rotateCamera(float xRot, float yRot);

private:
	int coordX;
	int coordY;
	int coordZ;

	float xRot;
	float yRot;
};