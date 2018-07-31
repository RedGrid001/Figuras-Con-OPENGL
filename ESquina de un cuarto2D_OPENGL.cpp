//RAUL ERNESTO PERDOMO COREAS PC14046
#include <GL/gl.h>//libreria para el reconocimiento de parametros glut de configuracion
#include <GL/glut.h>//libreria para la construccion de elementosd e vistas glut
//incluimos la libreria math para poder utilizar las funciones matematicas
#include <math.h>//libreria matematica para poder desarrollar ecuaciones para el trazado de figuras geometricas
void display(void)////funcion para la proyeccion en pantalla
{
    glClearColor(0, 0, 255,1.0);//color azul de la ventana
    glClear(GL_COLOR_BUFFER_BIT);/////Ajusta el área de plano binario de la ventana a los valores previamente seleccionados

	//TRAZADO DE FIGURA

	glColor3f(0,255,0);//color verde que ira alrededor del plano
    glPointSize(4);
    glBegin(GL_POINTS);
    float x,y,i,r;
    GLfloat angulo;//
for (i=0; i<180; i+=0.1) {//variable de invremento
  /* code */
  r=5;
  angulo=i*M_PI/180;
  x=r*cos(angulo)+5;
  y=r*sin(angulo)+5;
  glVertex2f(x,y);
}
glEnd();

glColor3f(0,255,0);//color verde que ira alrededor del plano
  glPointSize(4);
  glBegin(GL_POINTS);
for (i=0; i<360; i+=0.1) {//variable de invremento
/* code */
r=5;
angulo=i*M_PI/180;
x=r*cos(angulo)-5;
y=r*sin(angulo)-5;
glVertex2f(x,y);
}

    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas()


glFlush();//causa la ejecución de cualquier comando que quede en espera en la pila.

}
void init (void)
{
  glMatrixMode(GL_PROJECTION);//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
  glLoadIdentity();//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10, 10);//define una perspectiva ortonormal.
                                                //Esto quiere decir que lo que se ves será una proyección paralela en uno de los planos definidos
                                                //por los ejes. Los parámetros sirven para delimitar el volumen de vista y son,
                                                //por este orden: x_mínima, x_máxima, y_mínima, y_máxima, z_mínima, z_máxima,

glMatrixMode(GL_MODELVIEW);//permite el modelado de las matrices trazadas para cargar una vista frontal
glLoadIdentity();//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
//gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);//esta vista permite observar un objeto como si lo viéramos por una cámara que capta las imágenes.
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);// Esta función es la que inicializa la GLUT y negocia con el sistema de ventanas para abrir una.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//Define el modo en el que debe dibujar en la ventana.
  glutInitWindowSize (900, 700);  //ancho y alto de la nueva ventana
  glutInitWindowPosition (300, 100);//Posición x e y de la esquina superior izquierda de la nueva ventana, con respecto al escritorio en el que se trabaje
  glutCreateWindow ("ESQUINA DE CUARTO");
  init ();//En esta función, que hemos definido, activamos y definimos una serie de estados de ogl, antes de pasar el control del programa a la GLUT.
  glutDisplayFunc(display);//Aquí se define el primer callback.
                          //La función pasada como parámetro será llamada cada vez que GLUT determine oportuno que la ventana debe ser redibujada,
                          //como al maximizarse, poner otras ventanas por encima y después quitarlas, etc.
  glutMainLoop();//Esta función cede el control del flujo del programa a GLUT que, a partir de estos “eventos”,
                //irá llamando a las funciones que han sido pasadas como callbacks.
    return 0;
}
