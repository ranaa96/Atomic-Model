
#include "pch.h"
#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>

  //Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
int flag = 0;
//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	case 32: //Space key
		if (!flag)
			flag = 1;
		else if (flag)
			flag = 0 ;
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

//Draws the 3D scene
float angle;
float R = 0.0 ;
float B = 0.0;

void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	
	glLoadIdentity(); //Reset the drawing perspective

	glTranslatef(0.0, 0.0, -15.0);

	if (flag == 0)
		glScalef(1.0f, 1.0f, 1.0f);
	else {
		// press space key
		glScalef(0.5f, 0.5f, 1.0f);

		glPushMatrix();
		glTranslatef(7.0f, 5.0f, 0.0f);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(1.0f, 0.7f, 0.2f);
			angle = i * 3.142 / 180;
			glVertex3f(2.5*cos(angle), 2.5*sin(angle), 0.0);
		}
		glEnd();
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(0.25, 0.0);
		glVertex2f(-0.25, 0.0);
		glVertex2f(0.0, 0.25);
		glVertex2f(0.0, -0.25);
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			angle = i * 3.142 / 180;
			glColor3f(1.0f, 0.7f, 0.2f);
			glVertex3f(0.8*cos(angle), 0.8*sin(angle), 0.0);

		}
		glEnd();
		for (float n = 0.0; n <= 270.0; n += 90.0) {
			glRotatef(n, 0.0f, 0.0f, 1.0f);
			glPushMatrix();
			glTranslatef(0.95f, 0.95f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;
				glColor3f(0.3f, 0.4f, 1.0f);
				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0.5f, 1.8f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;
				glColor3f(0.3f, 0.4f, 1.0f);
				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.8f, 0.5f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;
				glColor3f(0.3f, 0.4f, 1.0f);
				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();
		}


		glPopMatrix();


		glPushMatrix();

		glTranslatef(-7.0f, 5.0f, 0.0f);


		for (float n = 0.0; n <= 270.0; n += 90.0) {
			glRotatef(n, 0.0f, 0.0f, 1.0f);
			glPushMatrix();
			glTranslatef(0.5f, 0.5f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;
				glColor3f(0.3f, 0.4f, 1.0f);
				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0.5f, 1.8f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;
				glColor3f(0.3f, 0.4f, 1.0f);
				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.8f, 0.5f, 0.0f);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++)
			{
				angle = i * 3.142 / 180;

				glVertex3f(0.27*cos(angle), 0.27*sin(angle), 0.0);

			}
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.5f, 1.1f, 0.0f);
			glBegin(GL_LINES);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(0.25, 0.0);
			glVertex2f(-0.25, 0.0);
			glVertex2f(0.0, 0.25);
			glVertex2f(0.0, -0.25);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.1f, 0.5f, 0.0f);
			glBegin(GL_LINES);
			glVertex2f(0.25, 0.0);
			glVertex2f(-0.25, 0.0);
			glVertex2f(0.0, 0.25);
			glVertex2f(0.0, -0.25);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1.4f, 1.4f, 0.0f);
			glBegin(GL_LINES);
			glVertex2f(0.25, 0.0);
			glVertex2f(-0.25, 0.0);
			glVertex2f(0.0, 0.25);
			glVertex2f(0.0, -0.25);
			glEnd();
			glPopMatrix();


		}


		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			angle = i * 3.142 / 180;
			glColor3f(1.0f, 0.7f, 0.2f);
			glVertex3f(2.5*cos(angle), 2.5*sin(angle), 0.0);

		}

		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0f, -6.3f, 0.0f);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			angle = i * 3.142 / 180;
			glColor3f(1.0f, 0.7f, 0.2f);
			glVertex3f(2.5*cos(angle), 2.5*sin(angle), 0.0);

		}

		glEnd();
		glPopMatrix();
	}

	//Start draw atom model

	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(-0.25, 0.25, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		angle = i * 3.142 / 180;

		glVertex3f(0.125*cos(angle), 0.125*sin(angle), 0.0);

	}
	glEnd();
	glPopMatrix();

	glColor3f(0.0f, 0.4f, 0.8f);
		glPushMatrix();
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			angle = i * 3.142 / 180;
			
			glVertex3f(0.5*cos(angle), 0.5*sin(angle), 0.0);

		}
		glEnd();
		
		glPopMatrix();

		glPushMatrix();

		glRotatef(20.0, 1.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.3f, 0.7f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(3.0*cos(angle), 0.0, 3.0*sin(angle));
		}
		glEnd();
		glTranslatef(-3.0, 0.0, 0.0);
		glTranslatef(3.0*cos(angle), 0.0, 3.0*sin(angle));
		glRotatef(R, 0.0, 1.0, 0.0);
		glTranslatef(-3.0*cos(angle), 0.0, -3.0*sin(angle));
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.0f, 0.4f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(0.125*cos(angle), 0.125*sin(angle), 0.0);
		}
		glEnd();

		glPopMatrix();


		glPushMatrix();
		glRotatef(-45.0, 0.0, 0.0, 1.0);
		glRotatef(-20.0, 0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.3f, 0.7f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(0.0, 3.0*cos(angle), 3.0*sin(angle));
		}
		glEnd();

		glTranslatef(0.0, -3.0, 0.0);
		glTranslatef(0.0, 3.0*cos(angle), 3.0*sin(angle));
		glRotatef(R, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -3.0*cos(angle), -3.0*sin(angle));
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.0f, 0.4f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(0.125*cos(angle), 0.125*sin(angle), 0.0);
		}
		glEnd();
		glPopMatrix();

		glColor3f(0.4f, 0.9f, 1.0f);
		glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glRotatef(20.0, 0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.3f, 0.7f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(0.0, 3.0*cos(angle), 3.0*sin(angle));
		}
		glEnd();

		glTranslatef(0.0, -3.0, 0.0);
		glTranslatef(0.0, 3.0*cos(angle), 3.0*sin(angle));
		glRotatef(R, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -3.0*cos(angle), -3.0*sin(angle));
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			glColor3f(0.0f, 0.4f, 0.8f);
			angle = i * 3.142 / 180;
			glVertex3f(0.125*cos(angle), 0.125*sin(angle), 0.0);
		}
		glEnd();
		glPopMatrix();

		R += 0.1;

		glutPostRedisplay();              //Tell GLUT that the display has changed
		glutTimerFunc(25, 0, 0);          //Tell GLUT to call update again in 25 milliseconds
	

		glutSwapBuffers();
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(550, 550); //Set the window size

	//Create the window
	glutCreateWindow("Atomic model");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}