  //RAUL ERNESTO PERDOMO COREAS PC14046
#include <GL/gl.h>//llamado a librerias glut
#include <GL/glut.h>
#include <math.h>
void display(void)//funcion para la proyeccion en pantalla
{
    glClearColor(0,0,0,0);//color amarillo que se proyecta en la consola
    glClear(GL_COLOR_BUFFER_BIT);//Ajusta el área de plano binario de la ventana a los valores previamente seleccionados

	//FIGURA-----------------------------------------------------------

	float x, y, r, i;//definicion de variables para trazado en eje x y eje y
                  //definicion de variables r parra el radio que tomara la circunferencia del chorro
	GLfloat angulo;//declaracion de variable glut para el trazado del circulo que divide la manecilla y poder transformar los radianes a grados



	glBegin(GL_LINES);//primitiva que permite el enlace entre lineas en diferentes ejes

	//-------------------------tubo deManecilla
  glColor3f(128,0,0);//color verde manecilla
  glVertex2f(-4, 10);//trazado de ala izquierda de manecilla
	glVertex2f(4, 10);//trazado de punto ala derecha de manecilla

	glVertex2f(-3, 12);//trazado de punto ala izquierda de manecilla
	glVertex2f(3, 12);//trazado de punto ala derecha de manecilla

	glVertex2f(-3, 10);//trazado de punto ala izquierda de manecilla
	glVertex2f(-3, 12);//trazado de punto ala izquierda de manecilla

	glVertex2f(3, 10);//trazado de punto ala derecha de manecilla
	glVertex2f(3, 12);//trazado de punto ala derecha de manecilla


	glVertex2f(-1, 12);//trazado de punto ala izquierda de manecilla
	glVertex2f(-1, 16.3);//trazado de segmento de linea a la izquierda de manecilla

	glVertex2f(1, 12);//trazado de linea derecha de manecilla
	glVertex2f(1, 16.3);//trazado de segmento de linea a la derecha de manecilla

		//OREJAS DEL CHORRO----
//OREJA IZQUIERDA
  glColor3f(0,255,0);//color verde
	glVertex2f(-2, 18);//vertice de maneciila del lado izquierdo
	glVertex2f(-7, 17);//vertice de manecilla del lado izquierdo

	glVertex2f(-2, 18);//vertice de maneciila del lado izquierdo
	glVertex2f(-7, 19);//vertice de maneciila del lado izquierdo

	glVertex2f(-7, 17);//vertice de maneciila del lado izquierdo
	glVertex2f(-7, 19);//vertice de maneciila del lado izquierdo
//OREJA DERECHA
	glVertex2f(2, 18);//vertice de maneciila del lado derecho
	glVertex2f(7, 17);//vertice de maneciila del lado derecho

	glVertex2f(2, 18);//vertice de maneciila del lado derecho
	glVertex2f(7, 19);//vertice de maneciila del lado derecho

	glVertex2f(7, 17);//vertice de maneciila del lado derecho
	glVertex2f(7, 19);//vertice de maneciila del lado derecho

	glEnd();//cierra la estructura del trazado de lineas ();



    //---circulo de manecilla---
	glPointSize(5);//Propiedad glut que permite definir el tamaño de los puntos que para el caso sera el de la curva a trazar
	glBegin(GL_POINTS);//Lllamado de primitiva que permite crear Puntos individuales aislados para que se unan con el trazado de la curva

	for(i=-60 ; i<240 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;//aplicando el valor de la variable angulo con la ecuacion del trazado de cruva en radianes
		r = 2;
		x = r*cos(angulo);
		y = r*sin(angulo)+18;
		glColor3f(128,0,0);//color marron
		glVertex2f(x,  y);

	}

	glEnd();//cierra la estructura del trazado de lineas ();

	//------------------------Tuberia

	glBegin(GL_LINES);

	glVertex2f(-4, 10);
	glVertex2f(-4, 8);

	glEnd();//cierra la estructura del trazado de lineas ();

	//sem-circulo-izquierdo-concabo hacia bajo

	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=270 ; i<360 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 5;
		x = r*cos(angulo)-9;
		y = r*sin(angulo)+8;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//sem-circulo-izquierdo-concabo hacia arriba

	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=90 ; i<180 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 8;
		x = r*cos(angulo)-9;
		y = r*sin(angulo)-5;
		glColor3f(128,0,0);//color rojo
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//--------
	glBegin(GL_LINES);

	glVertex2f(-17, -5);
	glVertex2f(-17, -7);

	glVertex2f(-17, -7);
	glVertex2f(-11, -7);

	glVertex2f(-11, -7);
	glVertex2f(-11, -5);

	glEnd();//cierra la estructura del trazado de lineas ();

	//----------
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=90 ; i<180 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 2;
		x = r*cos(angulo)-9;
		y = r*sin(angulo)-5;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//----
	glBegin(GL_LINES);

	glVertex2f(-9, -3);
	glVertex2f(-4, -3);

	glEnd();//cierra la estructura del trazado de lineas ();

	//-----
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=60 ; i<90 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 2;
		x = r*cos(angulo)-4;
		y = r*sin(angulo)-5;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//-----------
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=185 ; i<355 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 3;
		x = r*cos(angulo);
		y = r*sin(angulo)-3;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//-----
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=90 ; i<120 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 2;
		x = r*cos(angulo)+4;
		y = r*sin(angulo)-5;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//------
	glBegin(GL_LINES);

	glVertex2f(4, -3);
	glVertex2f(13.3, -3);

	glEnd();//cierra la estructura del trazado de lineas ();

	//-----
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=30 ; i<90 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 2;
		x = r*cos(angulo)+13.3;
		y = r*sin(angulo)-5;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//-----
	glBegin(GL_LINES);

	glVertex2f(15, -4);
	glVertex2f(17, -4);

	glVertex2f(17, -4);
	glVertex2f(17, 4);

	glVertex2f(15, 4);
	glVertex2f(17, 4);

	glEnd();//cierra la estructura del trazado de lineas ();

	//-----
	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=270 ; i<330 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		r = 2;
		x = r*cos(angulo)+13.3;
		y = r*sin(angulo)+5;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//----
	glBegin(GL_LINES);

	glVertex2f(8.5, 3);
	glVertex2f(13.3, 3);

	glEnd();//cierra la estructura del trazado de lineas ();

	//sem-circulo-derecho-concabo hacia bajo

	glPointSize(1);
	glBegin(GL_POINTS);

	for(i=180 ; i<270 ; i+=0.01)//circulo exterior El comando glFlush causa la ejecución de cualquier comando que quede en espera en la pila.
	{
		angulo = i*M_PI/180;
		r = 5;
		x = r*cos(angulo)+9;
		y = r*sin(angulo)+8;
		glColor3f(128,0,0);//color
		glVertex2f(x,  y);

	}
	glEnd();//cierra la estructura del trazado de lineas ();

	//-------
	glBegin(GL_LINES);

	glVertex2f(4, 10);
	glVertex2f(4, 8);

	glEnd();//cierra la estructura del trazado de lineas ();//cierra la estructura del trazado de lineas

glFlush();// El comando glFlush causa la ejecución de cualquier comando que quede en espera en la pila.

}
void init (void)//inicializacion del metodo init que permitira activar y definir estados de visualizacion de pantalla
{
    glMatrixMode(GL_PROJECTION);//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glLoadIdentity();//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glOrtho(-20.0, 20.0, -10.0, 22.0, -1.0, 1.0);//define una perspectiva ortonormal.
                                                //Esto quiere decir que lo que se ves será una proyección paralela en uno de los planos definidos
                                                //por los ejes. Los parámetros sirven para delimitar el volumen de vista y son,
                                                //por este orden: x_mínima, x_máxima, y_mínima, y_máxima, z_mínima, z_máxima,
}
int main(int argc, char** argv)//la funcion que permite contar argumentos "argc = argumentos count"
                              //la funcion que permite almacenar parametros "argv = argumentos variable"
{
    glutInit(&argc, argv);// Esta función es la que inicializa la GLUT y negocia con el sistema de ventanas para abrir una.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//Define el modo en el que debe dibujar en la ventana.
    glutInitWindowSize (900, 700);  //ancho y alto de la nueva ventana
    glutInitWindowPosition (300, 100);//Posición x e y de la esquina superior izquierda de la nueva ventana, con respecto al escritorio en el que se trabaje
    glutCreateWindow ("CHORRO");
    init ();//En esta función, que hemos definido, activamos y definimos una serie de estados de ogl, antes de pasar el control del programa a la GLUT.
    glutDisplayFunc(display);//Aquí se define el primer callback.
                            //La función pasada como parámetro será llamada cada vez que GLUT determine oportuno que la ventana debe ser redibujada,
                            //como al maximizarse, poner otras ventanas por encima y después quitarlas, etc.
    glutMainLoop();//Esta función cede el control del flujo del programa a GLUT que, a partir de estos “eventos”,
                  //irá llamando a las funciones que han sido pasadas como callbacks.
    return 0;
}
