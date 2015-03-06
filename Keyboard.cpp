#include "Keyboard.h"
#include "math.h"

Keyboard::Keyboard() {
	xRot = 126;
	yRot = 0;

	xPos = 25;
	zPos = 25;

	velocity = 0;
}

void Keyboard::keyPress(unsigned char key, int x, int y) {

	float xrotrad, yrotrad;
	yrotrad = ((float)yRot / 180 * 3.141592654f);
	xrotrad = ((float)xRot / 180 * 3.141592654f);

	if (key == 'w')
	{
		xPos += float(sin(xrotrad));
		zPos -= float(cos(xrotrad));
		//yPos -= float(sin(xrotrad));
	}

	if (key == 's')
	{
		xPos -= float(sin(yrotrad));
		zPos += float(cos(yrotrad));
		//yPos += float(sin(xrotrad));
	}

	if (key == 'd')
	{
		xPos += float(cos(xrotrad));
		zPos += float(sin(xrotrad));
	}

	if (key == 'a')
	{
		xPos -= float(cos(xrotrad));
		zPos -= float(sin(xrotrad));
	}

	if (key == 32) // spacebar
	{
		velocity = 5;
	}
}