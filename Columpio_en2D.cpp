//RAUL ERNESTO PERDOMO COREAS PC14046
#include <GL/gl.h>//libreria para el reconocimiento de parametros glut de configuracion
#include <GL/glut.h>//libreria para la construccion de elementosd e vistas glut
//incluimos la libreria math para poder utilizar las funciones matematicas
#include <math.h>//libreria matematica para poder desarrollar ecuaciones para el trazado de figuras geometricas
void display(void)////funcion para la proyeccion en pantalla
{
	glClearColor(0,0,0,0);//color amarillo que se proyecta en la consola
	glClear(GL_COLOR_BUFFER_BIT);////Ajusta el área de plano binario de la ventana a los valores previamente seleccionados

//FIGURA DE COLUMPIO-----------------------------------------------------------


glLineWidth(10);//elemento de libreria glut que permite establecer el tamaño en pixeles de las lineas
    // columnas vertice izquierdo izq
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados//Primitiva de opengl que permitira conectar segmentos de recta para la construccion
													//de la estructura del columpio son conectados y cerrados
		glColor3f(0, 255, 0);//asignacion de color verde para el contorno de los columpio
    glVertex2f(0.0f,3.0f);//vertice izquierd de columna COLUMPIO
    glVertex2f(0.0f,9.0f);//vertice superior inicial izquierdo de columna comlumpio
    glVertex2f(2.0f,11.0f);//vertice superior final izquierdo de columna comlumpio
    glVertex2f(2.0f,5.0f);//vertice inferior final izquierdo de columna comlumpio
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();//termina las intrucciones de la primitiva para comenzar el trazado de lineas
    // columna superior del vertice del centro
    glBegin(GL_LINE_STRIP);//primitiva de opengl que permite conectar segmentos de recta//primitiva de opengl que permite conectar segmentos de recta

    glVertex2f(4.0f,2.3f);//vertice inicial inferior del centro
    glVertex2f(4.0f,8.3f);//vertice inicial superior del centro
    glVertex2f(6.0f,10.3f);//vertice inicial superior del centro
    glVertex2f(6.0f,4.3f);//vertice inicial inferior del centro
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();//termina las intrucciones de la primitiva para comenzar el trazado de lineas
    // columnas vertice derecho
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados//primitiva que permite la construccion de segmentos de rectas conectado y cerrado
													//para el trazado de las columnas superiores de la estructura
    glVertex2f(16.0f,2.6f);//vertice inferior derecho
    glVertex2f(14.0f,0.6f);//vertice inferior inicial derecho
    glVertex2f(15.0f,11.6f);//vertice superior derecho
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

    // columnas horizontal superior
    glBegin(GL_LINES);//primitiva que permite definir cada par de puntos a una sola recta//primitiva que permite definir cada par de puntos a una sola recta
    glVertex2f(1.0f,13.0f);//TRAZADO DE LA RECTA SUPERIIOR INICIAL
    glVertex2f(15.0f,11.6f);//TRAZADO DE LA RECTA SUPERIIOR FINAL
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();//

    // columnas horizontales de arriba
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados//primitiva que permite el trazado de segmentos de recta conectados y cerrados
    glVertex2f(4.0f,8.3f);//punto inicial  de las columnas superior que conecta a la rampa
    glVertex2f(6.0f,10.3f);//punto secundario inferior de la columna SUPERIOR
    glVertex2f(2.0f,11.0f);//punto secundario del la columna superior del
    glVertex2f(0.0f,9.0f);//vertice que cierra el trazado de la linea arriba lado derecho
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();
    // columnas horiz abajo es decir segunda columna
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados
    glVertex2f(4.0f,5.3f);//vertice 1
    glVertex2f(6.0f,7.3f);//vertice 2
    glVertex2f(2.0f,8.0f);//vertice 3
    glVertex2f(0.0f,6.0f);//vertice 4
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

		glColor3f(255, 255, 255);//definicion del color verde para el contorno de Los comlumpio
		    // suelo
		    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados
				glColor3f(0, 255, 0);//color verde de los segmentos trazados
		    glVertex2f(0.0f,3.0f);//vertice inicial inferior del suelo
		    glVertex2f(2.0f,5.0f);//vertice final inicial del inferior del suelo
		    glVertex2f(16.0f,2.6f);//vertice inicial del inferior del suelo
		    glVertex2f(14.0f,0.6f);//vertice izquierdo del inferior del suelo donde se cierran las lineas
		    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

    // RAMPA comparte orientacion con jes positivos y negativos
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados
    glVertex2f(0.0f,6.0f);//vertice superior de la rampa
    glVertex2f(4.0f,5.3f);//vertice superior de la rampa
    glVertex2f(1.3f,-0.9f);//vertice inferior de la rampa
    glVertex2f(-2.3f,0.0f);//vertice inferior de la rampa
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();
    // TRIANGULO IZQ
		glBegin(GL_LINE_STRIP);//primitiva de opengl que permite conectar segmentos de recta
		glVertex2f(0.0f,9.0f);//PUNTO INICIAL DEL TRIANGULO SUPERIOR IZQUIERDO
    glVertex2f(1.0f,13.0f);//punto secuencial del triangulo superior izquierdo
    glVertex2f(2.0f,11.0f);//punto secuencial del triangulo superior izquierdo y con el que se cierrra el trazado de la linea
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

     // TRIANGULO superior derecho EL MAS GRANDE
    glBegin(GL_LINE_STRIP);//primitiva de opengl que permite conectar segmentos de recta
    glVertex2f(4.0f,8.3f);//vertice inferior del triangulo izquierdo
    glVertex2f(5.0f,12.6f);//vertice superior del triangulo izquierdo
    glVertex2f(6.0f,10.3f);//vertice inferior del triangulo izquierdo
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();


    // columpio izq
    //linea izq
    glBegin(GL_LINES);//primitiva que permite definir cada par de puntos a una sola recta//
		glColor3f(255, 0, 0);//COLOR VERDE
    glVertex2f(7.0f,12.4f);
    glVertex2f(7.0f,4.65f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();
    //linea der
    glBegin(GL_LINES);//primitiva que permite definir cada par de puntos a una sola recta
    glVertex2f(9.0f,12.2f);
    glVertex2f(9.0f,4.35f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();
    //tabla
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados
    glVertex2f(6.9f,4.6f);
    glVertex2f(7.1f,4.7f);
    glVertex2f(9.1f,4.4f);
    glVertex2f(8.9f,4.3f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

    // columpio der
    //linea izq
		glColor3f(255, 0, 0);
    glBegin(GL_LINES);//primitiva que permite definir cada par de puntos a una sola recta
    glVertex2f(11.1f,12.0f);
    glVertex2f(11.1f,4.05f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();
    //linea der
    glBegin(GL_LINES);//primitiva que permite definir cada par de puntos a una sola recta
    glVertex2f(13.1f,11.8f);
    glVertex2f(13.1f,3.75f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

    //tabla
    glBegin(GL_LINE_LOOP);//primitiva que permite el trazado de segmentos de recta conectados y cerrados
    glVertex2f(11.0f,4.0f);
    glVertex2f(11.2f,4.1f);
    glVertex2f(13.2f,3.8f);
    glVertex2f(13.0f,3.7f);
    glEnd();//termina las intrucciones de la primitiva para comenzar el trazado de lineas();

    glFlush ();//causa la ejecución de cualquier comando que quede en espera en la pila.



}
void init (void)//metodo que permite establecer las propiedades de visualizacion
{
    glMatrixMode(GL_PROJECTION);//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glLoadIdentity();//Con esto cargamos en la matriz actual la matriz identidad (equivale a resetear la matriz).
    glOrtho(-4, 17, -2.0, 15.0, -1.0, 1.0);//define una perspectiva ortonormal.
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
    glutCreateWindow ("COLUMPIO");
    init ();//En esta función, que hemos definido, activamos y definimos una serie de estados de ogl, antes de pasar el control del programa a la GLUT.
    glutDisplayFunc(display);//Aquí se define el primer callback.
                            //La función pasada como parámetro será llamada cada vez que GLUT determine oportuno que la ventana debe ser redibujada,
                            //como al maximizarse, poner otras ventanas por encima y después quitarlas, etc.
    glutMainLoop();//Esta función cede el control del flujo del programa a GLUT que, a partir de estos “eventos”,
                  //irá llamando a las funciones que han sido pasadas como callbacks.
    return 0;
}
