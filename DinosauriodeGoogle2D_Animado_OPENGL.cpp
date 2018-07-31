#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#define RUTA_AUDIO "overworld.wav" //nombre del archivo de audio
using namespace std;


GLuint texture[0];
float escala=0.2;
float angX=0.0f,angY=0.0f;
int ResX=800,ResY=600;
float posicionY=0;
float rotateY;
int frameNumber;
float aceX=0.0f,aceY=-0.001f;
float velX=0.01f,velY=0.0f;
float velY1=0.0f;
float posX=0.0f,posY=0.0f;



GLfloat X = 1;//direccion de movimiento en plano X si es en 1 se movera hacia la derecha
GLfloat W = 1;//direccion hacia donde se dibujaran los cuadros si es en 1 se dibujaran hacia deracha

GLfloat x=0; GLfloat y=0;
//
//Definición del modelo de una luz
GLfloat light_Ambient [4] = { 2, 2, 2, 1.0};
GLfloat light_Diffuse [4] = { 4.0, 4.0, 4.0, 1.0};
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_Position [4] = {0.0, 0.0, 10.0, 1.0};
//Definición de las caracteristicas opticas del material: coeficientes de reflexión
GLfloat GreenMaterial [4] = {1.0, 1.0, 0.0, 0.0 };
GLfloat whiteMaterial [4] = {1.0,1.0,1.0,0.0};
GLfloat blackMaterial [4] = {0,0,0,0};

// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 *stream, int len);

// variables para audio
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
static char label[100];
void dibujarCadena (char *s)
{
 unsigned int i;
 for (i = 0; i < strlen (s); i++)
 glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, s[i]);//recorre todas las fuentes el s{i}
}
void luces(void){
        glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_Position );
}
void cuadros(float x, float y,float z, float h, float w, float r, float g, float b) {
  //creacion de cuadros puntos x,y alto h, ancho w, color r,g,b
glColor3f(r,g,b);
glBegin(GL_POLYGON);
glVertex3f(x,y,z);//puntos iniciales
glVertex3f(x,y+h,z); //linea recta a 90 grados sumamos alto (h) a y
glVertex3f(x+w,y+h,z);//linea paralela al eje x le sumamos ancho (w) a 'x' y sumamos alto (h)a y
glVertex3f(x+w,y,z);//linea recta en angulo 0 sumamos ancho (w) a x
glEnd();//finalizacion de trazos

}
//La pelota
void pelota(){

    glPushMatrix();
    glTranslatef(rotateY+40,-2,1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,1);
    glVertex3f(0,2,1);
    glVertex3f(-1,2,1);
    glVertex3f(-1,0,1);
    glEnd();

//    glutSolidSphere(.5f,50,50);
    glPopMatrix();

}
void pelota2(){

    glPushMatrix();
      glTranslatef(rotateY+60,-2,1.0f);
        glutSolidSphere(.5f,50,50);
        glEnd();
        glPopMatrix();

}
void pelota3(){

    glPushMatrix();
      glTranslatef(rotateY+300,-2,1.0f);
        glutSolidSphere(0.5f,50,50);
        glEnd();
        glPopMatrix();

}
void escena(){

     glShadeModel (GL_FLAT); //Hace notar o suaviza los bordes
     glEnable(GL_LIGHTING); //Activa iluminación
     glEnable(GL_LIGHT0);
     glEnable(GL_DEPTH_TEST);

      luces();
    glPushMatrix();
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
       glTranslatef(rotateY,0,0.0f);
  texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture ES LA TEXTURA DE EL SUELO
                            (
                  "fondo.bmp",
                  SOIL_LOAD_AUTO,
                  SOIL_CREATE_NEW_ID,
                  SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                int posEscena = -7;
                for(int i=0;i<=100;i++){
                  glEnable(GL_TEXTURE_2D);
                  glBindTexture(GL_TEXTURE_2D, texture[0]);
                  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                  glBegin(GL_POLYGON);
                  glNormal3f( 0.0f, 0.0f,1.0f);

                  glTexCoord2f(1,0); glVertex3f(posEscena,-3,-1.5);
                  glTexCoord2f(1,1); glVertex3f(posEscena,6.0,-1.5);
                  glTexCoord2f(0,1); glVertex3f(posEscena+6,6.0,-1.5);
                  glTexCoord2f(0,0); glVertex3f(posEscena+6,-3.0,-1.5);
                  glEnd();
                  glDisable(GL_TEXTURE_2D);
                  posEscena +=6;
                }

                glPopMatrix();

glDisable(GL_LIGHTING); //Activa iluminación
glDisable(GL_LIGHT0);
glDisable(GL_DEPTH_TEST);
}

void dinosaurio(){


    glPushMatrix();
    glTranslatef(X-5.5,posicionY,0.0f);
    glRotatef(0,0,1,0);

  cuadros(x,y,0,0.4,0.8*W,0,0,0);
  	cuadros(x,y+0.4,0,0.9,1.5*W,0,0,0);


  	cuadros(x+0.2*W,y+1.3,0,0.2,1.1*W,0,0,0);
  	cuadros(x+0.8*W,y,0,0.2,0.5*W,0,0,0);
  	cuadros(x+0.2*W,y+0.9,0.001,0.2,0.2*W,1,1,1);//ojo

    cuadros(x-0.2*W,y-1.5,0,1.5,0.8*W,0,0,0);
    cuadros(x+.55*W,y-0.9,0,0.2,0.3*W,0,0,0);//mano
    cuadros(x+0.8*W,y-1.2,0,0.5,0.2*W,0,0,0);//mano
    cuadros(x-.3*W,y-1.7,0,1.4,0.8*W,0,0,0);
    cuadros(x-0.5*W,y-1.9,0,1.4,0.8*W,0,0,0);
    cuadros(x-0.7*W,y-2.1,0,1.4,0.8*W,0,0,0);
    //patas

    //cola
    cuadros(x-1.5*W,y-1.0,0,1,0.11*W,0,0,0);
    cuadros(x-1.45*W,y-1.3,0,1,0.25*W,0,0,0);
    cuadros(x-1.30*W,y-1.6,0,1,0.25*W,0,0,0);
    cuadros(x-1.20*W,y-1.7,0,1,0.25*W,0,0,0);
    cuadros(x-1.*W,y-1.8,0,1,0.3*W,0,0,0);

      glPopMatrix();

}
void patas(){

    glPushMatrix();
      glTranslatef(X-5.5,posicionY+posY,0.0f);


  cuadros(x-0.7*W,y-2.7,0,1.4,0.1*W,0,0,0);
  cuadros(x-0.7*W,y-2.7,0,0.2,0.2*W,0,0,0);
  cuadros(x-0.7*W,y-2.4,0,0.4,0.2*W,0,0,0);
  cuadros(x-0.55*W,y-2.3,0,0.4,0.15*W,0,0,0);

  cuadros(x-0.2*W,y-2.3,0,0.4,0.15*W,0,0,0);
  cuadros(x-0.1*W,y-2.7,0,1.4,0.1*W,0,0,0);
  cuadros(x-0.1*W,y-2.7,0,0.2,0.15*W,0,0,0);
  glPopMatrix();

}
// --------------- Para animación  ------------------------------------------

int animating = 0;      // 0 sin animación
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
        // Llamamo a la función para detener la animación
        animating = 0;
}

void updateFrame() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
        //Hacemos que la tetera gire
        for (float i=0; i<=1; i+=0.6) {
                rotateY-= i;
        }
        //Verificamos el numero de frames para detener animación
        if(frameNumber==1000)
        {
                pauseAnimation();
                //si se detiene la animacion detenemos el audio
                // SDL_PauseAudio(1);
                frameNumber=0;


        }
        if(rotateY <=-45 and rotateY>=-46 and posicionY==0){
          pauseAnimation();
           SDL_PauseAudio(1);
          frameNumber=0;
          rotateY=0;
        }else if (posicionY==0 and rotateY <=-65 and rotateY>=-66){
          pauseAnimation();
             SDL_PauseAudio(1);
          frameNumber=0;
          rotateY=0;
        }else if (posicionY==0 and rotateY <=-305 and rotateY>=-306){
          pauseAnimation();
             SDL_PauseAudio(1);
          frameNumber=0;
          rotateY=0;
        }
        //Almacenamos el numero de frames
        frameNumber++;


        printf ("Numero de Frame: %d \n", frameNumber);

        }

// float puntaje=frameNumber;

void timerFunction(int timerID) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating) {
                updateFrame();
                glutTimerFunc(30, timerFunction, 0);
                glutPostRedisplay();
        }
}

void startAnimation() {
        // llamamos la función para iniciar la animación
        if ( !animating ) {
                animating = 1;
                glutTimerFunc(600, timerFunction, 1);
        }
}



// ------------- Manejo de Teclado-----------------------------------------------
void text()
{

      char text[32];
    sprintf(text, "score:%d", frameNumber);
    glColor3f(0, 0, 0);
    glRasterPos3f( 0 , 0 , 1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
 }

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(1.000, 0.922, 0.804,0.1);
   glLoadIdentity();



   escena();
    dinosaurio();
    patas();

    pelota();
    pelota2();
    pelota3();
      text();

      glColor3f (0, 0, 255);
      dibujarCadena (label);
      sprintf (label, "Dinosaurio de Google");
      glRasterPos3f (-4.0F, 4.0F,5.0);
      dibujarCadena (label);
      sprintf (label, "Magaly-Mario-Raul-Edgar");
      glRasterPos3f (-4.0F, 3.0F,5.0);
      glEnd();

    glFlush();
	glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-7,7,-7,7,-7,7);
  // gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 0.5, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclado(unsigned char key, int x, int y){
        if (key =='+') {aceY+=-0.001f; }
        if (key =='-') {aceY-=0.001f; }
        if ( key == 27 && animating==1) {
                pauseAnimation();
               SDL_PauseAudio(1);
        }
        else
        {
                startAnimation();
              SDL_PauseAudio(0);
        }
        if(key=='q'){
           exit(0);
        }
}
//rebote
void animacion(void){

  velY+=-0.05f; posicionY+=velY;
  if(posicionY<0.0f){
    posicionY-=0.1f; velY*=0;
      if(velY<0.01f) {
          velY=0.0f;
          posicionY=0;
        }

}

velY1+=aceY; posY+=velY;
velX+=aceX; posX+=velX;
if(posY<0.0f){
  posY+=0.5f; velY1=0.8f;
    if(velY1<0.01f) {
        velX=0.0f; velY1=0.0f;
      }
  }


        glutPostRedisplay();
}

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT){
        X+= 0.2;
  // SDL_PauseAudio(1);
      }
      else{
          //SDL_PauseAudio(0);
      }
   if (key == GLUT_KEY_LEFT)
        X-= 0.2;
     if (key == GLUT_KEY_UP){
  //  W*= -1;
      posicionY=5;
    }
     if (key == GLUT_KEY_DOWN)
        W*= -1;
    glutPostRedisplay();

}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(1000, 600);//tamaño de la ventana
   glutInitWindowPosition(100, 100); //posicion
   glEnable(GL_TEXTURE_2D);
   // sonido
   // Inicializar SDL.
   if (SDL_Init(SDL_INIT_AUDIO) < 0)
           return 1;

   // Variables locales
   static Uint32 wav_length; // Longitud de nuestra muestra
   static Uint8 *wav_buffer; // Buffer que contiene nuestro archivo de audio
   static SDL_AudioSpec wav_spec; // Las especificaciones de nuestra pieza de música

   /* Cargar el WAV */
   // Las especificaciones, la longitud y el búfer de nuestro wav se llenan
   if( SDL_LoadWAV(RUTA_AUDIO, &wav_spec, &wav_buffer, &wav_length) == NULL )
   {
           return 1;
   }
   // Establecer la función de devolución de llamada
   wav_spec.callback = my_audio_callback;
   wav_spec.userdata = NULL;

   // Establecer nuestras variables estáticas globales
   audio_pos = wav_buffer; // Copia el buffer de sonido
   audio_len = wav_length; // Copia la longitud del archivo

   /*Abrir el dispositivo de audio */
   if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
   {
           fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
           exit(-1);
   }


   glutCreateWindow("Dinosaurio"); //titulo
   glutDisplayFunc(display);//dibuja la escena
   glutReshapeFunc(reshape);//recalcula el tamaño
   glutKeyboardFunc(teclado);
   glutIdleFunc(animacion);
     glutSpecialFunc(specialKeys);

     // Descomentar si queremos que la animación y el audio inicie al levantar el script
     // startAnimation();
     // /* Empezar a sonar */
     // SDL_PauseAudio(0);

   glutMainLoop();
   return 0;


//SDL_PauseAudio(0);
while ( audio_len > 0 )
{
        SDL_Delay(100); // espera un segundo para la pausa
}
SDL_CloseAudio();
SDL_FreeWAV(wav_buffer);

}

//Función de devolución de llamada de audio donde se recoren los valores del bufer
void my_audio_callback(void *userdata, Uint8 *stream, int len)
{

if (audio_len ==0)
        return;

len = ( len > audio_len ? audio_len : len );

SDL_memcpy (stream, audio_pos, len); // Simplemente copie desde un buffer en el otro
//SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro

audio_pos += len;
audio_len -= len;
}
