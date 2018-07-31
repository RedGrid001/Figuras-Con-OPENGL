#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void cotangente(void)
{
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    //Declarando variables
    GLfloat y;
    GLfloat x;
    GLfloat i;

    for(i=-(3.0*M_PI); i<=(3.0*M_PI); i+=(0.001*M_PI))//dibuja desde -3pi hasta 3pi en el plano, aumentando de 0.001pi
    {

	    x=i;
	    y=1/tan((M_PI)*x);//ecuacion cotangente
	    glVertex2f(x,y);
    }
}
void Plano()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-(4.0f*M_PI), 0.0f);//eje negativo de las x
	glVertex2f((4.0f*M_PI), 0.0f);//eje positivo de las x
	glVertex2f(0.0f, (4.0f*M_PI));//eje positivo de las y
	glVertex2f(0.0f, -(4.0f*M_PI));//eje negativo y
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Plano();
    glEnd();
    cotangente();
    glEnd();
    glFlush ();


}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(4.0*M_PI), (4.0*M_PI), -(4.0*M_PI), (4.0*M_PI), -4.0, 4.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("cotangente");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
