#include <gl/glut.h> 


void init(void)
{
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}



void display(void)
{
   //Clear the window and the depth buffer
   glClearColor(0.0, 0.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glColor3f(0.0,1.0,0.0);
   glutWireCube(.90) ;

   //Render the triangle
   glColor3f(1.0f, 0.0f, 0.0f );
   glBegin(GL_TRIANGLES);
	   glVertex2d( -0.35f, -0.35f );
	   glVertex2d( 0.35f, -0.35f );
	   glVertex2d( 0.0f, 0.35f );
   glEnd();
 
   //Swap front and back buffer
   glutSwapBuffers();
}
 
int main(int argc, char **argv)
{
   glutInit(&argc, argv); 
   glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
   glutInitWindowSize(500, 500); 
   glutCreateWindow("Practica 1a");  
 
   init();
 
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
 
   glutMainLoop();
 
   return 0;
}