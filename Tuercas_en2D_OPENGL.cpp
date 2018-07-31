//RAUL ERNESTO PERDOMO COREAS PC14046
#include <GL/gl.h>//libreria para el reconocimiento de parametros glut de configuracion
#include <GL/glut.h>//libreria para la construccion de elementosd e vistas glut
//incluimos la libreria math para poder utilizar las funciones matematicas
#include <math.h>//libreria matematica para poder desarrollar ecuaciones para el trazado de figuras geometricas
void display(void)////funcion para la proyeccion en pantalla
{
    glClearColor(0, 0, 255,1);//color azul que se proyecta en la consola
    glClear(GL_COLOR_BUFFER_BIT);////Ajusta el área de plano binario de la ventana a los valores previamente seleccionados

	//TRAZADO DE FIGURA

	float x, y, r, i;//DECLARACION DE VARIABLES QUE SE UTILIZARAN PARA EL TRAZADO DE CIRCUNFERENCIAS
	GLfloat angulo;//VARIABLE DE DIBUJADO GLUT QUE PERMITIRA IR DANDOLE VALOES AL ANGULO

  //-----Engranaje derecho
    //anillo
  glPointSize(10);//propiedad de opengl que permite aumento del tamaño de las tuercas todas al mismo tamaño de 10//propiedad de opengl que permite aumento del tamaño de las tuercas todas al mismo tamaño de 10
  glBegin(GL_POINTS);//Primitiva que permite conectar puntos individuales aislados//Primitiva que permite conectar puntos individuales aislados

  for(i=0 ; i<360 ; i+=0.01)//circulo exterior
  {
    angulo = i*M_PI/180;
    for(r=1.5 ;r<2.4; r+=0.01)//definicion del radio de la circunferencia en el plano
    {
    x = r*cos(angulo)+4.8;
    y = r*sin(angulo)-0.4;
    glColor3f(255, 0, 0);//color rojo para todo el engranaje
    glVertex2f(x,  y);//construcion en x y y como variables de trazado//construcion en x y y como variables de trazado
    }
  }
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
    //----Dientes
  //Diente derecho numero 1
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                      //conectados entresi
  glVertex2f(4.4, 2.8);
  glVertex2f(5.1, 2.8);
  glVertex2f(5.3, 1.9);
  glVertex2f(4.2, 1.9);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //Diente derecho numero 2
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(5.7, 1.8);
  glVertex2f(6.5, 2.3);
  glVertex2f(6.9, 2.0);
  glVertex2f(6.6, 1.2);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //Diente derecho numero 3
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entre si
  glVertex2f(6.8, 0.8);
  glVertex2f(7.7, 0.9);
  glVertex2f(7.9, 0.3);
  glVertex2f(7.2, -0.1);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //Diente derecho numero 4
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(7.2, -0.6);
  glVertex2f(7.8, -1.1);
  glVertex2f(7.6, -1.6);
  glVertex2f(6.8, -1.6);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //Diente derecho numero 5
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(6.4, -1.9);
  glVertex2f(6.7, -2.6);
  glVertex2f(6.2, -2.9);
  glVertex2f(5.6, -2.4);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //DIente derecho numero 6
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(4.2, -2.5);
  glVertex2f(4.4, -3.3);
  glVertex2f(5.1, -3.3);
  glVertex2f(5.2, -2.5);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //DIente derecho numero 7
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(2.9, -1.6);
  glVertex2f(2.6, -2.4);
  glVertex2f(3.0, -2.7);
  glVertex2f(3.7, -2.3);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //DIente derecho numero 8
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(2.4, -0.5);
  glVertex2f(1.7, -0.9);
  glVertex2f(1.9, -1.5);
  glVertex2f(2.9, -1.4);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //DIente derecho numero 9
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(2.8, 0.9);
  glVertex2f(2.0, 0.9);
  glVertex2f(1.8, 0.4);
  glVertex2f(2.4, 0.0);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
  //diente derecho numero 10
  glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
  glVertex2f(3.8, 1.8);
  glVertex2f(3.1, 2.3);
  glVertex2f(2.6, 2.0);
  glVertex2f(2.9, 1.1);
  glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()

	//-----CIrculo del centro o Engranaje central
		//anillo
	glPointSize(10);//propiedad de opengl que permite aumento del tamaño de las tuercas todas al mismo tamaño de 10
	glBegin(GL_POINTS);//Primitiva que permite conectar puntos individuales aislados

	for(i=0 ; i<360 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;//definicion de valores a tomar por parte de la circunferencia
		for(r=1.5 ;r<2.4; r+=0.01)//rangode parametros para trazado en x
		{
		x = r*cos(angulo)-0.5;//calculo en base al coseno
		y = r*sin(angulo)+2.4;//calculo en base al seno
		glColor3f(0.0f,0.0f,0.0f);//color negro
		glVertex2f(x,  y);//construcion en x y y como variables de trazado
		}
	}
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()

		//dientes
	//diente del centro numero 1
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-0.8, 5.5);
	glVertex2f(-0.1, 5.5);
	glVertex2f(0.1, 4.6);
	glVertex2f(-1.0, 4.6);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 2
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(0.6, 4.5);
	glVertex2f(1.3, 4.9);
	glVertex2f(1.7, 4.6);
	glVertex2f(1.4, 3.8);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 3
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(1.6, 3.4);
	glVertex2f(2.5, 3.5);
	glVertex2f(2.7, 2.9);
	glVertex2f(1.9, 2.5);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 4
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(1.8, 2.0);
	glVertex2f(2.6, 1.5);
	glVertex2f(2.4, 1.0);
	glVertex2f(1.4, 1.0);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 5
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(1.2, 0.7);
	glVertex2f(1.5, 0.0);
	glVertex2f(1.0, -0.3);
	glVertex2f(0.1, 0.7);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 6
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-1.0, 0.1);
	glVertex2f(-0.8, -0.6);
	glVertex2f(-0.2, -0.6);
	glVertex2f(0.0, 0.1);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 7
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-2.3, 1.0);
	glVertex2f(-2.6, 0.2);
	glVertex2f(-2.2, -0.1);
	glVertex2f(-1.5, 0.3);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 8
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-2.8, 2.1);
	glVertex2f(-3.5, 1.7);
	glVertex2f(-3.3, 1.1);
	glVertex2f(-2.6, 1.2);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 9
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-2.5, 3.5);
	glVertex2f(-3.2, 3.5);
	glVertex2f(-3.4, 3);
	glVertex2f(-2.8, 2.6);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del centro numero 10
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-1.5, 4.5);
	glVertex2f(-2.1, 4.9);
	glVertex2f(-2.6, 4.6);
	glVertex2f(-2.3, 3.9);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()




  //-----Engranaje izquierdo trazado a partir de un circulo
		//anillo
	glPointSize(10);//propiedad de opengl que permite aumento del tamaño de las tuercas todas al mismo tamaño de 10
	glBegin(GL_POINTS);//Primitiva que permite conectar puntos individuales aislados

	for(i=0 ; i<360 ; i+=0.01)//circulo exterior
	{
		angulo = i*M_PI/180;
		for(r=1.5 ;r<2.4; r+=0.01)
		{
		x = r*cos(angulo)-4.7;
		y = r*sin(angulo)-1.6;
		glColor3f(0.0f,1.0f,0.0f);//color
		glVertex2f(x,  y);//construcion en x y y como variables de trazado
		}
	}
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()

		//dientes
	//diente del engranaje izquierdo numero 1
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-5.1, 1.5);
	glVertex2f(-4.4, 1.5);
	glVertex2f(-4.2, 0.6);
	glVertex2f(-5.3, 0.6);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 2
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-3.7, 0.5);
	glVertex2f(-3.0, 0.9);
	glVertex2f(-2.6, 0.6);
	glVertex2f(-2.9, -0.2);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 3
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-2.7, -0.6);
	glVertex2f(-1.8, -0.5);
	glVertex2f(-1.6, -1.1);
	glVertex2f(-2.3, -1.5);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 4
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-2.3, -2.0);
	glVertex2f(-1.7, -2.5);
	glVertex2f(-1.9, -3.0);
	glVertex2f(-2.7, -3.0);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 5
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-3.1, -3.3);
	glVertex2f(-2.8, -4.0);
	glVertex2f(-3.3, -4.3);
	glVertex2f(-3.9, -3.8);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 6
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-5.3, -3.9);
	glVertex2f(-5.1, -4.6);
	glVertex2f(-4.5, -4.6);
	glVertex2f(-4.3, -3.9);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 7
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-6.6, -3.0);
	glVertex2f(-6.9, -3.8);
	glVertex2f(-6.5, -4.1);
	glVertex2f(-5.8, -3.7);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 8
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-7.1, -1.9);
	glVertex2f(-7.8, -2.3);
	glVertex2f(-7.6, -2.9);
	glVertex2f(-6.6, -2.8);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 9
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-6.8, -0.5);
	glVertex2f(-7.5, -0.5);
	glVertex2f(-7.7, -1.0);
	glVertex2f(-7.1, -1.4);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()
	//diente del engranaje izquierdo numero 10
	glBegin(GL_POLYGON);//primitiva de opengl que permite crear un poligono en base a segmentos de recta
                    //conectados entresi
	glVertex2f(-5.8, 0.5);
	glVertex2f(-6.4, 0.9);
	glVertex2f(-6.9, 0.6);
	glVertex2f(-6.6, -0.1);
	glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()

glFlush();//causa la ejecución de cualquier comando que quede en espera en la pila.



}
void init (void)
{
  glMatrixMode(GL_PROJECTION);//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
  glLoadIdentity();//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glOrtho(-8.0, 8.0, -6.0, 6.0, -1.0, 1.0);//define una perspectiva ortonormal.
                                                //Esto quiere decir que lo que se ves será una proyección paralela en uno de los planos definidos
                                                //por los ejes. Los parámetros sirven para delimitar el volumen de vista y son,
                                                //por este orden: x_mínima, x_máxima, y_mínima, y_máxima, z_mínima, z_máxima,
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);// Esta función es la que inicializa la GLUT y negocia con el sistema de ventanas para abrir una.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//Define el modo en el que debe dibujar en la ventana.
  glutInitWindowSize (900, 700);  //ancho y alto de la nueva ventana
  glutInitWindowPosition (300, 100);//Posición x e y de la esquina superior izquierda de la nueva ventana, con respecto al escritorio en el que se trabaje
  glutCreateWindow ("TUERCAS");
  init ();//En esta función, que hemos definido, activamos y definimos una serie de estados de ogl, antes de pasar el control del programa a la GLUT.
  glutDisplayFunc(display);//Aquí se define el primer callback.
                          //La función pasada como parámetro será llamada cada vez que GLUT determine oportuno que la ventana debe ser redibujada,
                          //como al maximizarse, poner otras ventanas por encima y después quitarlas, etc.
  glutMainLoop();//Esta función cede el control del flujo del programa a GLUT que, a partir de estos “eventos”,
                //irá llamando a las funciones que han sido pasadas como callbacks.
    return 0;
}
