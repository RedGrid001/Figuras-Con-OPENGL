#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void bresenham(void)
{
	double xi=-4;
	double yi=-4;
	double xf=4;
	double yf=4;
	double x=0;
	double y=0;
	double deltax,deltay,constante,fin;
	deltax=abs(xf-xi);//valor absoluto abs "4--4" 8
	deltay=abs(yf-yi);//valor absoluto abs "4--4" 8 valor final menos el inicial
	constante=2*deltay-deltax;//constante 2* 8-8

	if(xi>xf)//si xi=-4 es mayor a xf=4
	{
		x=xf;//x que vale cero sera igual a xf que vale 4
		y=yf;//y que vale cero sera igual a yf que vale 4
		fin=xi;//la variable fin tomara el valor de xi que vale -4
		}
		else//ademas
		{
			x=xi;//x que vale cero tomara el vaor de xi que vale -4
			y=yi;//y qe vale cero tomara el valor de yique vale -4
			fin=xf;//la variable fin tomara el valor de xf que es 4

			}

		 glBegin(GL_POINTS);
         glColor3f(1.0, 1.0, 1.0);
		 glVertex2f(x, y);//dibujo de pixel en x y y


         while(x<fin)//mientras x que vale cero sea menor a fin que toma valores entre -4 y 4a
				 {
			 x+=1;//habra un incremento en 1 por cada linea
			 if(constante<0)// si la constante que es 2 por delta y y delta x es menor a cero
			 {
				 constante+=2*deltay;//se hara un incremento de 2 por delta y octavo paso del pseudocodigo
				 }
				 else//ademas
				 {
					 y+=1;//incremento en 1 para y
					 constante+=2*(deltay-deltax);
					 }
					 glBegin(GL_POINTS);
					 glVertex2f(x, y);
			 }

}
void Plano()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-6.0f, 0.0f);//eje negativo de las x dibujo
	glVertex2f(6.0f, 0.0f);//eje positivo de las x
	glVertex2f(0.0f, 6.0f);//eje positivo de las y
	glVertex2f(0.0f, -6.0f);//eje negativo y
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Plano();
    glEnd();
    bresenham();
    glEnd();
    glFlush ();


}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("bresenham");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
