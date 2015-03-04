#include "Block.h"

Block::Block() {}

Block::Block(int edge) {
	this->edge = edge;
}

void Block::drawBlock(int coordX, int coordY, int coordZ) {
	glPushMatrix();
	glTranslatef(coordX, coordY, coordZ);

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
		// Top face (y = edge)
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(edge, edge, -edge);
		glVertex3f(-edge, edge, -edge);
		glVertex3f(-edge, edge, edge);
		glVertex3f(edge, edge, edge);

		// Bottom face (y = -edge)
		glVertex3f(edge, -edge, edge);
		glVertex3f(-edge, -edge, edge);
		glVertex3f(-edge, -edge, -edge);
		glVertex3f(edge, -edge, -edge);


		// Front face  (z = edge)
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(edge, edge, edge);
		glVertex3f(-edge, edge, edge);
		glVertex3f(-edge, -edge, edge);
		glVertex3f(edge, -edge, edge);

		// Back face (z = -edge)
		glVertex3f(edge, -edge, -edge);
		glVertex3f(-edge, -edge, -edge);
		glVertex3f(-edge, edge, -edge);
		glVertex3f(edge, edge, -edge);

		// Left face (x = -edge)
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-edge, edge, edge);
		glVertex3f(-edge, edge, -edge);
		glVertex3f(-edge, -edge, -edge);
		glVertex3f(-edge, -edge, edge);

		// Right face (x = edge)
		glVertex3f(edge, edge, -edge);
		glVertex3f(edge, edge, edge);
		glVertex3f(edge, -edge, edge);
		glVertex3f(edge, -edge, -edge);
	glEnd();  // End of drawing color-cube
	glPopMatrix();

}
