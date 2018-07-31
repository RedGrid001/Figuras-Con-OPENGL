////*************DESARROLLADO POR RAUL PERDOMO***************//////
#include <GL/gl.h>//libreria para el reconocimiento de parametros glut de configuracion
#include <GL/glut.h>//libreria para la construccion de elementosd e vistas glut
#include <iostream>
#include <SOIL/SOIL.h>//LIBRERIA QUE NOS PERMITE CARGAR LAS DIFERENTES TEXTURAS
using namespace std;
double rotate_y=30;//Se define una variable global de rotacion de todo el plano en y para poder girar toda la figura creada
double rotate_x=35;//Se define una variable global de rotacion de todo el plano en x para poder girar toda la figura creada
double rotate_z=0;//Se define una variable global de rotacion de todo el plano en z para poder girar toda la figura creada
GLfloat X = 0.0f;//declaracion de variable mayuscula
GLfloat Y = 0.0f;//declaracion de variable mayuscula
GLfloat Z = 0.0f;//declaracion de variable mayuscula
GLfloat scale = 1.0f;//
GLint ancho = 800;
GLint alto = 600;
GLuint texture[0];//se declara la variable que permitira cargar las diferentes texturas que se estaran creando
GLfloat light_Ambient [4] = { 20.0, 20.0, 20.0, 20.0};//se define la intensidad de la luz ambiental
GLfloat light_Diffuse [4] = { 10.0, 10.0, 10.0, 10.0};//se define la intensidad de la luz difusa
GLfloat light_Position[4] = {-10.0,-10.0,-10.0,0.0};//se define la posicion dela luz

void luces(void)//se crea una funcion que permita definir los parametros necesario para la ilumincaion
{
        glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT0, GL_POSITION, light_Position );
}

void display()
{
  glClearColor(0, 0, 0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Resetear transformaciones
  glLoadIdentity();
  // Rotar en el eje X,Y y Z
  glRotatef( rotate_x, 15, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, -38.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 0.0 );

  //glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
  // Otras transformaciones

  glScalef(scale, scale, scale);
  texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE EL SUELO
                            (
                  "../piso.bmp",
                  SOIL_LOAD_AUTO,
                  SOIL_CREATE_NEW_ID,
                  SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE LA PARED DE LA VENTANA
                            (
                  "../verde(1).jpg",
                  SOIL_LOAD_AUTO,
                  SOIL_CREATE_NEW_ID,
                  SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                           );

texture[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE LA PARED QUE ESTA AL FONDO DONDE ESTA EL SILLON
																					(
																"../rojo.png",
																SOIL_LOAD_AUTO,
																SOIL_CREATE_NEW_ID,
																SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
																					);
texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE LA VENTANA FRANCESA
                                          (
                                "../ventana.jpg",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                          );
texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DEL SILLON
                                          (
                                "../gris(1).jpg",
                                 SOIL_LOAD_AUTO,
                                SOIL_CREATE_NEW_ID,
                                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | GL_TEXTURE_3D
                                           );
texture[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DEL RESPALDO O COJIN DEL SILLON
                                           (
                                "../rojo(1).jpg",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                          );
texture[6] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE LA MESA
                                          (
                                 "../madera(1).jpg",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                          );
texture[7] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DEL MANTEL DE LA MESA
                                          (
                                  "../mantel.bmp",
                                   SOIL_LOAD_AUTO,
                                   SOIL_CREATE_NEW_ID,
                                   SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                          );
////*************************************************************************************///////
/*SE TRAZARON TRES LINEAS PARA QUE SIRVIESEN DE GUIA PARA EL TRAZADO DEPAREDES CON EL QUAD PROPORCIONADO/
////*************************************************************************************///////
// EJES   X
//glPushMatrix();
//glTranslatef(15,-38,0);
  glLineWidth(1);
  glBegin(GL_LINES);
  glColor3f( 0.1, 0.87, 0.51 );
  glVertex3f(  0.0, 0.0, 0.0 );
  glVertex3f(  4.0, 0.0, 0.0 );
  glEnd();
// EJE Y
  glBegin(GL_LINES);
  glLineWidth(5);
  glColor3f( 0.97, 0.51, 1.0 );
  glVertex3f(  0.0, 0.0, 0.0 );
  glVertex3f(  0.0, 4.0, 0.0 );
  glEnd();
// EJE z
  glBegin(GL_LINES);
  glColor3f( 0.66, 1.0, 0.51 );
  glVertex3f(  0.0, 0.0, 4.0 );
  glVertex3f(  0.0, 0.0, 0.0 );
  glEnd();
  ////*************************************************************************************///////
  /*SE FINALIZA EL TRAZADO DE TRES LINEAS PARA QUE SIRVIESEN DE GUIA PARA EL TRAZADO DEPAREDES CON EL QUAD PROPORCIONADO/
  ////*************************************************************************************///////
  ////*************************************************************************************///////
  /*SE EMPIEZA EL TRAZADO DE LA PARED LATERAL QUE ESTARA ENTRE EL EJE X e Y /
  ////*************************************************************************************///////
//Pared ventana
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[1]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);

glTexCoord2f(0,0); glVertex3f(0.0,0.0,0.0);
glTexCoord2f(1,0); glVertex3f(0.0,4.0,0.0);
glTexCoord2f(1,1); glVertex3f(4.0,4.0,0.0);
glTexCoord2f(0,1); glVertex3f(4.0,0.0,0.0);
glEnd();
////*************************************************************************************///////
/*SE FINALIZA EL TRAZADO DE LA PARED LATERAL QUE ESTARA ENTRE EL EJE X e Y /
////*************************************************************************************///////
////*************************************************************************************///////
/*SE EMPIEZA EL TRAZADO DE LA primitiva LATERAL QUE CREARA EL POLIGONO PARA TEXTURIZAR LA VENTANA QUE ESTARA ENTRE EL EJE X e Y /
////*************************************************************************************///////
//ventana
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[3]);
glBegin(GL_POLYGON);
glTexCoord2f(0,0); glVertex3f(1.0,2.0,0.01);
glTexCoord2f(1,0); glVertex3f(1.0,3.0,0.01);
glTexCoord2f(1,1); glVertex3f(3.0,3.0,0.01);
glTexCoord2f(0,1); glVertex3f(3.0,2.0,0.01);
glEnd();
///*************************************************************************************///////
/*SE FINALIZA EL TRAZADO DE LA primitiva LATERAL QUE CREARA EL POLIGONO PARA TEXTURIZAR LA VENTANA QUE ESTARA ENTRE EL EJE X e Y /
////*************************************************************************************///////
//Pared fondo sillon
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[2]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f, 4.0f, 4.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f, 4.0f);
glEnd();



//SUELO DE COLOR VERDE
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[0]);
glBegin(GL_QUADS);
glNormal3f( 0.0f, 0.0f,1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 0.0f, 0.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 4.0f, 0.0f,4.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f, 4.0f);
glEnd();
///////*****************************************************////////////////////////////////
//sillon parte atras izquierdo 1
glBegin(GL_POLYGON);
glVertex3f(0.01,0.0,3.0);
glVertex3f(0.01,2.0,3.0);
glVertex3f(0.01,2.0,3.5);
glVertex3f(0.01,0.0,3.5);
glEnd();
//sillon lateral izquierdo 1
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,0.0,3.5);
glTexCoord2f(1,1); glVertex3f(1.0,0.0,3.5);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,3.5);
glTexCoord2f(0,0); glVertex3f(0.0,2.0,3.5);
glEnd();

//sillon lateral izquierdo 1
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(1.0,0.0,3.0);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,3.0);
glTexCoord2f(0,0); glVertex3f(0.0,2.0,3.0);
glEnd();
//sillon frente lateral izquierdo 1
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(1.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,3.0);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,3.5);
glTexCoord2f(0,0); glVertex3f(1.0,0.0,3.5);
glEnd();
//sillon cara aerea laterial izquierdo 1
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,2.0,3.0);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,3.0);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,3.5);
glTexCoord2f(0,0); glVertex3f(0.0,2.0,3.5);
glEnd();
///********************************************************************////
///********************************************************************////
//sillon lateral derecho fondo 2
glBegin(GL_POLYGON);
glVertex3f(0.01,0.0,1.0);
glVertex3f(0.01,2.0,1.0);
glVertex3f(0.01,2.0,1.55);
glVertex3f(0.01,0.0,1.55);
glEnd();
//sillon lateral derecho lateral derecho 2
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,2.0,1.0);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,1.0);
glTexCoord2f(0,1); glVertex3f(1.0,0.0,1.0);
glTexCoord2f(0,0); glVertex3f(0.0,0.0,1.0);
glEnd();
//sillon lateral derecho lateral izquierdo 2
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,2.0,1.55);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,1.55);
glTexCoord2f(0,1); glVertex3f(1.0,0.0,1.55);
glTexCoord2f(0,0); glVertex3f(0.0,0.0,1.55);
glEnd();
//sillon frente lateral izquierdo 2
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(1.0,0.0,1.0);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,1.0);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,1.55);
glTexCoord2f(0,0); glVertex3f(1.0,0.0,1.55);
glEnd();
//sillon cara superior lateral izquierdo 2
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(0.0,2.0,1.0);
glTexCoord2f(1,1); glVertex3f(1.0,2.0,1.0);
glTexCoord2f(0,1); glVertex3f(1.0,2.0,1.55);
glTexCoord2f(0,0); glVertex3f(0.0,2.0,1.55);
glEnd();
/////*****************************************///////////////
///////***************************************//////////////
//SILLON PARTE DE EN MEDIO FONDO CON Pared
glBegin(GL_POLYGON);
glVertex3f(0.01,0.0,1.55);
glVertex3f(0.01,0.0,3.0);
glVertex3f(0.01,1.5,3.0);
glVertex3f(0.01,1.5,1.55);
glEnd();
//SILLON FRENTE PARTE DE EN MEDIO
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glBegin(GL_POLYGON);
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1,0); glVertex3f(1.0,0.0,1.55);
glTexCoord2f(1,1); glVertex3f(1.0,0.0,3.0);
glTexCoord2f(0,1); glVertex3f(1.0,1.5,3.0);
glTexCoord2f(0,0); glVertex3f(1.0,1.5,1.55);
glEnd();
//sSILLON CARA AEREA PARTE DE EN MEDIO
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[4]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);

glTexCoord2f(1,0); glVertex3f(0.0,1.5,1.55);
glTexCoord2f(1,1); glVertex3f(1.0,1.5,1.55);
glTexCoord2f(0,1); glVertex3f(1.0,1.5,3.0);
glTexCoord2f(0,0); glVertex3f(0.0,1.5,3.0);
glEnd();
/////*****************************************///////////////
///////***************************************//////////////
//sILLON almohada PARTE DE EN  MEDIO pegado a la pared
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[5]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(0.01,0.0,1.55);
glTexCoord2f(1,1); glVertex3f(0.01,2.0,1.55);
glTexCoord2f(0,1); glVertex3f(0.01,2.0,3.0);
glTexCoord2f(0,0); glVertex3f(0.01,0.0,3.0);
glEnd();
//Sillon parte de en medio pegado a la pared frontal
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[5]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(0.5,0.0,1.55);
glTexCoord2f(1,1); glVertex3f(0.5,2.0,1.55);
glTexCoord2f(0,1); glVertex3f(0.5,2.0,3.0);
glTexCoord2f(0,0); glVertex3f(0.5,0.0,3.0);
glEnd();
//Sillon parte de en medio pegado a la paren cara superior o aerea
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[5]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(0.0,2.0,1.55);
glTexCoord2f(1,1); glVertex3f(0.5,2.0,1.55);
glTexCoord2f(0,1); glVertex3f(0.5,2.0,3.0);
glTexCoord2f(0,0); glVertex3f(0.0,2.0,3.0);
glEnd();
//////*****************************************//////////////////
/*comienza hacer la mesa*/
/////******************************************/////////////////
//mantel de la mesa
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[7]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.8,1.55,1.1);
glTexCoord2f(1,1); glVertex3f(2.8,1.55,2.8);
glTexCoord2f(0,1); glVertex3f(2.2,1.55,2.8);
glTexCoord2f(0,0); glVertex3f(2.2,1.55,1.1);
glEnd();
//mesa tablero largo superior
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.5,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.5,3.0);
glTexCoord2f(0,1); glVertex3f(2.0,1.5,3.0);
glTexCoord2f(0,0); glVertex3f(2.0,1.5,0.9);
glEnd();
//Mesa tablero lado izquierdo del borde
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.5,3.0);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(2.0,1.5,3.0);
glEnd();
//Mesa tablero lado frontal del borde
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.5,3.0);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(0,0); glVertex3f(3.0,1.5,0.9);
glEnd();
//Mesa tablero lado lateral derecho del borde
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.5,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,0.9);
glTexCoord2f(0,0); glVertex3f(2.0,1.5,0.9);
glEnd();
//Mesa tablero lado trasero del borde
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.0,1.5,3.0);
glTexCoord2f(1,1); glVertex3f(2.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,0.9);
glTexCoord2f(0,0); glVertex3f(2.0,1.5,0.9);
glEnd();
//mesa tablero largo inferior
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(2.0,1.3,0.9);
glEnd();
////************************************************////
/*PATAS DE MESA*/
////************************************************////
//tapa primera pata
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.3,2.8);
glTexCoord2f(1,1); glVertex3f(2.8,1.3,2.8);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(3.0,1.3,3.0);
glEnd();
//Patas de mesa ES LA PATA IZQUIERA LATERAL IZQUIERDA
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,3.0);
glEnd();
///otra PARTE pata izquierda
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(3.0,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(3.0,0.0,2.8);
glEnd();
///otra PARTE pata IZQUIErda
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,2.8);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,2.8);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,2.8);
glEnd();
///OTRA PARTE pata izquierda
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.8,0.0,2.8);
glTexCoord2f(1,1); glVertex3f(2.8,1.3,2.8);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,3.0);
glEnd();
//sello superior pata
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,1.3,0.9);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,1.1);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.0,1.3,0.9);
glEnd();
//pata izquierda pegada al sillon trasera
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,0.9);
glTexCoord2f(0,0); glVertex3f(2.0,0.0,0.9);
glEnd();
//pata izquierda pegada al sillon trasera
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,0.0,1.1);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,1.1);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.0,0.0,1.1);
glEnd();
//pata izquierda pegada al sillon trasera
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.2,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.2,0.0,1.1);
glEnd();
///
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.0,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(2.0,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.0,0.0,1.1);
glEnd();
//////******termina pta izquierda del lado del asiento
///********empieza pata derecha del lado del aciento**********////////
//sello superior pata
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,1.3,3.0);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,2.8);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(2.0,1.3,3.0);
glEnd();
//pata derecha
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(2.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.2,1.3,3.0);
glTexCoord2f(0,0); glVertex3f(2.2,0.0,3.0);
glEnd();
///
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.0,0.0,2.8);
glTexCoord2f(1,1); glVertex3f(2.0,1.3,2.8);
glTexCoord2f(0,1); glVertex3f(2.2,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(2.2,0.0,2.8);
glEnd();
////
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.2,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(2.2,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.2,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(2.2,0.0,2.8);
glEnd();
/////
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.0,0.0,3.0);
glTexCoord2f(1,1); glVertex3f(2.0,1.3,3.0);
glTexCoord2f(0,1); glVertex3f(2.0,1.3,2.8);
glTexCoord2f(0,0); glVertex3f(2.0,0.0,2.8);
glEnd();
///********TERMINA pata derecha del lado del aciento**********////////
///********empieza pata IZQUIERDA del lado del FRENTE**********////////
///
//sello superior pata
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,1.1);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.8,1.3,0.9);
glEnd();
//pata izquierda frontal
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,0.9);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,0.9);
glEnd();
//
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,1.1);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,1.1);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,1.1);
glEnd();
//
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(3.0,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(3.0,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(3.0,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(3.0,0.0,1.1);
glEnd();
////
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);
glNormal3f( 0.0f, 0.0f,-1.0f);
glBegin(GL_POLYGON);
glTexCoord2f(1,0); glVertex3f(2.8,0.0,0.9);
glTexCoord2f(1,1); glVertex3f(2.8,1.3,0.9);
glTexCoord2f(0,1); glVertex3f(2.8,1.3,1.1);
glTexCoord2f(0,0); glVertex3f(2.8,0.0,1.1);
glEnd();
//glPopMatrix();
std::cout<<"puntos en x "<<rotate_x;
std::cout<<"puntos en y "<<rotate_y;
std::cout<<"puntos en z "<<rotate_z<<endl;
glDisable(GL_TEXTURE_2D);
    glFlush();
    glutSwapBuffers();
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

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
	glDisable(GL_TEXTURE_2D);
    ////  Flecha derecha: aumentar rotación 7 grados
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
void reshape (int w, int h)
{
	glViewport(0, 0,(GLsizei) w,(GLsizei) h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-7, 7, -7, 7, -7, 7);
 //glViewport(0, 0, 100,100); //permite establecer que la ventana siempre mantenga la simetría no en si que dependa de una coordenadas definidas, es decir que no importa la resolución del monitor el objeto siempre tiene que mantener la proporción.
 //gluLookAt(5.0, 5.0, 5.0, 5.0, 4.1, 0.0, 0.0, -5.1, 0.0);
 glMatrixMode(GL_MODELVIEW);


 ancho = w;
 alto = h;


}
// void init (void){
//
//   glEnable(GL_TEXTURE_2D);//PERMITE HABILIRAR LAS TEXTURAS
//   glShadeModel(GL_SMOOTH);
//
//  //glClearColor(0.0, 0.5, 0.8, 0.0);
//  //glClearDepth(1.0f);
//  glEnable(GL_DEPTH_TEST);
//  glDepthFunc(GL_LEQUAL);
//  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//  glDepthFunc(GL_LESS); //comparación de profundidad
//  glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
//
//  //activa la luz
//
//    glClear(GL_COLOR_BUFFER_BIT);
//     glOrtho(-6, 6, -6, 6, -5, 5);
//     //gluLookAt(-5,5,-5,5,-5,5,-3,3,4);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
// }

int main(int argc, char* argv[])
{

   //  Inicializar los parámetros GLUT y de usuario proceso
   glutInit(&argc,argv);


   // Solicitar ventana con color real y doble buffer con Z-buffer
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (0, 0);
   // Crear ventana
   glutCreateWindow("CUARTO EN 3D");
   // init();

   // Habilitar la prueba de profundidad de Z-buffer
   glEnable(GL_DEPTH_TEST);
   luces();
   // Funciones de retrollamadahttps://www.facebook.com/beatryzz.hernandezz/videos/1734985896581463/
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeys);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glShadeModel(GL_SMOOTH);
   // Pasar el control de eventos a GLUT
   glutMainLoop();

   // Regresar al sistema operativo
   return 0;

}
