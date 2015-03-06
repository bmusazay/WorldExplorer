#include "Camera.h"

Camera::Camera() {
	acceleration = .01;
	velocity = 0;

	xRot = 126;
	yRot = 0;

	coordY = 5;
	collision = false;
}

void Camera::moveCamera(int newX, int newY, int newZ) {

	velocity += acceleration;
	if (collision) {
		velocity = 0;
	}

	coordX = newX;
	coordY -= velocity;
	coordZ = newZ;
	
	glTranslated(-coordX, -coordY, -coordZ);
}

void Camera::rotateCamera(int newXRot, int newYRot) {

	int newY = newYRot % 360;
	xRot = newXRot % 360;

	if (!(newY > 90 && newY < 270)) {
			yRot = newY;
	} 

	glRotatef(yRot, 1.0, 0.0, 0.0);
	glRotatef(xRot, 0.0, 1.0, 0.0);
}

void Camera::checkCollision() {
	collision = false;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i == coordX) {
				if (coordY < -1) {
					if (j == coordZ) {
						collision = true;
					}
				}
			}
		}
	}

}