#include "Libraries\glew\glew.h"
#include "Libraries\freeglut\glut.h"
#include <iostream>
#include <Math.h>    
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Libraries\glm\glm.hpp"
#include "Libraries\glm\gtc\matrix_transform.hpp"
#include "Libraries\glm\gtc\type_ptr.hpp"

using namespace std;

#include "Camera.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Block.h"

#define PI 3.14159265f

Camera* camera;
Mouse* mouse;
Keyboard* keyboard;

void drawButtons();

int winw = 720;
int winh = 700;

int refreshRate = 15;


/* Initialize OpenGL Graphics and Buttons */
void initGL()
{

}

void Draw2D()
{
	// drawButtons();
}

void Draw3D()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	int size = 50;

	int** blocks = new int*[size * size];
	for (int i = 0; i < size * size; i++) {
		blocks[i] = new int[3];
	}

	Block* block = new Block(1);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			block->drawBlock(i, -5, j);
		}
	}
	block->drawBlock(10, 5, 10);
	block->drawBlock(30, 5, 10);
	block->drawBlock(10, 5, 30);

	delete block;

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
}

void Draw()
{
	// Prepare for 3D drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (winh == 0) ? (1) : ((float)winw / winh), 1, 100);


	camera->checkCollision();

	keyboard->yRot = camera->yRot;
	keyboard->xRot = camera->xRot;

	camera->rotateCamera(mouse->x, mouse->y);
	camera->moveCamera(keyboard->xPos, keyboard->yPos, keyboard->zPos);

	cout << camera->coordY << " " << keyboard->velocity << endl;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Draw3D();
	
	// Prepare for 2D drawing
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, winw, winh, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Draw2D();

	glutSwapBuffers();
}

void Resize(int w, int h)
{
	winw = w;
	winh = h;
	glViewport(0, 0, w, h);
}

void timer(int value) {
	glutPostRedisplay();                  // Post re-paint request to activate display()
	glutTimerFunc(refreshRate, timer, 0); // next timer call milliseconds later
}

void mouseFunc(int x, int y) {
	mouse->mouseMotion(x, y);
}

void keyBoardFunc(unsigned char key, int x, int y) {
	keyboard->keyPress(key, x, y);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // Initialize GLUT
	glutInitWindowSize(winw, winh);   // Set the window's initial width & height
	glutInitWindowPosition(300, 100); // Position the window's initial top-left corner

	glutCreateWindow("World Explorer");  // Create window with the given title
	
	camera = new Camera();
	mouse = new Mouse;
	keyboard = new Keyboard;

	glutReshapeFunc(Resize);
	glutDisplayFunc(Draw);  
	glutMotionFunc(mouseFunc);
	glutPassiveMotionFunc(mouseFunc);
	glutKeyboardFunc(keyBoardFunc);

	glutTimerFunc(0, timer, 0);

	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop

	return 0;
}
