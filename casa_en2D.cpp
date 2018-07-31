//RAUL ERNESTO PERDOMO COREAS PC14046
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
int i=10;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.6f;




void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);

    // EJES   X
    glLineWidth(1);
    glBegin(GL_LINES);
      glColor3f( 0.1, 0.87, 0.51 );
    glVertex3f(  -1.5, 0.0, 0.0 );
    glVertex3f(  1.5, 0.0, 0.0 );
      glEnd();
      // EJE Y
       glBegin(GL_LINES);
      glColor3f( 0.97, 0.51, 1.0 );
    glVertex3f(  0.0, -1.5, 0.0 );
    glVertex3f(  0.0, 1.5, 0.0 );
      glEnd();

        // EJE z
       glBegin(GL_LINES);
      glColor3f( 0.66, 1.0, 0.51 );
    glVertex3f(  0.0, 0.0, 1.5 );
    glVertex3f(  0.0, 0.0, -1.5 );
      glEnd();




       // PARED DERECHA
  glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.0, 0.0, 0.0 );
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glVertex3f(  0.0, 0.8, 0.0 );
   glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.0, 0.8, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glVertex3f(  0.4, 1.1, 0.0 );
   glEnd();


    // PARED ATRAS
  glBegin(GL_POLYGON);
   glColor3f( 0.2, 0.17, 0.51 );
   glVertex3f(  0.0, 0.0, 0.0 );
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.0, 0.8, -0.8 );
   glVertex3f(  0.0, 0.8, 0.0 );
   glEnd();

      // PARED IZQU
  glBegin(GL_POLYGON);
  glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.8, 0.0, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.0, 0.8, -0.8 );
   glEnd();

    glBegin(GL_POLYGON);
   glVertex3f(  0.0, 0.8, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.4, 1.1, -0.8 );
   glEnd();

   // PARED FRENTE
  glBegin(GL_POLYGON);
  glColor3f( 0.2, 0.6, 0.0 );
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  0.8, 0.0, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glEnd();

  // TECHO MAYOR
   glBegin(GL_POLYGON);
  glColor3f( 1, 0.5, 0 );


   glVertex3f(  -0.05, 0.79, -0.85 );
   glVertex3f(  0.4, 1.1, -0.85 );

   glVertex3f(  0.4, 1.1, 0.05 );
   glVertex3f(  -0.05, 0.79, 0.05 );
   glEnd();


  glBegin(GL_POLYGON);
  glColor3f( 1, 0.5, 0 );
   glVertex3f(  0.4, 1.1, -0.85 );
   glVertex3f(  0.85, 0.79, -0.85 );
   glVertex3f(  0.85, 0.79, 0.05 );
   glVertex3f(  0.4, 1.1, 0.05 );



   glEnd();

  // CHIMENEA
    glPushMatrix ();
    glColor3f( 0.5, 0.0, 0.9 );
    glTranslatef (0.4, 1.1, -0.4);
    glRotatef(0.0, 0.0, 0.0, 0.0);
    glutSolidCube (0.1);
    glPopMatrix ();




    // COSTADO SALIDO ALV ***********************************************************************
     // PARED FRENTE
  glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.7, 0.2 );
   glVertex3f(  1.0, 0.0, 0.0 );
   glVertex3f(  1.0, 0.0, -0.5 );
   glVertex3f(  1.0, 0.8, -0.5 );
   glVertex3f(  1.0, 1.0, -0.25 );
   glVertex3f(  1.0, 0.8, 0.0 );
   glEnd();

    // PARED DERECHA
    glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  1.0, 0.0, 0.0 );
   glVertex3f(  1.0, 0.8, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glEnd();

    // PARED IZQU
   glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.8, 0.0, -0.50 );
   glVertex3f(  1.0, 0.0, -0.50 );
   glVertex3f(  1.0, 0.8, -0.50 );
   glVertex3f(  0.8, 0.8, -0.50 );
   glEnd();


 /// ------------------------------ COCHERA ---------------------------------


  // PARED IZQU
  glBegin(GL_POLYGON);
 glColor3f( 0.1, 0.87, 0.51 );
   glVertex3f(  0.0, 0.0, -1.2 );
   glVertex3f(  0.7, 0.0, -1.2 );
   glVertex3f(  0.7, 0.3, -1.2 );
   glVertex3f(  0.0, 0.3, -1.2 );
   glEnd();

   // PARED ATRAS
  glBegin(GL_POLYGON);
   glColor3f( 0.2, 0.17, 0.51 );
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.0, 0.0, -1.2 );
   glVertex3f(  0.0, 0.3, -1.2 );
   glVertex3f(  0.0, 0.3, -0.8 );
   glEnd();

   // PARED FRENTE TRIANGULO
  glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.7, 0.2 );
   glVertex3f(  0.70, 0.3, -0.8 );
   glVertex3f(  0.70, 0.4, -1.0);
   glVertex3f(  0.70, 0.3, -1.2 );
   glEnd();

   // PARED ATRAS TRIANGULO
  glBegin(GL_POLYGON);
   glColor3f( 0.1, 0.7, 0.2 );
   glVertex3f(  0.0, 0.3, -0.8 );
   glVertex3f(  0.0, 0.4, -1.0);
   glVertex3f(  0.0, 0.3, -1.2 );
   glEnd();



     // PARED FRENTE
  glBegin(GL_POLYGON);
   glColor3f( 0.5, 0.7, 0.2 );
   glVertex3f(  0.7, 0.0, -0.8 );
   glVertex3f(  0.7, 0.0, -0.85 );
   glVertex3f(  0.7, 0.3, -0.85 );
   glVertex3f(  0.7, 0.3, -0.8 );
   glEnd();


    glBegin(GL_POLYGON);
   glColor3f( 0.5, 0.7, 0.52 );
   glVertex3f(  0.7, 0.0, -1.15 );
   glVertex3f(  0.7, 0.0, -1.2 );
   glVertex3f(  0.7, 0.3, -1.2 );
   glVertex3f(  0.7, 0.3, -1.15 );
   glEnd();

   // PUERTA COCHERA

   glBegin(GL_POLYGON);
   glColor3f( 0.8, 0.7, 0.9 );


   glVertex3f(  0.7, 0.3, -1.15 );
   glVertex3f(  0.9, 0.15, -1.15 );

   glVertex3f(  0.9, 0.15, -0.85 );
   glVertex3f(  0.7, 0.3, -0.85 );
   glEnd();


   // TECHO COCHERA

   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );


   glVertex3f(  -0.03, 0.29, -1.22 );
   glVertex3f(  0.72, 0.29, -1.22 );

   glVertex3f(  0.72, 0.4, -1.0 );
   glVertex3f(  -0.03, 0.4, -1.0 );
   glEnd();

   glBegin(GL_POLYGON);
glColor3f( 1, 0.5, 0 );


   glVertex3f(  -0.03, 0.3, -0.80 );
   glVertex3f(  0.72, 0.3, -0.8);

   glVertex3f(  0.72, 0.4, -1.0 );
   glVertex3f(  -0.03, 0.4, -1.0 );
   glEnd();



   // TECHO salido

   glBegin(GL_POLYGON);
  glColor3f( 1, 0.5, 0.4 );


   glVertex3f(  0.4, 0.79, -0.5 );
   glVertex3f(  1.02, 0.79, -0.5 );

   glVertex3f(  1.02, 1.0, -0.25 );
   glVertex3f(  0.4, 1.0, -0.25 );
   glEnd();

   glBegin(GL_POLYGON);
  glColor3f( 1, 0.5, 0.4 );

   glVertex3f(  0.4, 0.79, 0.0 );
   glVertex3f(  1.02, 0.79, 0.0);

   glVertex3f(  1.02, 1.0, -0.25 );
   glVertex3f(  0.4, 1.0, -0.25 );
   glEnd();

  ///----------------------*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-VENTANAS *-*-*-*-*-*-*--------------

   glLineWidth(1.5);


  // VENTANA COCHERA
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.5, 0.1, -1.21 );
   glVertex3f(  0.6, 0.1, -1.21 );
   glVertex3f(  0.6, 0.2, -1.21 );
   glVertex3f(  0.5, 0.2, -1.21 );
   glEnd();


     glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0 );
   glVertex3f(  0.5, 0.1, -1.21 );
   glVertex3f(  0.6, 0.1, -1.21 );
   glVertex3f(  0.6, 0.2, -1.21 );
   glVertex3f(  0.5, 0.2, -1.21 );
   glEnd();



    // VENTANAS PARED IZQU
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.4, 0.6, -0.81 );
   glVertex3f(  0.6, 0.6, -0.81 );
   glVertex3f(  0.6, 0.8, -0.81 );
   glVertex3f(  0.4, 0.8, -0.81 );
   glEnd();

     glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   glVertex3f(  0.4, 0.6, -0.81 );
   glVertex3f(  0.6, 0.6, -0.81 );
   glVertex3f(  0.6, 0.8, -0.81 );
   glVertex3f(  0.4, 0.8, -0.81 );
   glEnd();

  glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );

   glVertex3f(  0.5, 0.6, -0.81 );
   glVertex3f(  0.5, 0.8, -0.81 );
   glEnd();

    glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.1, 0.6, -0.81 );
   glVertex3f(  0.3, 0.6, -0.81 );
   glVertex3f(  0.3, 0.8, -0.81 );
   glVertex3f(  0.1, 0.8, -0.81 );
   glEnd();

    glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   glVertex3f(  0.1, 0.6, -0.81 );
   glVertex3f(  0.3, 0.6, -0.81 );
   glVertex3f(  0.3, 0.8, -0.81 );
   glVertex3f(  0.1, 0.8, -0.81 );
   glEnd();

    glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );

   glVertex3f(  0.2, 0.6, -0.81 );
   glVertex3f(  0.2, 0.8, -0.81 );
   glEnd();

   // PARED FRENTE SALIDO VENTANA  PRIMERA PLANTA
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  1.01, 0.1, -0.1 );
   glVertex3f(  1.01, 0.1, -0.4 );
   glVertex3f(  1.01, 0.3, -0.4 );
   glVertex3f(  1.01, 0.3, -0.1 );
   glEnd();




    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.1 );
   glVertex3f(  1.01, 0.1, -0.4 );
   glVertex3f(  1.01, 0.3, -0.4 );
   glVertex3f(  1.01, 0.3, -0.1 );
   glEnd();

    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.3 );
   glVertex3f(  1.01, 0.3, -0.3 );
   glEnd();
       glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.2 );
   glVertex3f(  1.01, 0.3, -0.2 );
   glEnd();


    // PARED FRENTE SALIDO VENTANA  SEGUNDA PLANTA
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  1.01, 0.5, -0.1 );
   glVertex3f(  1.01, 0.5, -0.4 );
   glVertex3f(  1.01, 0.7, -0.4 );
   glVertex3f(  1.01, 0.7, -0.1 );
   glEnd();


    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.1 );
   glVertex3f(  1.01, 0.5, -0.4 );
   glVertex3f(  1.01, 0.7, -0.4 );
   glVertex3f(  1.01, 0.7, -0.1 );
   glEnd();

    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.3 );
   glVertex3f(  1.01, 0.7, -0.3 );
   glEnd();
       glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.2 );
   glVertex3f(  1.01, 0.7, -0.2 );
   glEnd();

    // VENTANA FRENTE ARRIBA DE PUERTA
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.81, 0.5, -0.55 );
   glVertex3f(  0.81, 0.5, -0.75 );
   glVertex3f(  0.81, 0.7, -0.75 );
   glVertex3f(  0.81, 0.7, -0.55 );
   glEnd();


    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  0.81, 0.5, -0.55 );
   glVertex3f(  0.81, 0.5, -0.75 );
   glVertex3f(  0.81, 0.7, -0.75 );
   glVertex3f(  0.81, 0.7, -0.55 );
   glEnd();




    //      PUERTA
  glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.81, 0.05, -0.60 );
   glVertex3f(  0.81, 0.05, -0.70 );
   glVertex3f(  0.81, 0.35, -0.70 );
   glVertex3f(  0.81, 0.35, -0.60 );
   glEnd();


    glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  0.81, 0.05, -0.60 );
   glVertex3f(  0.81, 0.05, -0.70 );
   glVertex3f(  0.81, 0.35, -0.70 );
   glVertex3f(  0.81, 0.35, -0.60 );
   glEnd();


     // RAMPA ARRIBA DE PUERTA

   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );


   glVertex3f(  0.7, 0.40, -0.70 );
   glVertex3f(  0.9, 0.30, -0.70 );

   glVertex3f(  0.9, 0.30, -0.60 );
   glVertex3f(  0.7, 0.40, -0.60 );
   glEnd();



    glFlush();
    glutSwapBuffers();








}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 5;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 5;

    //  Solicitar actualización de visualización
    glutPostRedisplay();

}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.5;
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
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}


 void init (void){
	glClearColor(0.0, 0.5, 0.8, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);


    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Ejercicio N 6");
    init();

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
