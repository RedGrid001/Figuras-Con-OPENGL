#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float pi3 = 5*M_PI, x, fx, eje = 0;//pi3 es el punto o posicion de de 5PI

void Furrier()
{
	glBegin(GL_LINES);

    float k = 4;//Constante de la formula
    for(float i = -(3*M_PI); i<=(5*M_PI); i+= (M_PI))//For declarado desde -3PI hasta 5PI aumentando de PI en PI
    {
		x = i;//Posicion de x
		fx = k + ((4.0*k)/M_PI)*((sin(x))+ (1/3.0*sin(3*x)) + (1/5.0*sin(5*x)));//encontrando la posicion de y
		glVertex3f(x,fx,0.0f);//Puntos de la linea paralela al eje x
		glVertex3f(x,0.0f,0.0f);//Primer punto de la linea paralela al eje y, se movera solamente en el eje x
		glVertex3f(x,fx,0.0f);//Segundo punto de la linea paralela al eje y, se movera en "x" y "y"
	}

	}
void Plano()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-(6.0f*M_PI), 0.0f);//eje negativo de las x
	glVertex2f((6.0f*M_PI), 0.0f);//eje positivo de las x
	glVertex2f(0.0f, (6.0f*M_PI));//eje positivo de las y
	glVertex2f(0.0f, -(6.0f*M_PI));//eje negativo y
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Plano();
    glEnd();
    glEnd();
    Furrier();
    glEnd();
    glFlush ();


}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(6*M_PI), (6*M_PI), -(6*M_PI), (6*M_PI), 1.0, -1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Furrier");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
