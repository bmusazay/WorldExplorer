#include "Camera.h"

Camera::Camera() {

}
void Camera::moveCamera(int newX, int newY, int newZ) {

	glTranslated(-coordX, -coordY, -coordZ);
}

void Camera::rotateCamera(float newXRot, float newYRot) {
	xRot += newXRot;
	yRot += newYRot;

	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);

}