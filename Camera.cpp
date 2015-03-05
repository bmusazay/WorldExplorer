#include "Camera.h"

Camera::Camera(int winw, int winh) {
	xRot = winw / 2;
	yRot = winh / 2;

	acceleration = 0;
	velocity = .1;
}

void Camera::moveCamera(int newX, int newY, int newZ) {

	coordX = newX;
	coordY = newY + acceleration;
	coordZ = newZ;

	//acceleration += velocity;

	glTranslated(-coordX, -coordY, -coordZ);
}

void Camera::rotateCamera(float newXRot, float newYRot) {

	xRot = newXRot;
	yRot = newYRot;

	glRotatef(yRot, 1.0, 0.0, 0.0);
	glRotatef(xRot, 0.0, 1.0, 0.0);
}