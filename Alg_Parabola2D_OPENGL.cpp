#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void Parabola(void)
{
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);//agrega color a la parabola
    GLfloat y1=0;//declarando variable
    GLfloat cuadrado=0;//declarando variable

    for(GLfloat x1=-5; x1<=5; x1+=0.05)//For que itera desde -5 a 5
    {
	    cuadrado=x1*x1;//x al cuadrado
	    y1 = 2*cuadrado + 3*x1 - 2; //ecuación
	    glVertex2f(x1,y1);//vertice
	}

}
void Plano()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-5.0f, 0.0f);//eje negativo de las x
	glVertex2f(5.0f, 0.0f);//eje positivo de las x
	glVertex2f(0.0f, 5.0f);//eje positivo de las y
	glVertex2f(0.0f, -5.0f);//eje negativo y
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Plano();
    glEnd();
    glEnd();
    Parabola();
    glEnd();
    glFlush ();


}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Parabola");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
