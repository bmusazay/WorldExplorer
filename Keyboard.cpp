#include "Keyboard.h"
#include "math.h"

Keyboard::Keyboard() {

	xRot = 0;
	yRot = 0;

	xPos = 0;
	yPos = 0;
	zPos = 0;
}

void Keyboard::keyPress(unsigned char key, int x, int y) {
	if (key == 'w')
	{
		float xrotrad, yrotrad;
		yrotrad = (yRot / 180 * 3.141592654f);
		xrotrad = (xRot / 180 * 3.141592654f);
		xPos += float(sin(yrotrad));
		zPos -= float(cos(yrotrad));
		// yPos -= float(sin(xrotrad));
	}

	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (yRot / 180 * 3.141592654f);
		xrotrad = (xRot / 180 * 3.141592654f);
		xPos -= float(sin(yrotrad));
		zPos += float(cos(yrotrad));
		// yPos += float(sin(xrotrad));
	}

	if (key == 'd')
	{
		float yrotrad;
		yrotrad = (yRot / 180 * 3.141592654f);
		xPos += float(cos(yrotrad));
		zPos += float(sin(yrotrad));
	}

	if (key == 'a')
	{
		float yrotrad;
		yrotrad = (yRot / 180 * 3.141592654f);
		xPos -= float(cos(yrotrad));
		zPos -= float(sin(yrotrad));
	}
}