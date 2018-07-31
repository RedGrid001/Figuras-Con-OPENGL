#include <stdio.h> // Llamado de las funciones estandar de la libreria c++ en donde se obtienen todos los datos basicos de los trazados
#include <GL/gl.h> //En la primer parte del código estan los #includes que indican al compilador que debe incluir otros archivos fuentes o librerias.
#include <GL/glut.h>//En la primer parte del código estan los #includes que indican al compilador que debe incluir otros archivos fuentes o librerias
 
//Definición de las variables
double rotate_x=0; //Definicion de variables para rotar con teclas especiales y trazar coordenadas en el plano X
double rotate_y=0; //Definicion de variables para rotar con teclas especiales y trazar coordenadas en el plano Y
double rotate_z=0; //Definicion de variables para rotar con teclas especiales y trazar coordenadas en el plano Z
 
GLfloat X = 0.0f; //Definicion de coordenadas en el espacion de manera decimal para una mayor precision en X Sabiendo aplicar un buen calculo
GLfloat Y = 0.0f; //Definicion de coordenadas en el espacion de manera decimal para una mayor precision en Y Sabiendo aplicar un buen calculo
GLfloat Z = 0.0f; //Definicion de coordenadas en el espacion de manera decimal para una mayor precision en Z Sabiendo aplicar un buen calculo
GLfloat scale = 1.0f; //Define la variable que servira en la escala de rotacion y al mismo tiempo en el menu de agrandado de la figura tanto al hacer zoom como el desplazamiento de la misma
void cubo() //Aqui empieza el metodo deconstruccion del cubo a partir de cada una de sus caras
{
 // Primera cara, se identica por multiples colores
    glBegin(GL_POLYGON); //"esta funcion permite crear diferentes poligonos que van desde cuadrado hasta ractangulos"
    glColor3f( 1.0, 1.0, 1.0 ); //definicion de color BLANCO en uno de los lados del cubo con la colaboracion de la libreria glut
    glVertex3f(  0.3, -0.3, -0.3 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 ); //definicion de color AMARILLO en uno de los lados del cubo con la colaboracion de la libreria glut
    glVertex3f(  0.3,  0.3, -0.3 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 ); //definicion de color AZUL en uno de los lados del cubo con la colaboracion de la libreria glut
    glVertex3f( -0.3,  0.3, -0.3 );      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 ); //definicion de color ROJO en uno de los lados del cubo con la colaboracion de la libreria glut
    glVertex3f( -0.3, -0.3, -0.3 );      // V4 rojo
 
    glEnd(); //Finalizacion de las primeras coordenadas del trazado de caras
 
    // LADO TRASERO: lado blanco dibujado
    glBegin(GL_POLYGON); //"esta funcion permite crear diferentes poligonos que van desde cuadrado hasta ractangulos"
    glColor3f( 1.0,  1.0, 1.0 ); //definicion del color de la cara blanca del cubo
    glVertex3f( 0.3, -0.3, 0.3 );//dibujo del primer vertice de la cara blanca en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f( 0.3,  0.3, 0.3 );//dibujo del segundo vertice de la cara blanca en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f(-0.3,  0.3, 0.3 );//dibujo del tercer vertice de la cara blanca en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f(-0.3, -0.3, 0.3 );//dibujo del cuarto vertice de la cara blanca en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glEnd(); //Cierre de la utilizacion de las librerias glut
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);//"esta funcion permite crear diferentes poligonos que van desde cuadrado hasta ractangulos"
    glColor3f( 0.0,  1.0,  0.0 ); //definicion del color de la cara verde del cubo
    glVertex3f(0.3, -0.3, -0.3 ); //dibujo del primer vertice de la cara verde en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f(0.3,  0.3, -0.3 ); //dibujo del segundo vertice de la cara verde en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f(0.3,  0.3,  0.3 ); //dibujo del tercer vertice de la cara verde en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glVertex3f(0.3, -0.3,  0.3 ); //dibujo del cuarto vertice de la cara verde en "XYZ" por medio de la libreria de trazado de glut la cual grafica un vertice o linea
    glEnd(); //Cierre de la utilizacion de las librerias glut en este lado del cubo
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3,  0.3,  0.3 );
    glVertex3f(-0.3,  0.3, -0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3,  0.3,  0.3 );
    glVertex3f(0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3,  0.3 );
    glEnd();
 
    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();	
    
	}

void display()//es en donde se abren el conjunto de instrucciones que permitira manejar las configuraciones del monitor de los diferentes puntos para poder ubicar exactamente cada punto
{
	glMatrixMode(GL_PROJECTION); //Aplica las operaciones de matriz subsiguientes a la pila de la matriz de proyección.
	glLoadIdentity(); ////funcion que permite cargar la identificacion de proyeccion aplicando las coordenadas que establece la vista ortogonal
	glOrtho(-1, 1, -1, 1, -1, 1);//definicion de la vista ortogonal de acuerdo a las condiciones left o izquierda, right o derecha, bottom o parte del fondo , top o parte de arriba, near o cerca
	glMatrixMode(GL_MODELVIEW); //inicio de la matriz que permitira utilizar la funcion de vista de 2 puntos y de definicion de proporciones
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //permita esta funcion cargar de nuevo las configuraciones predeterminadas cada vez que se ejecute el programa del cubo
 
    // Resetear transformaciones
    glLoadIdentity(); //al iniciar la secuencia de teclado comienza en base a la vista que se configuro de la camara
    glViewport(0, 0, 400,400); //permite establecer que la ventana siempre mantenga la simetría no en si que dependa de una coordenadas definidas, es decir que no importa la resolución del monitor el objeto siempre tiene que mantener la proporción.
    gluLookAt(0.1, 0.0, 0.0, 0.0, -0.1, -0.1, 0.0, 0.1, 0.0); //función crea 2 puntos de interés en la vista que esta brindando la camara que para el caso sera la vistade 3 PLANOS
    glRotatef( rotate_x, 1.0, 0.0, 0.0 ); //inicia una rutina de rotacion en base a las coordenadas dadas de X con las variables inicializadas al inicio
    glRotatef( rotate_y, 0.0, 1.0, 0.0 ); //inicia una rutina de rotacion en base a las coordenadas dadas de Y con las variables inicializadas al inicio
    glRotatef( rotate_z, 0.0, 0.0, 1.0 ); //inicia una rutina de rotacion en base a las coordenadas dadas de Z con las variables inicializadas al inicio
    glTranslatef(X, Y, Z); //multiplica la matriz con los desplazamientos indicados en x, y y z que se le indican
 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale); //se usa esta funcion para poder aumetar o disminuir las dimensiones del cubo con las teclas especiales que se usan en el menu mas adelante
    cubo(); //Llamado de la función que dibuja el cubo en el plano o la funcion void que se inicio unas o varias lineas arriba
    
    glFlush(); //esta instruccion obliga a pintar y no espera a que el hardawre termine para continuar con el  programa es decir define las capas de colores en cada cara del cubo
    glutSwapBuffers(); //Permite intercambiar las capas de colores a la hora de la rotacion permitiendo a las diferentes caras rotar sin problemas de fallo en el color en otras palabras es la RAM del dibujo
 
}

 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y ) //Definicion del metodo que permitira hacer uso de las teclas especiales del teclado definiendo variables de tecla y de coordenada en x y y
{
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT) //uso de la tecla derecha y tipo de rotacion que realizara al momento de hacer uso de la misma
        rotate_y += 7; //rotacion en y en escala de 7
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT) //uso de la tecla izquierda y tipo de rotacion que realizara al momento de hacer uso de la misma
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP) //uso de la tecla arriba o superior y tipo de rotacion que realizara al momento de hacer uso de la misma
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN) //uso de la tecla inferior o de abajo y tipo de rotacion que realizara al momento de hacer uso de la misma
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2) ////uso de la tecla de funcion f2 y tipo de rotacion que realizara al momento de hacer uso de la misma al momento de rotar en Z
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización en base a la funcion de la libreria de glut
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z. se usa switch por ser multiples casos de ejecucion con el mismo usuario
    switch (key)
    {
    case 's':
        scale=0.5; //aqui empieza el uso de la declaracion de variables iniciales para la definicionde escaladas
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 27:
        exit(0);			// exit, por medio de la tecla ESC
    }
    glutPostRedisplay();     //  Solicitar actualización de visualización en base a la funcion de la libreria de glut
}
 
 
 
int main(int argc, char* argv[]) //inicializacion del metodo que define estableces la cantidad de parametros que ejecutara el programa por cada compilacion y los asteriscos simbolizan algo asi como mas de 1 argumento por ventana
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//permite establecer el modo de visualizacion inicail que tendra el programa el glut_single establece una mascara de bits para seleccionar una sola ventana en un buffer y el grb permite establecer un parametro para colocar un nombre al programa ejecutable o trazo ya compilado
    glutInitWindowSize (500, 500);//funcion que permite definir el tamaño de la ventana a la hora de la compilacion que realizara el make
    glutInitWindowPosition (0, 0);//funcion que permite definir la posicion de la ventana a la hora de la compilacion que realizara el make es decir permite por medio de coordenadas si se quiere una ubicacion centrada o por costados ya definidos
    //"a esta parte se ha cambiado el parametro de la posicion de la ventana en la cual se probo la posicion 200px, 150px confirmando que la ventana se ubica mas hacia la izquierda" 
    //"luego de esto las coordenadas 300px y 300 px permiten centralizar la ventana"
    // Crear ventana
    glutCreateWindow("Cubo controlado por teclas");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutDisplayFunc(display); //permite la retrollamada de la pantalla
    glutKeyboardFunc(keyboard); //permite la retrollamada del teclado
    glutSpecialFunc(specialKeys); //permite la retrollamada de las teclas especiales
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();//Esta función provocará que todas las funciones GLUT que controlan funciones, se repitan cuando sea necesario o mejor dicho cada vez que se notifique, es decir, es un bucle inteligente, en otras palabras, es darle a refresh al control sobre el programa.
 
    // Regresar al sistema operativo
    return 0;
 
}
