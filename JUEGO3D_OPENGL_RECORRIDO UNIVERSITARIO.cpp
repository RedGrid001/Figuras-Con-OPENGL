#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <SDL2/SDL.h>
#include "SDL/SDL_mixer.h"
#include <SOIL/SOIL.h>
#include "img.cpp"


#define MOV_ARRIBA      1
#define MOV_ABAJO       2
#define MOV_IZQUIERDA   3
#define MOV_DERECHA     4
using namespace std;


//pantalla doble

int IdMain;
int IdSub;
int IdSubSub;
int IdSubSub2;

//la musica de fondo
Mix_Music *music = NULL;

//el efecto de sonido
Mix_Chunk *scratch = NULL;

Mix_Chunk *win= NULL;
//efecto de caminar de avatar
Mix_Chunk *walk= NULL;
//efecto error
Mix_Chunk *error = NULL;
//efecto tope
Mix_Chunk *tope = NULL;
//efecto recoger materias
Mix_Chunk *get= NULL;
// efecto cesped
Mix_Chunk *cesped=NULL;

/* Constantes para la luz */
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_spot_dir[] = { 10.0f, 10.0f, 0.0f};
const GLfloat light_attenuation[] = {1.0f};
GLfloat light_position[] =       { -100.0f, 50.0f, -100.0f, 0 };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


//posición para la camara
const GLfloat maxCamY = 200.0f, minCamY = 60.0f;
GLfloat camX,camY,camZ;
// variable para el movimiento de los objetos
double Z = 0;

//variable para usar textura
unsigned int textureID;

int xx[20],yy[20];
int fin=0;
float initX, initZ; //(initX,initZ) esquina superior izquierda de todo el mapa
int posX, posZ; //(posX,posZ) posición en la matriz actual del jugador
float xActual,zActual;
float rotx=0,roty=0;
int tamCubo=20,espacios=tamCubo/2;
const int altoMapa=40,largoMapa=20;
// 0 = espacio en donde circula el avatar
// 2 = avatar
// 3 = arboles
// 4 = carros
// 5 = edificio
// 6 = arbol paso al segundo nivele
// 7 = poste de luz
// 8 = arbusto
// 9 = avatar ayudante
// 10 = objeto lapizcero
// 11 = objeto lapiz
// 12 = borrador
// 13 = compas
// 14 = cuaderno grande
// 15 = hombrecito = avatar ayudante
// 16 = cuaderno pequenio indicador luego que recoger el objeto a buscar
// 17 = color Azul
// 18 = color rojo
// 19 = color Blanco
// 20 = color Negro
// 21 = color Amarillo

// variable donde se Almacenamos los puntos recolectados
float puntos =0;
// variable que indica cuando se mostrara el mensaje, estando en 0 el mensaje estara oculto
// estando en 1 el mensaje se mostrara
int mostrarmensaje[] ={0,0};

// matriz donde guardaremos las posiciones de los objetos que agarremos en la escena 1
int posicionesEscena1[5][2]={};
// matriz donde indicamos que el objeto ya lo ha obtenido, estando en 0 el objeto aun no lo a
// agarrado, estando el 1 el objeto ya esta guardado
int matiriaEscena1[5]={0,0,0,0,0};

// matriz donde guardaremos las posiciones de los objetos que agarremos en la escena 2
int posicionesEscena2[5][2]={};
// matriz donde indicamos que el objeto ya lo ha obtenido, estando en 0 el objeto aun no lo a
// agarrado, estando el 1 el objeto ya esta guardado
int matiriaEscena2[5]={0,0,0,0,0};

//variable donde almacenamos la cadena de texto que vamos a mostrar como mensaje
string mensajetexto;
//variable que utilizamos para el temporizador recoger la matriz matiriaEscena1 y si
//en todas las posición el valor es verdadero, solo se detendra el temporizador
//si al recorrer la matriz detecta un falso los objetos volveran a su lugar para recogerlos de nuevo
bool materiaOk =false;

#define PI 3.141592653

int start=1;
char str[]="00:00:00";
int ancho=128,alto=128;
double segs=1000,mins=60000,hrs=10;
int aseg=0,amin=0,ahr=0;
unsigned char * datos;

//variables para rotar
float rotateX, rotateY;

// matriz para indicar hacia donde esta viendo el avatar
int VistaPersonaje[]={1,0,0,0};

//diferentes mensaje para mostrar
string mensaje2 = "Muchas Felicidades has llegado al nivel dos, ahora tu mision sera reunir los colores en este orden, Azul, Rojo, Blanco, Negro, Amarillo";
string mensaje1 = "Bienvenido al mundo del estudio. Antes de seguir necesitas estar equipado, consigue un lapicero, un lapiz, un borrado, una compas y un cuaderno. Si consigues estos objetos en este orden podras pasar al siguiente nivel";
string mensaje3 = "Muchas Felicidades has recogido todos los colores que se te pidieron, estamos trabajando para tener mas niveles";


bool mostrarAyuda =true;


//matriz que nos servira para dibujar el mapa
int mapa[altoMapa][largoMapa] ={3,0,0,3,2,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,9,0,0,0,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,7,0,0,7,0,0,0,0,0,0,3,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,10,0,13,0,0,0,0,3,
                               3,4,0,3,0,0,3,0,0,0,0,0,0,8,0,0,0,0,0,3,
                               3,0,0,7,0,0,7,0,0,0,0,0,8,7,8,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,8,0,0,0,0,0,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,12,0,11,0,0,0,0,3,
                               3,0,4,3,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,4,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,4,0,3,0,0,3,0,14,0,3,3,3,3,3,3,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,3,3,3,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
                               3,8,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,8,0,8,8,8,8,8,0,0,0,0,0,0,8,8,8,3,3,3,//aqui
                               3,8,0,8,8,7,3,8,0,0,0,0,0,0,8,8,7,8,8,3,
                               3,8,0,8,8,8,8,8,0,0,0,0,0,0,8,8,8,8,8,3,
                               3,8,0,0,0,0,0,0,0,0,21,0,0,0,8,3,8,8,8,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,19,0,0,8,0,0,0,0,0,0,0,8,0,0,0,0,0,3,
                               3,0,0,0,8,7,8,0,0,0,0,0,8,7,8,0,0,0,0,3,
                               3,0,0,0,0,8,0,0,0,0,0,0,0,8,0,0,0,0,0,3,
                               3,0,0,0,0,0,0,0,7,0,7,0,0,0,0,0,0,20,0,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,5,5,0,0,0,5,5,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,5,5,5,0,5,5,5,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,5,5,5,0,5,5,5,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,3,
                               3,0,0,18,0,0,5,5,5,5,5,5,5,0,0,0,0,0,0,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,3,
                               3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
                               3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
                               };


int cubos[altoMapa][largoMapa][2];

//Esta función carga de la matriz inicial las coordenadas de todos los cubos
//con el fin de optimizar el proceso de dibujo

//inicia sdl
bool init_sdl() {
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //If everything initialized fine
    return true;
}


//carga los archivos
bool load_files_sdl(){
    //Load the music
    music = Mix_LoadMUS( "../audio/tema1.wav" );

    //If there was a problem loading the music
    if( music == NULL )
    {
        return false;
    }

    //Load the sound effects
    scratch = Mix_LoadWAV( "../audio/OOT_Navi_Hey1.wav" );

    //If there was a problem loading the sound effects
    if( ( scratch == NULL ) )
    {
        return false;
    }

    win = Mix_LoadWAV("../audio/puerta.wav");

    if (( win == NULL))
    {
      return false;
    }
    walk = Mix_LoadWAV("../audio/caminarPiso.wav");
    if (( walk == NULL))
    {
      return false;
    }
    error= Mix_LoadWAV("../audio/error.wav");

    if (( error == NULL))
    {
      return false;
    }
    tope= Mix_LoadWAV("../audio/caminarGrama.wav");

    if (( tope == NULL))
    {
      return false;
    }
    get= Mix_LoadWAV("../audio/get.wav");

    if (( get == NULL))
    {
      return false;
    }
    cesped= Mix_LoadWAV("../audio/caminarCesped.wav");

    if (( cesped == NULL))
    {
      return false;
    }

    //If everything loaded fine
    return true;
}


static char label[100];
void dibujarCadena (char *s)
{
 unsigned int i;
 for (i = 0; i < strlen (s); i++)
 glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}


void dibujaTexto(char * mensaje){
    while (*mensaje) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*mensaje++);
    }
}

void cronometro(void){
    glPushMatrix();
        glColor3f(1, 1, 1);
       // glTranslatef(10,10,0);
      glRotated(180,0,1,0);
        glScalef(0.007, 0.007, 1);
        str[0]=amin/10+'0';
        str[1]=amin%10+'0';
        str[3]=aseg/10+'0';
        str[4]=aseg%10+'0';
        str[6]=ahr/10+'0';
        str[7]=ahr%10+'0';
        dibujaTexto(&str[0]);
    glPopMatrix();
}



void parseCubos(){
    //(initX,initZ) es la esquina superior izquierda de todo el mapa
    initX = -(tamCubo*largoMapa)/2.0;
    initZ = -(tamCubo*altoMapa)/2.0;
    //cubos = new int[altoMapa][largoMapa][2]; // 2 coordenadas por cubo (esquina superior izquierda)
    for(int i=0;i<altoMapa;i++){
        for(int j=0;j<largoMapa;j++){
            cubos[i][j][0] = initX+(tamCubo*j);
            cubos[i][j][1] = initZ+(tamCubo*i);
            if(mapa[i][j]==2){
                posZ=i;
                posX=j;
                xActual = initX+(tamCubo*j);
                zActual = initZ+(tamCubo*i);
            }
        }
    }

    //Definimos la distancia de la cámara/foco según el tamaño del mapa
    double w = (largoMapa/2.0);
    double h = (altoMapa/2.0);
    int hipotenusa = (ceil(sqrt(w*w + h*h))+2) * tamCubo;
    camX = light_position[0] = 0.0f;
    camY = light_position[1] = minCamY;
    camZ = light_position[2] = hipotenusa;
    printf("%d\n",hipotenusa);
}
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int maxi = (sqrt(largoMapa*largoMapa + altoMapa*altoMapa)+3) * tamCubo;
    gluPerspective(90.0,width/height,10,maxi);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSetWindow (IdSub);
    glutReshapeWindow (width -950, height / 6);
    glutPositionWindow (5, 5);
    glutSetWindow (IdSubSub);
    glutReshapeWindow (width -10, height / 5);
    glutPositionWindow (5, 560);
    glutSetWindow (IdSubSub2);
    glutReshapeWindow (width -10, height / 5);
    glutPositionWindow (5, 560);
    glutSetWindow (IdMain);
}


void arbol(){
  //funcion para dibujar el arbol
  glPushMatrix();
    glTranslated(0,2,0);
    GLUquadricObj *obj;
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj,GLU_FILL);
    glPushMatrix();
        glColor3f( 0.36, 0.25,0.20);
        glRotated(90,1,0,0);
        // glScalef(1,1,1);
        gluCylinder(obj,0.5,0.5,3,20,20);
        glRotated(180,0,1,0);

            glPushMatrix();
            glTranslated(0,0,-2.999);
            glColor4f(0,0,0,0.4);
            glutSolidCone(0.8,0,10,10);
            glPopMatrix();

            glPushMatrix();
            glColor3f(0,0.3,0);
            glutSolidCone(1,3,10,10);
            glPopMatrix();

            glPushMatrix();
            glColor3f(0,0.6,0);
            glTranslated(0,0,1);
            glutSolidCone(1,3,10,10);
            glPopMatrix();

    glPopMatrix();
  glPopMatrix();
}
void lapicero(){
  // funcion para dibujar el lapicero
  glDisable(GL_CULL_FACE);
  glPushMatrix();
  glRotated(180,0,1,0);
  glRotated(90,1,0,0);
  GLUquadricObj *obj;
  obj = gluNewQuadric();
  gluQuadricDrawStyle(obj,GLU_FILL);

  glPushMatrix();
  glTranslated(1,1,-1);
  glColor3f(0,0,1);
  gluCylinder(obj,0.3,0.3,3,10,10);
  glPopMatrix();

  glPushMatrix();
    glTranslated(1,1,-1);
  glColor4f(1,1,1,0.5);
  gluCylinder(obj,0.5,0.5,3,10,10);

  glPushMatrix();
    glTranslated(0,0,-0.3);
  glColor3f(0,0,0);
  gluCylinder(obj,0.5,0.5,0.3,10,10);
  glPopMatrix();

  glPopMatrix();
  glPushMatrix();
  glColor3f(0.502, 0.502, 0.502);
  glTranslated(1,1,2);
  glutSolidCone(0.5,1,10,10);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0, 0, 0);
  glTranslated(1,1,-1.3);
  glutSolidCone(0.5,0,10,10);
  glPopMatrix();
  glPopMatrix();

  glDisable(GL_CULL_FACE);
}
void compas(){
  //funcion para dibujar el compas
  glPushMatrix();
  glRotated(50,1,0,0);
  GLUquadricObj *obj;
  obj = gluNewQuadric();
  gluQuadricDrawStyle(obj,GLU_FILL);

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslated(0,1,-1);
    glutSolidSphere(0.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,1,-1.5);
    glRotatef(40,0,1,0);
    glColor3f(0.412, 0.412, 0.412);
    gluCylinder(obj,0.3,0.3,0.5,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
      glPushMatrix();
      glColor3f(0.412, 0.412, 0.412);
      glTranslated(0,1,2);
      glutSolidCone(0.3,1,10,10);
      glPopMatrix();

      glPushMatrix();
      glTranslated(0,1,-1);
      glColor3f(0.412, 0.412, 0.412);
      gluCylinder(obj,0.3,0.3,3,10,10);
      glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,0,-0.5);
    glRotatef(60,0,1,0);
      glPushMatrix();
      glColor3f(0.412, 0.412, 0.412);
      glTranslated(0,1,2);
      glutSolidCone(0.3,1,10,10);
      glPopMatrix();

      glPushMatrix();
      glTranslated(0,1,-1);
      glColor3f(0.412, 0.412, 0.412);
      gluCylinder(obj,0.3,0.3,3,10,10);
      glPopMatrix();
    glPopMatrix();

  glPopMatrix();
}
void lapiz(){
  //funcion para dibujar el lapiz
  glPushMatrix();
    glRotated(180,0,1,0);
    glRotated(90,1,0,0);
    GLUquadricObj *obj;
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj,GLU_FILL);
    glPushMatrix();
      glColor3f(0.502, 0.502, 0.502);
      glTranslated(1,1,2);
      glutSolidCone(0.5,1,10,10);
    glPopMatrix();

    glPushMatrix();
      glTranslated(1,1,-1);
      glColor3f(1,1,0);
      gluCylinder(obj,0.5,0.5,3,10,10);
    glPopMatrix();

    glPushMatrix();
      glTranslated(1,1,-1.3);
      glColor3f(0,0,0);
      gluCylinder(obj,0.5,0.5,0.3,10,10);
    glPopMatrix();
    glPushMatrix();
      glTranslated(1,1,-1.6);
      glColor3f(0.647, 0.165, 0.165);
      gluCylinder(obj,0.5,0.5,0.3,10,10);
    glPopMatrix();
    glPushMatrix();
      glColor3f(0.647, 0.165, 0.165);
      glTranslated(1,1,-1.5);
      glutSolidCone(0.5,0,10,10);
    glPopMatrix();
  glPopMatrix();
}

void carros(){
  // funcion para dibujar carros
  glDisable(GL_CULL_FACE);
  glPushMatrix();
  glColor3f(0,0,0.5);
  glScalef(0.5,0.2,1);
  glutSolidCube(3);
  glEnd();
  glPushMatrix();
  // glColor3f(0,0,1);
    glScalef(1,1,1);
  glTranslated(0,3,0);
  glutSolidCube(2);
  glPopMatrix();
  glPopMatrix();

//llanta
  glPushMatrix();
  glTranslated(-1,-0.1,0.6);
  GLUquadricObj *obj;
  obj = gluNewQuadric();
  gluQuadricDrawStyle(obj,GLU_FILL);

  glPushMatrix();
  glTranslated(0,-0.1,0);
  glColor3f( 0,0,0);
  glRotated(90,0,1,0);
  glScalef(1,1,0.3);
  gluCylinder(obj,0.2,0.2,6.5,20,20);
//  glRotated(180,0,1,0);
  glPopMatrix();
  glPopMatrix();

  //llanta2
  glPushMatrix();
  glTranslated(-1,-0.1,-1);
  glPushMatrix();
  glColor3f( 0,0,0);
  glRotated(90,0,1,0);
  glScalef(1,1,0.3);
  gluCylinder(obj,0.2,0.2,6.5,20,20);
//  glRotated(180,0,1,0);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  glEnable(GL_CULL_FACE);
}

void postes(){
  //funcion para dibujar poste de luz
  glPushMatrix();
  GLUquadricObj *obj;
  obj = gluNewQuadric();
  gluQuadricDrawStyle(obj,GLU_FILL);

  glPushMatrix();
  glColor3f(0.412, 0.412, 0.412);
  glRotated(90,1,0,0);
  //glScalef(1,1,0.3);
  gluCylinder(obj,0.2,0.2,4,20,20);
  glRotated(180,0,1,0);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1,1,1);
  glTranslated(0,0,0);
  glutSolidSphere(0.5,50,50);
  glPopMatrix();
  glPopMatrix();
}



void figuraCuboTextura(float x, float y, float z, float ancho, float alto, float largo, int Numtextura){
  //funcion que utilizaremos para dibujar el avatar
  //paremetros a pasar puntos (x,y,z) ancho, alto, largo, numero de textura
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f,1.0f);
  if(ancho!=0 && alto!=0 && largo!=0){
    glVertex3f(x,y,z);//punto inicial
    glVertex3f(x, y+alto,z);//alto
    glVertex3f( x+ancho, y+alto,z+largo);
    glVertex3f( x+ancho,y,z+largo);
  }else if(ancho==0 && alto!=0 && largo!=0){
    glVertex3f(x,y,z);//punto inicial
    glVertex3f(x, y+alto,z);//alto
    glVertex3f(x, y+alto,z+largo);
    glVertex3f(x,y,z+largo);
  }else if(ancho!=0 && alto!=0 && largo==0){
    glVertex3f(x,y,z);//punto inicial
    glVertex3f(x, y+alto,z);//alto
    glVertex3f(x+ancho, y+alto, z);
    glVertex3f(x+ancho, y ,z);
  }else if(ancho!=0 && alto==0 && largo!=0){
    glVertex3f(x,y,z);//punto inicial
    glVertex3f(x, y,z+largo);//alto
    glVertex3f( x+ancho, y,z+largo);
    glVertex3f( x+ancho,y,z);
  }
  glEnd();
}
void avatar1(){
  // avatar creado a partir de varios cuadros hechos con GL_QUADS
  // ver en la funcion figuraCuboTextura()
  glDisable(GL_CULL_FACE);

glRotatef( 180, 0, 1,0 );
  int tamanioCabeza=4;
  int tamanioCuerpoX=3;
  int tamanioCuerpoY=5;
  int tamanioBrazoX=1;
  int tamanioBrazoY=3.5;
  glTranslatef(0,10,0);
  glPushMatrix();
  glPushMatrix();
  // glColor3f(1.000, 0.871, 0.678);
  glRotatef( Z, 0, tamanioCabeza/2,0 );

  glTranslatef(0,0,0);
  figuraCuboTextura(0,0,0,tamanioCabeza,tamanioCabeza,0,0);//cabeza enfrente
  figuraCuboTextura(0,0,0,0,tamanioCabeza,-tamanioCabeza,1);//cabeza lado b
  figuraCuboTextura(4,0,-4,0,tamanioCabeza,tamanioCabeza,2);//cabeza lado a
  figuraCuboTextura(0,0,0,tamanioCabeza,0,-tamanioCabeza,5);//cabeza lado e
  figuraCuboTextura(0,4,0,tamanioCabeza,0,-tamanioCabeza,3);//cabeza lado e

  figuraCuboTextura(0,0,-4,tamanioCabeza,tamanioCabeza,0,0);//cabeza atras
  glEnd();
  glPopMatrix();


//cuerpo

  glPushMatrix();
  glTranslatef(-0.2,0,-0.2);
  figuraCuboTextura(0.5,-5,-0.5,tamanioCuerpoX,tamanioCuerpoY,0,6);//cuerpo enfrente
  figuraCuboTextura(0.5,-5,-0.5,0,tamanioCuerpoY,-tamanioCuerpoX,8);//cuerpo lado b
  figuraCuboTextura(3.5,-5,-3.5,0,tamanioCuerpoY,tamanioCuerpoX,9);//cuerpo lado a
  figuraCuboTextura(0.5,-5,-3.5,tamanioCuerpoX,tamanioCuerpoY,0,10);//cuerpo enfrente
  glPopMatrix();

//brazo
  glPushMatrix();
  glRotatef( Z, tamanioCabeza/2,0,0 );
  glTranslatef(1.8,0,-1.8);
  glColor3f(0,0,0);
  figuraCuboTextura(1.5,-3,0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
  figuraCuboTextura(1.5,-3,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado b
  figuraCuboTextura(2.5,-3,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado a
  figuraCuboTextura(1.5,-3,-0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
  figuraCuboTextura(1.5,-3,0.5,tamanioBrazoX,0,-tamanioBrazoX ,12);//cabeza lado e
  figuraCuboTextura(1.5,0,0.5,tamanioBrazoX,0,-tamanioBrazoX ,13);//cabeza lado d
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glRotatef( -Z,tamanioCabeza/2,0,0 );
  glTranslatef(1.8,0,-1.8);
  figuraCuboTextura(-2.5,-3,0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
  figuraCuboTextura(-1.5,-3,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado b
  figuraCuboTextura(-2.5,-3,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado a
  figuraCuboTextura(-2.5,-3,-0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
  figuraCuboTextura(-2.5,-3,0.5,tamanioBrazoX,0,-tamanioBrazoX ,14);//cabeza lado e
  figuraCuboTextura(-2.5,0,0.5,tamanioBrazoX,0,-tamanioBrazoX ,13);//cabeza lado d
  glEnd();
  glPopMatrix();

  //brazo
glTranslatef(2,0,-2.5);
    glPushMatrix();
    glRotatef( -Z, tamanioCabeza/2,0,0 );

    figuraCuboTextura(0.4,-7,0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
    figuraCuboTextura(0.4,-7,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado b
    figuraCuboTextura(1.4,-7,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado a
    figuraCuboTextura(0.4,-7,-0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
    figuraCuboTextura(0.4,-7,0.5,tamanioBrazoX,0,-tamanioBrazoX ,12);//cabeza lado e
    // figuraCuboTextura(0.5,0,0.5,tamanioBrazoX,0,-tamanioBrazoX ,13);//cabeza lado d
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef( Z,tamanioCabeza/2,0,0 );

    figuraCuboTextura(-1.4,-7,0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
    figuraCuboTextura(-0.4,-7,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado b
    figuraCuboTextura(-1.4,-7,0.5,0,tamanioBrazoY,-tamanioBrazoX,11);//cuerpo lado a
    figuraCuboTextura(-1.4,-7,-0.5,tamanioBrazoX,tamanioBrazoY,0,11);//cabeza enfrente
    figuraCuboTextura(-1.4,-7,0.5,tamanioBrazoX,0,-tamanioBrazoX ,14);//cabeza lado e
    // figuraCuboTextura(-1.5,-3,0.5,tamanioBrazoX,0,-tamanioBrazoX ,13);//cabeza lado d
    glEnd();
    glPopMatrix();
glPopMatrix();

    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslatef(1.5,5,7);
    glColor4f(0,0,0,0.2);
    glutSolidCone(2,0,50,50);
    glPopMatrix();

    glEnable(GL_CULL_FACE);

}

void materia(){
  // funcion para dibujar materia, libro, o cuaderno
  glPushMatrix();
      glScalef(0.1,1,1);
      glTranslated(0,1,0);
      glColor3f(1,0,0);
      glutSolidCube(1);
            glPushMatrix();
            glTranslated(-0.7,0,0);
            glScalef(1,0.9,1);
            glColor3f(1,1,1);
            glutSolidCube(1);
            glPopMatrix();
      glPushMatrix();
      glTranslated(-1.7,0,0);
      glColor3f(1,0,0);
      glutSolidCube(1);
      glPopMatrix();
  glPopMatrix();
}
void define_textura_2D_128(struct ttextura_gimp textuN){
  glGenTextures(1,&textureID);          // Genera la textura 1 con la variable texture
  glBindTexture(GL_TEXTURE_2D,textureID);   // Asocia la variable texture como GL_TEXTURE_2D
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);  // Asigna Gl_MODULATE A GL_TEXTURE_ENV_MODE
  gluBuild2DMipmaps( GL_TEXTURE_2D, textuN.bytes_per_pixel,textuN.width,textuN.height,GL_RGB,GL_UNSIGNED_BYTE,textuN.pixel_data );
    // Define las propiedasdes de la textura 2D asociando la textura exportada gimp_image a la GL_TEXTURE_2D
};


void dibujarCubo(int X, int Z){
    glColor4f(1.0,1.0,1.0,1.0);

    glBegin(GL_QUADS);
        //Cara de enfrente
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2d(0.0,0.0);   glVertex3f(X-espacios,espacios,Z+espacios);
        glTexCoord2d(0.0,1.0);   glVertex3f(X-espacios,-espacios,Z+espacios);
        glTexCoord2d(1.0,1.0);   glVertex3f(X+espacios,-espacios,Z+espacios);
        glTexCoord2d(1.0,0.0);   glVertex3f(X+espacios,espacios,Z+espacios);

        //Cara izquierda
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2d(0.0,0.0);   glVertex3f(X-espacios,espacios,Z-espacios);
        glTexCoord2d(0.0,1.0);   glVertex3f(X-espacios,-espacios,Z-espacios);
        glTexCoord2d(1.0,1.0);   glVertex3f(X-espacios,-espacios,Z+espacios);
        glTexCoord2d(1.0,0.0);   glVertex3f(X-espacios,espacios,Z+espacios);

        //Cara de atrás
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2d(0.0,0.0);   glVertex3f(X+espacios,espacios,Z-espacios);
        glTexCoord2d(0.0,1.0);   glVertex3f(X+espacios,-espacios,Z-espacios);
        glTexCoord2d(1.0,1.0);   glVertex3f(X-espacios,-espacios,Z-espacios);
        glTexCoord2d(1.0,0.0);   glVertex3f(X-espacios,espacios,Z-espacios);

        //Cara derecha
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2d(0.0,0.0);   glVertex3f(X+espacios,espacios,Z+espacios);
        glTexCoord2d(0.0,1.0);   glVertex3f(X+espacios,-espacios,Z+espacios);
        glTexCoord2d(1.0,1.0);   glVertex3f(X+espacios,-espacios,Z-espacios);
        glTexCoord2d(1.0,0.0);   glVertex3f(X+espacios,espacios,Z-espacios);

        //Cara Arriba
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2d(0.0,0.0);   glVertex3f(X-espacios,espacios,Z-espacios);
        glTexCoord2d(0.0,1.0);   glVertex3f(X-espacios,espacios,Z+espacios);
        glTexCoord2d(1.0,1.0);   glVertex3f(X+espacios,espacios,Z+espacios);
        glTexCoord2d(1.0,0.0);   glVertex3f(X+espacios,espacios,Z-espacios);
    glEnd();
}

void edificios(){
  // dibujar edificios, en la matriz si se llegan a poder unidos se podra observar
  // que es un solo edificio
  glDisable(GL_CULL_FACE);
  glPushMatrix();
  glRotated(180,0,1,0);
  glTranslated(0,1,0);
  glColor3f(0.502, 0.000, 0.000);
  glScalef(1,1.5,1);
  glutSolidCube(3);
  glEnd();

  glPushMatrix();
  glTranslated(0,1,1.55);
  glBegin(GL_POLYGON);
  glColor4f(0,0,0,1);
  glVertex3f(-0.7,-0.3,0);
  glVertex3f(-0.7,0.3,0);
  glVertex3f(0.7,0.3,0);
  glVertex3f(0.7,-0.3,0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslated(0,-1,1.55);
  glBegin(GL_POLYGON);
  glColor4f(0,0,0,1);
  glVertex3f(-1,-0.5,0);
  glVertex3f(-1,0.5,0);
  glVertex3f(1,0.5,0);
  glVertex3f(1,-0.5,0);
  glEnd();
  glPopMatrix();
  glPopMatrix();
  glEnable(GL_CULL_FACE);
}

void hombrecito(){
  //avatar ayudante
  //cuerpo
  glPushMatrix();
      glScalef(1,1.3,1);
      glColor3f(0.118, 0.565, 1.000);
      glutSolidCube(1);
      //cabeza
      glPushMatrix();
        glColor3f(1.000, 0.871, 0.678);
        glTranslated(0,1,0);
        glScalef(1.8,1,1);
        glutSolidCube(1);
        //brazo
            glPushMatrix();
                  glColor3f(1.000, 0.871, 0.678);
                glTranslated(0.3,-0.8,0);
                glScalef(0.2,1,0.5);
                glutSolidCube(0.5);
            glPopMatrix();
            //brazo derecho
              glPushMatrix();
                 glColor3f(1.000, 0.871, 0.678);
               glTranslated(-0.3,-0.8,0);
               glScalef(0.2,1,0.5);
               glutSolidCube(0.5);
               glPopMatrix();
        glPopMatrix();
        //pierna izquierda
        glPushMatrix();
        glTranslated(0.3,-0.7,0);
        glScalef(0.5,1,0.5);
        glColor3f(0,0,1);
        glutSolidCube(0.5);
        glPopMatrix();
//pierna derecha
        glPushMatrix();
        glTranslated(-0.3,-0.7,0);
        glScalef(0.5,1,0.5);
        glColor3f(0,0,1);
        glutSolidCube(0.5);
        glPopMatrix();
  glPopMatrix();
}

void arbusto(){
  //funcion para dibujar un arbusto creado con una esfera
  glPushMatrix();
  glRotated(90,1,0,0);
  glColor3f(0.000, 0.502, 0.000);
  glutSolidSphere(1,6,6);
  glPopMatrix();
}

bool esValido(int X, int Z) {
    return X>=0 && X<largoMapa && Z>=0 && Z<altoMapa;
}


void dibujarPiso(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}

void dibujarPisoAzul(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}
void dibujarPisoRojo(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}
void dibujarPisoBlanco(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}
void dibujarPisoNegro(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}

void dibujarPisoMorado(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();
}

void dibujarPisoRojol(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glTexCoord2d(0.0,0.0);glVertex3f(X-espacios,Y,Z-espacios);
        glTexCoord2d(0.0,1.0);glVertex3f(X-espacios,Y,Z+espacios);
        glTexCoord2d(1.0,1.0);glVertex3f(X+espacios,Y,Z+espacios);
        glTexCoord2d(1.0,0.0);glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();


}
void dibujarPisoVerde(int X, int Y, int Z){
    glPushMatrix();
    glColor3f(0.1,1,0.2);

    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f); //Hacia arriba
        glVertex3f(X-espacios,Y,Z-espacios);
        glVertex3f(X-espacios,Y,Z+espacios);
        glVertex3f(X+espacios,Y,Z+espacios);
        glVertex3f(X+espacios,Y,Z-espacios);
    glEnd();
    glColor3f(0,0,0);
    glPopMatrix();


}



void dibujaMapa(){
	//float x,y;
  //Habilitamos textura para el piso utilizado mas que todo en case 0,2
  define_textura_2D_128(textura_ladrillos);

	for(int i=0;i<altoMapa;i++){
        for(int j=0;j<largoMapa;j++){
            switch(mapa[i][j]){
                case 0:
                case 2:
                    glEnable(GL_TEXTURE_2D);		// Habilita la GL_TEXTURE_2D
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                    break;
                case 1:
                     //Carga el cubo con textura
                    glEnable(GL_TEXTURE_2D);		// Habilita la GL_TEXTURE_2D
                    glPushMatrix();
                    dibujarCubo(cubos[i][j][0],cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();

                break;

                case 3:
                    glPushMatrix();
                    dibujarPisoVerde(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glTranslatef(cubos[i][j][0],0,cubos[i][j][1]);
                    glScalef(10,7,10);
                    arbol();
                    glPopMatrix();
                break;
                case 4:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],-4,cubos[i][j][1]);
                    glScalef(10,10,10);
                    carros();
                    glPopMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glPushMatrix();

                    glPopMatrix();
                break;
                case 5:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],0,cubos[i][j][1]);
                    glScalef(6.7,8,6.7);
                    edificios();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();


                break;
                case 6:
                    glPushMatrix();
                    dibujarPisoVerde(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glTranslatef(cubos[i][j][0],0,cubos[i][j][1]);
                    glScalef(10,7,10);
                    arbol();
                    glPopMatrix();

                break;
                case 7:
                    glPushMatrix();
                    dibujarPisoVerde(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glTranslatef(cubos[i][j][0],30,cubos[i][j][1]);
                    glScalef(10,10,10);
                    postes();
                    glPopMatrix();
                break;
                case 8:
                    glPushMatrix();
                    dibujarPisoVerde(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glTranslatef(cubos[i][j][0],-5,cubos[i][j][1]);
                    glScalef(10,5,10);
                    arbusto();
                    glPopMatrix();
                break;
                case 9:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],1,cubos[i][j][1]);
                    glRotatef(90,0,1,0);
                    glScalef(5,5,5);
                    hombrecito();
                    glPopMatrix();
                    glPushMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;
                case 10:

                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],10,cubos[i][j][1]);
                    glRotatef(-rotateX,0,1,0);
                    glScalef(2,5,2);
                    lapicero();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;
                case 11:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],10,cubos[i][j][1]);
                    glRotatef(rotateX,0,1,0);
                    glScalef(2,5,2);
                    lapiz();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;
                case 12:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],10,cubos[i][j][1]);
                    glRotatef(rotateX,0,1,0);
                    glScalef(0.2,0.2,0.2);
                    glColor3f(0.12, 0.12, 0.12);
                    glutSolidCube(tamCubo);
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;
                case 13:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],10,cubos[i][j][1]);
                    glRotatef(rotateX,0,1,0);
                    glRotatef(20,1,0,0);
                    glScalef(2,3,2);
                    glColor3f(1,1,0);
                    compas();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();

                    //compas va aqui
                break;
                case 14:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],-4,cubos[i][j][1]);
                    glRotatef(rotateX,0,1,0);
                    glScalef(10,10,10);
                    materia();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;
                case 15:
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],1,cubos[i][j][1]);
                    glRotatef(90,0,1,0);
                    glScalef(5,5,5);
                    hombrecito();
                    glPopMatrix();
                    glPushMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                break;

                case 16:
                //
                glEnable(GL_TEXTURE_2D);
                    glPushMatrix();
                    dibujarPiso(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glDisable(GL_TEXTURE_2D);
                    glTranslatef(cubos[i][j][0],1,cubos[i][j][1]);
                    glRotatef(rotateX,0,1,0);
                    glScalef(5,5,5);
                    materia();
                    glDisable(GL_TEXTURE_2D);
                    glPopMatrix();

                break;
                case 17:
                glPushMatrix();
                dibujarPisoAzul(cubos[i][j][0],-espacios,cubos[i][j][1]);
                glPopMatrix();

                break;
                case 18:
                glPushMatrix();
                dibujarPisoRojol(cubos[i][j][0],-espacios,cubos[i][j][1]);
                glPopMatrix();
                break;
                case 19:
                glPushMatrix();
                dibujarPisoBlanco(cubos[i][j][0],-espacios,cubos[i][j][1]);
                glPopMatrix();
                break;

                case 20:
                    glPushMatrix();
                    dibujarPisoNegro(cubos[i][j][0],-espacios,cubos[i][j][1]);
                    glPopMatrix();
                break;

                case 21:
                glPushMatrix();
                dibujarPisoMorado(cubos[i][j][0],-espacios,cubos[i][j][1]);
                glPopMatrix();
                break;


            }
            //animacion para que los objetos esten rotando
            //se utilizo la matriz para poder animar los objetos
            rotateX=rotateX-= 0.01;

        }
        //cronometro si esta activo tendremos que recojer las variables en un tiempo de 1 minuto
        cronometro();
    }
    glPushMatrix();
		glTranslatef(xActual,-20,zActual);
    glPushMatrix();

    		glRotatef(rotx,0,1,0);
        glTranslatef(4,0,-4);
        glScalef(2,3,2);
        glColor3f(0,1,0);
        avatar1();
        glPopMatrix();

		glPopMatrix();


}
//subpantalla
void pintarsubventana ()
{
  glDisable(GL_CULL_FACE);
  glutSetWindow (IdSub);
   glClearColor (0.0, 0.0, 0.0, 0.5);
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor4f (0.0F, 0.0F, 0.0F,0.5F);
   glBegin (GL_POLYGON);
   glVertex2f (0.0F, 0.0F);
   glVertex2f (0.0F, 0.99F);
   glVertex2f (0.999F, 0.99F);
   glVertex2f (0.999F, 0.0F);
   glEnd ();


   glColor3f (1.0F, 1.0F, 1.0F);
   sprintf (label, "puntaje: %0.0f",puntos);
   glRasterPos2f (0.20F, 0.70F);
   dibujarCadena (label);
   sprintf (label, "Tiempo:%s", &str[0]);
   glRasterPos2f (0.20F, 0.45F);
   dibujarCadena (label);
   sprintf (label, "F2 ayuda ");
   glRasterPos2f (0.20F, 0.25F);
   dibujarCadena (label);

   glEnable(GL_CULL_FACE);
   glutSwapBuffers ();
}

void tamanosubventana (int w, int h) {
 glViewport (0, 0, w, h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F);
}////
//subpantalla2
void pintarsubventana2 ()
{
  glDisable(GL_CULL_FACE);
  glutSetWindow (IdSubSub);
   glClearColor (0.0, 0.0, 0.0, 0.5);
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor4f (1.0F, 1.0F, 1.0F,0.5F);
   glBegin (GL_POLYGON);
   glVertex2f (0.0F, 0.0F);
   glVertex2f (0.0F, 0.99F);
   glVertex2f (0.999F, 0.99F);
   glVertex2f (0.999F, 0.0F);
   glEnd ();
if(mostrarmensaje[1] ==1 || mostrarmensaje[0]==1){
   glColor3f (0.0F, 0.0F, 0.0F);
   sprintf (label,"%s ",mensajetexto.substr(0,118).c_str());
   glRasterPos2f (0.0F, 0.70F);
   dibujarCadena (label);

   if(mensajetexto.length()>118){
     sprintf (label,"%s ",mensajetexto.substr(119).c_str());
     glRasterPos2f (0.0F, 0.35F);
    dibujarCadena (label);
   }

 }

   // sprintf (label, "Tiempo:%s", &str[0]);
   //
   glEnable(GL_CULL_FACE);
   glutSwapBuffers ();
}

void tamanosubventana2 (int w, int h) {
 glViewport (0, 0, w, h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F);
}
//subpantalla3
void pintarsubventana3 ()
{
  glDisable(GL_CULL_FACE);
  glutSetWindow (IdSubSub2);
   glClearColor (0.0, 0.0, 0.0, 0.5);
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor4f (1.0F, 1.0F, 1.0F,0.5F);
   glBegin (GL_POLYGON);
   glVertex2f (0.0F, 0.0F);
   glVertex2f (0.0F, 0.99F);
   glVertex2f (0.999F, 0.99F);
   glVertex2f (0.999F, 0.0F);
   glEnd ();
   glColor3f (0.0F, 0.0F, 0.0F);
   sprintf (label, "usa las teclas cursoras para desplazarte en el juego");
   glRasterPos2f (0.20F, 0.70F);
   dibujarCadena (label);
   sprintf (label, "con la tecla espaciadora inicias el timepo");
   glRasterPos2f (0.20F, 0.45F);
   dibujarCadena (label);
   sprintf (label, "presiona F2 para salir de este mensaje");
   glRasterPos2f (0.20F, 0.25F);
   dibujarCadena (label);
   glutSwapBuffers ();
}

void tamanosubventana3 (int w, int h) {
 glViewport (0, 0, w, h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F);
}

// función que muestra por pantalla la escena.
void display() {
   glutSetWindow (IdMain);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(xActual,camY-camY+50,zActual-60,
      xActual,-1,zActual-10,
      camX,0,camZ+100);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    // rotateX+=1;
	  dibujaMapa();
    glutSwapBuffers();
}

void init() {
    glClearColor(0,0,0,0);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    camX = light_position[0] = 0.0f,camY = light_position[1] = 60.0f, camZ = light_position[2] =120.0f;
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    light_position[0]= -100;
		light_position[2]= -100;
    light_position[1]= 100;

    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION,light_spot_dir);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, light_attenuation);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}


void moverCubo(int direccion){

    switch(direccion){
        case MOV_ARRIBA://Arriba

            if(esValido(posX,posZ+1) && mapa[posZ+1][posX]!=3 && mapa[posZ+1][posX]!=1 && mapa[posZ+1][posX]!=4 && mapa[posZ+1][posX]!=5 && mapa[posZ+1][posX]!=7 && mapa[posZ+1][posX]!=9 && mapa[posZ+1][posX]!=6 ){
              //evaluando en z+1 (hacia a delante)
              //si es diferentes a las posiciones escritas arriba, nos moveremos

              // deciciones que nos ayudaran a rotar el avatar dependiendo haciendo donde este viendo
              if(VistaPersonaje[1]==1){
                for(int i=0;i<=17; i++){
                    rotx += 10;
                    display();
                }
                VistaPersonaje[0]=1;
                VistaPersonaje[1]=0;
                VistaPersonaje[2]=0;
                VistaPersonaje[3]=0;
              }
              if(VistaPersonaje[3]==1){
                for(int i=0;i<=9; i++){
                    rotx -= 10;
                    display();
                }
                VistaPersonaje[0]=1;
                VistaPersonaje[1]=0;
                VistaPersonaje[2]=0;
                VistaPersonaje[3]=0;
              }
              if(VistaPersonaje[2]==1){
                for(int i=0;i<=9; i++){
                    rotx += 10;
                    display();
                }
                VistaPersonaje[0]=1;
                VistaPersonaje[1]=0;
                VistaPersonaje[2]=0;
                VistaPersonaje[3]=0;
              }
///------------------------------------------------------------------------////
              if(esValido(posX,posZ+1) && mapa[posZ+1][posX]==0){
                //sonido para caminar mientras se mueva el avatar
                //caminando en piso
                Mix_PlayChannel( -1, walk, 0 );
              }
              if(esValido(posX,posZ+1) && mapa[posZ+1][posX]==8){
                //sonido para caminar mientras se mueva el avatar
                //caminando en cesped
                Mix_PlayChannel( -1, cesped, 0 );
              }
                for (int i = 0; i < tamCubo; i++)
                {
                    zActual+=1; // mover en z positivo
                    // roty+=4.5;
                    Z=10*cos(i);
                    display();
                }
                posZ++;

            }else{
              //sonido que seria de tope, cuando el objeto no se pueda mover
              Mix_PlayChannel( -1, tope, 0 );
            }


            if(esValido(posX,posZ+1) && mapa[posZ+1][posX]==9 ){
              //validcion para el avatar ayudante
              mostrarmensaje[0] = 1; //cambiamos la variable para que se muestre el mensaje
              mensajetexto = mensaje1; //llamamos a la cadena de texto que esta almacenada en la variable mensaje1
              Mix_PlayChannel( -1, scratch, 0 );//sonido del ayudante
              glutSetWindow(IdSubSub);//capturamos la pantalla
              glutShowWindow();//mostramos la tercera pantalla
            }else{
              //decicion cuando el avtar se halla alejado
              mostrarmensaje[0]=0; //cambiamos la variable para ocultar el mensaje
              glutSetWindow(IdSubSub);//capturamos la pantalla
              glutHideWindow();//mostramos la tercera pantalla
            }
//////--------------------------------------------------------------------/////
/////------------Deciciones para recoger y gardar objetos----------------//////
            if(esValido(posX,posZ) && mapa[posZ][posX]==10){
              //primer if
              //guardamos posicion de objeto en la matris posicionesEscena1
              posicionesEscena1[0][0] =posZ;// posicion en Z
              posicionesEscena1[0][1]=posX;// posicion en X
              mapa[posZ][posX]=16; // cambiamos el objeto por un libro
              matiriaEscena1[0]=1; // llenamos el campo de la matriz matiriaEscena1 con valor a 1 indicando que ya tenemos el objeto
              puntos+=4;// sumamos puntos
              Mix_PlayChannel( -1, get, 0 );//sonido de agarre
            }
            if(esValido(posX,posZ) && mapa[posZ][posX]==11){
                //evaluamos si el primer objeto ya se a recolectado
                if(matiriaEscena1[0]==1){
                  //si esta recolentado hacemos lo mismo que en el primer if
                  posicionesEscena1[1][0] =posZ;
                  posicionesEscena1[1][1]=posX;
                  mapa[posZ][posX]=16;
                  matiriaEscena1[1]=1;
                  puntos+=4;

                  Mix_PlayChannel( -1, get, 0 );
                }else{
                  //si el objeto anterior no esta recolectado
                  //puntos los pondremos en 0
                  //sonido de error
                  puntos=0;
                  Mix_PlayChannel( -1, error, 0 );
                }
            }
            if(esValido(posX,posZ) && mapa[posZ][posX]==12){

                if(matiriaEscena1[1]==1){
                  posicionesEscena1[2][0] =posZ;
                  posicionesEscena1[2][1]=posX;
                  mapa[posZ][posX]=16;
                  matiriaEscena1[2]=1;
                  puntos+=4;

                  Mix_PlayChannel( -1, get, 0 );
                }else{
                  mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
                  matiriaEscena1[0]=0;
                  puntos=0;
                  Mix_PlayChannel( -1, error, 0 );
                }
            }
            if(esValido(posX,posZ) && mapa[posZ][posX]==13){

                if(matiriaEscena1[2]==1){
                  posicionesEscena1[3][0] =posZ;
                  posicionesEscena1[3][1]=posX;
                  mapa[posZ][posX]=16;
                  matiriaEscena1[3]=1;
                  puntos+=4;

                  Mix_PlayChannel( -1, get, 0 );
                }else{
                  mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
                  matiriaEscena1[0]=0;
                  mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
                  matiriaEscena1[1]=0;
                  puntos=0;
                  Mix_PlayChannel( -1, error, 0 );
                }
            }
            if(esValido(posX,posZ) && mapa[posZ][posX]==14){

                if(matiriaEscena1[3]==1){
                  posicionesEscena1[4][0] =posZ;
                  posicionesEscena1[4][1]=posX;
                  mapa[posZ][posX]=16;
                  matiriaEscena1[4]=1;
                  puntos+=4;
                  mostrarmensaje[1]=1;
                  mensajetexto = "Felicidades has logrado conseguir todos los objetos, vamos al siguiente nivel";
                  mensaje1 = "Muchas Felicidades has llegado al nivel dos, ahora tu mision sera reunir los colores en este orden, Azul, Rojo, Blanco, Negro, Amarillo";
                  glutSetWindow(IdSubSub);
                  glutShowWindow();
                  for(int i=0;i<altoMapa;i++){
                  //si todos los objetos han sido recolectados
                  //evaluar el mapa para cambiar el objeto con valor a 6
                  //y poner piso cambiando el valor de 6 a 0
                        for(int j=0;j<largoMapa;j++){
                            if(mapa[i][j]==6){
                              mapa[i][j]=0;
                            }
                        }
                      }
                        Mix_PlayChannel( -1, win, 0 );
                }else{
                  // si no sale bien pondra todos los objetos en su lugar
                  mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
                  matiriaEscena1[0]=0;
                  mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
                  matiriaEscena1[1]=0;
                  mapa[posicionesEscena1[2][0]][posicionesEscena1[2][1]]=12;
                  matiriaEscena1[2]=0;
                  puntos=0;
                  Mix_PlayChannel( -1, error, 0 );
                }
            }
///------------------------fin de capturar objetos------------------------/////
//------------------------------------------------------------------------/////
//======================Hacer lo mismo para las demas teclas==============////
//----con difencia que tecla abajo se le restara uno a posZ, zActual restar 1---///
//====--tecla izquierda sumar 1 posX, y a xActual----=====================//
//====--tecla derecha restar 1 posX, y a xActual----=====================//
            break;

        case MOV_ABAJO://Abajo
        if(esValido(posX,posZ-1) && mapa[posZ-1][posX]!=3 && mapa[posZ-1][posX]!=1 && mapa[posZ-1][posX]!=9 && mapa[posZ-1][posX]!=4  && mapa[posZ-1][posX]!=5 && mapa[posZ-1][posX]!=7){

          if(VistaPersonaje[0]==1){
            for(int i=0;i<=17; i++){
                rotx += 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=1;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=0;
          }
          if(VistaPersonaje[2]==1){
            for(int i=0;i<=9; i++){
                rotx -= 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=1;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=0;
          }
          if(VistaPersonaje[3]==1){
            for(int i=0;i<=8; i++){
                rotx += 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=1;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=0;
          }

          if(esValido(posX,posZ-1) && mapa[posZ-1][posX]==0){
            Mix_PlayChannel( -1, walk, 0 );
          }
          if(esValido(posX,posZ-1) && mapa[posZ-1][posX]==8){


            Mix_PlayChannel( -1, cesped, 0 );
          }

            for (int i = 0; i < tamCubo; i++)
            {
                zActual-=1;
                // rotx-=4.5;
                Z=10*cos(i);
                // rotateX-=i;//rotar libro
                display();
            }


            posZ--;
        }else{
          Mix_PlayChannel( -1, tope, 0 );
        }
        if(esValido(posX,posZ-1) && mapa[posZ-1][posX]==9){

          mostrarmensaje[1] = 1;
          Mix_PlayChannel( -1, scratch, 0 );
          mensajetexto = mensaje1;
          glutSetWindow(IdSubSub);
          glutShowWindow();
        }else{
          mostrarmensaje[1]=0;
          glutSetWindow(IdSubSub);
          glutHideWindow();
        }



        if(esValido(posX,posZ) && mapa[posZ][posX]==10){

          posicionesEscena1[0][0] =posZ;
          posicionesEscena1[0][1]=posX;
          mapa[posZ][posX]=16;
          matiriaEscena1[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==11){

            if(matiriaEscena1[0]==1){
              posicionesEscena1[1][0] =posZ;
              posicionesEscena1[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[1]=1;
              puntos+=4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==12){

            if(matiriaEscena1[1]==1){
              posicionesEscena1[2][0] =posZ;
              posicionesEscena1[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[2]=1;
              puntos=+4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==13){

            if(matiriaEscena1[2]==1){
              posicionesEscena1[3][0] =posZ;
              posicionesEscena1[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[3]=1;
              puntos+=4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
              puntos=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==14){

            if(matiriaEscena1[3]==1){

              posicionesEscena1[4][0] =posZ;
              posicionesEscena1[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[4]=1;
              puntos+=4;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los objetos, vamos al siguiente nivel";
              mensaje1 = "Muchas Felicidades has llegado al nivel dos, ahora tu mision sera reunir los colores en este orden, Azul, Rojo, Blanco, Negro, Amarillo";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              for(int i=0;i<altoMapa;i++){
                    for(int j=0;j<largoMapa;j++){
                        if(mapa[i][j]==6){
                          mapa[i][j]=0;
                        }
                    }

                  }
                    Mix_PlayChannel( -1, win, 0 );
            }else{
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
              mapa[posicionesEscena1[2][0]][posicionesEscena1[2][1]]=12;
              matiriaEscena1[2]=0;
              puntos=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }

            break;
        case MOV_IZQUIERDA://Izquierda

        if(esValido(posX+1,posZ) && mapa[posZ][posX+1]!=3 && mapa[posZ][posX+1]!=1 && mapa[posZ][posX+1]!=9 && mapa[posZ][posX+1]!=4 && mapa[posZ][posX+1]!=5 && mapa[posZ][posX+1]!=7){

          if(VistaPersonaje[2]==1){
            for(int i=0;i<=17; i++){
                rotx += 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=0;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=1;
          }
          if(VistaPersonaje[0]==1){
            for(int i=0;i<=9; i++){
                rotx += 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=0;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=1;
          }
          if(VistaPersonaje[1]==1){
            for(int i=0;i<=9; i++){
                rotx -= 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=0;
            VistaPersonaje[2]=0;
            VistaPersonaje[3]=1;
          }

          if(esValido(posX+1,posZ) && mapa[posZ][posX+1]==0){
            Mix_PlayChannel( -1, walk, 0 );
          }
          if(esValido(posX+1,posZ) && mapa[posZ][posX+1]==8){


            Mix_PlayChannel( -1, cesped, 0 );
          }
            for (int i = 0; i < tamCubo; i++){
                xActual+=1;
                roty+=4.5;
                Z=10*cos(i);
                display();
            }
            posX++;
        }else{
          Mix_PlayChannel( -1, tope, 0 );
        }
        if(esValido(posX+1,posZ) && mapa[posZ][posX+1]==9){

          mostrarmensaje[1] = 1;
          mensajetexto = mensaje1;
          Mix_PlayChannel( -1, scratch, 0 );
          glutSetWindow(IdSubSub);
          glutShowWindow();
        }else{
          mostrarmensaje[1]=0;
          glutSetWindow(IdSubSub);
          glutHideWindow();
        }



        if(esValido(posX,posZ) && mapa[posZ][posX]==10){

          posicionesEscena1[0][0] =posZ;
          posicionesEscena1[0][1]=posX;
          mapa[posZ][posX]=16;
          matiriaEscena1[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==11){

            if(matiriaEscena1[0]==1){
              posicionesEscena1[1][0] =posZ;
              posicionesEscena1[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[1]=1;
              puntos+=4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==12){

            if(matiriaEscena1[1]==1){
              posicionesEscena1[2][0] =posZ;
              posicionesEscena1[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[2]=1;
              puntos+=4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==13){

            if(matiriaEscena1[2]==1){
              posicionesEscena1[3][0] =posZ;
              posicionesEscena1[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[3]=1;
              puntos+=4;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
              puntos=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==14){

            if(matiriaEscena1[3]==1){

              posicionesEscena1[4][0] =posZ;
              posicionesEscena1[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[4]=1;
              puntos+=4;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los objetos, vamos al siguiente nivel";
              mensaje1 = "Muchas Felicidades has llegado al nivel dos, ahora tu mision sera reunir los colores en este orden, Azul, Rojo, Blanco, Negro, Amarillo";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              for(int i=0;i<altoMapa;i++){
                    for(int j=0;j<largoMapa;j++){
                        if(mapa[i][j]==6){
                          mapa[i][j]=0;
                        }
                    }

                  }
                    Mix_PlayChannel( -1, win, 0 );
            }else{
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
              mapa[posicionesEscena1[2][0]][posicionesEscena1[2][1]]=12;
              matiriaEscena1[2]=0;
              puntos=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }

            break;
        case MOV_DERECHA://Derecha
        if(esValido(posX-1,posZ) && mapa[posZ][posX-1]!=3 && mapa[posZ][posX-1]!=1 && mapa[posZ][posX-1]!=9 && mapa[posZ][posX-1]!=4 && mapa[posZ][posX-1]!=5 && mapa[posZ][posX-1]!=7 ){
          if(VistaPersonaje[0]==1){
            for(int i=0;i<=9; i++){
                rotx -= 10;
                display();
            }
            VistaPersonaje[0]=0;
            VistaPersonaje[1]=0;
            VistaPersonaje[2]=1;
            VistaPersonaje[3]=0;
          }
          if(esValido(posX-1,posZ) && mapa[posZ][posX-1]==0){
            Mix_PlayChannel( -1, walk, 0 );
          }
          if(esValido(posX-1,posZ) && mapa[posZ][posX-1]==8){


            Mix_PlayChannel( -1, cesped, 0 );
          }
            for (int i = 0; i < tamCubo; i++){
                xActual-=1;
                roty+=4.5;
                Z=10*cos(i);
                display();
            }

          posX--;
        }else{
          Mix_PlayChannel( -1, tope, 0 );
        }
        if(esValido(posX-1,posZ) && mapa[posZ][posX-1]==9){

          mostrarmensaje[1] = 1;
          mensajetexto = mensaje1;
          Mix_PlayChannel( -1, scratch, 0 );
          glutSetWindow(IdSubSub);
          glutShowWindow();
        }else{
          mostrarmensaje[1]=0;
          glutSetWindow(IdSubSub);
          glutHideWindow();
        }



        if(esValido(posX,posZ) && mapa[posZ][posX]==10){
          puntos+=4;
          posicionesEscena1[0][0] =posZ;
          posicionesEscena1[0][1]=posX;
          mapa[posZ][posX]=16;
          matiriaEscena1[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==11){

            if(matiriaEscena1[0]==1){
              puntos+=4;
              posicionesEscena1[1][0] =posZ;
              posicionesEscena1[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[1]=1;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==12){

            if(matiriaEscena1[1]==1){
              puntos+=4;
              posicionesEscena1[2][0] =posZ;
              posicionesEscena1[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[2]=1;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==13){

            if(matiriaEscena1[2]==1){
              puntos+=4;
              posicionesEscena1[3][0] =posZ;
              posicionesEscena1[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[3]=1;
              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==14){

            if(matiriaEscena1[3]==1){
              puntos+=4;
              posicionesEscena1[4][0] =posZ;
              posicionesEscena1[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena1[4]=1;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los objetos, vamos al siguiente nivel";
              mensaje1 = "Muchas Felicidades has llegado al nivel dos, ahora tu mision sera reunir los colores en este orden, Azul, Rojo, Blanco, Negro, Amarillo";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              for(int i=0;i<altoMapa;i++){
                    for(int j=0;j<largoMapa;j++){
                        if(mapa[i][j]==6){
                          mapa[i][j]=0;
                        }
                    }

                  }
                    Mix_PlayChannel( -1, win, 0 );
            }else{
              puntos=0;
              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              matiriaEscena1[0]=0;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              matiriaEscena1[1]=0;
              mapa[posicionesEscena1[2][0]][posicionesEscena1[2][1]]=12;
              matiriaEscena1[2]=0;
            Mix_PlayChannel( -1, error, 0 );
            }
        }

            break;
    }
}

void temporizador(int value) {
    switch (value) {
        case 1 :
            if(start==1) {aseg++;};
            if (aseg==60){
              for(int j=0; j<5; j++){
                if(matiriaEscena1[j]==1){
                  materiaOk=true;
                }else{
                  materiaOk=false;
                }
              }
              aseg=0;
              start=0;

              if(materiaOk==false){
              for(int i=0;i<5;i++){
                matiriaEscena1[i]=0;
              }

              mapa[posicionesEscena1[0][0]][posicionesEscena1[0][1]]=10;
              mapa[posicionesEscena1[1][0]][posicionesEscena1[1][1]]=11;
              mapa[posicionesEscena1[2][0]][posicionesEscena1[2][1]]=12;
              mapa[posicionesEscena1[3][0]][posicionesEscena1[3][1]]=13;
              mapa[posicionesEscena1[4][0]][posicionesEscena1[4][1]]=14;
            }
            }
            glutPostRedisplay();
            glutTimerFunc(segs,temporizador,1);
            break;
        case 2 :
            if(start==1) {amin++;}if (amin==60){amin=0;}
            glutPostRedisplay();
            glutTimerFunc(mins,temporizador,2);
            break;
        case 3 :
            if(start==1) {ahr++;}if (ahr==100){ahr=0;}
            glutPostRedisplay();
            glutTimerFunc(hrs,temporizador,3);
            break;
    }
}




// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
static int info_banner = 1;
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT){
        moverCubo(MOV_DERECHA);
        if(esValido(posX,posZ) && mapa[posZ][posX]==17){

          posicionesEscena2[0][0] =posZ;
          posicionesEscena2[0][1]=posX;
          mapa[posZ][posX]=16; // libro
          matiriaEscena2[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==18){

            if(matiriaEscena2[0]==1){
              posicionesEscena2[1][0] =posZ;
              posicionesEscena2[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[1]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==19){

            if(matiriaEscena2[1]==1){
              posicionesEscena2[2][0] =posZ;
              posicionesEscena2[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[2]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==20){

            if(matiriaEscena2[2]==1){
              posicionesEscena2[3][0] =posZ;
              posicionesEscena2[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[3]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==21){

            if(matiriaEscena2[3]==1){
              posicionesEscena2[4][0] =posZ;
              posicionesEscena2[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[4]=1;
              puntos+=4;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los colores";
              mensaje1 = "Felicidades ya sabes los colores basicos, proximamente vamos a tener mas niveles para ti";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              // for(int i=0;i<altoMapa;i++){
              //       for(int j=0;j<largoMapa;j++){
              //           if(mapa[i][j]==6){
              //             mapa[i][j]=0;
              //           }
              //       }
              //
              //     }
                    Mix_PlayChannel( -1, win, 0 );
                    // mostrarmensaje[1]=0;
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              mapa[posicionesEscena2[2][0]][posicionesEscena2[2][1]]=19;
              matiriaEscena2[2]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
      }
}
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT){
        moverCubo(MOV_IZQUIERDA);
        if(esValido(posX,posZ) && mapa[posZ][posX]==17){

          posicionesEscena2[0][0] =posZ;
          posicionesEscena2[0][1]=posX;
          mapa[posZ][posX]=16; // libro
          matiriaEscena2[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==18){

            if(matiriaEscena2[0]==1){
              posicionesEscena2[1][0] =posZ;
              posicionesEscena2[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[1]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==19){

            if(matiriaEscena2[1]==1){
              posicionesEscena2[2][0] =posZ;
              posicionesEscena2[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[2]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==20){

            if(matiriaEscena2[2]==1){
              posicionesEscena2[3][0] =posZ;
              posicionesEscena2[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[3]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==21){

            if(matiriaEscena2[3]==1){
              posicionesEscena2[4][0] =posZ;
              posicionesEscena2[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[4]=1;
              puntos+=4;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los colores";
              mensaje1 = "Felicidades ya sabes los colores basicos, proximamente vamos a tener mas niveles para ti";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              // for(int i=0;i<altoMapa;i++){
              //       for(int j=0;j<largoMapa;j++){
              //           if(mapa[i][j]==6){
              //             mapa[i][j]=0;
              //           }
              //       }
              //
              //     }
                    Mix_PlayChannel( -1, win, 0 );
                    // mostrarmensaje[1]=0;
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              mapa[posicionesEscena2[2][0]][posicionesEscena2[2][1]]=19;
              matiriaEscena2[2]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
      }
      }
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP){
        moverCubo(MOV_ARRIBA);
        if(esValido(posX,posZ) && mapa[posZ][posX]==17){

          posicionesEscena2[0][0] =posZ;
          posicionesEscena2[0][1]=posX;
          mapa[posZ][posX]=16; // libro
          matiriaEscena2[0]=1;
          puntos+=4;
          Mix_PlayChannel( -1, get, 0 );
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==18){

            if(matiriaEscena2[0]==1){
              posicionesEscena2[1][0] =posZ;
              posicionesEscena2[1][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[1]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              puntos=0;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==19){

            if(matiriaEscena2[1]==1){
              posicionesEscena2[2][0] =posZ;
              posicionesEscena2[2][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[2]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==20){

            if(matiriaEscena2[2]==1){
              posicionesEscena2[3][0] =posZ;
              posicionesEscena2[3][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[3]=1;
              puntos+=4;

              Mix_PlayChannel( -1, get, 0 );
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
        }
        if(esValido(posX,posZ) && mapa[posZ][posX]==21){

            if(matiriaEscena2[3]==1){
              posicionesEscena2[4][0] =posZ;
              posicionesEscena2[4][1]=posX;
              mapa[posZ][posX]=16;
              matiriaEscena2[4]=1;
              puntos+=4;
              mostrarmensaje[1]=1;
              mensajetexto = "Felicidades has logrado conseguir todos los colores";
              mensaje1 = "Felicidades ya sabes los colores basicos, proximamente vamos a tener mas niveles para ti";
              glutSetWindow(IdSubSub);
              glutShowWindow();
              // for(int i=0;i<altoMapa;i++){
              //       for(int j=0;j<largoMapa;j++){
              //           if(mapa[i][j]==6){
              //             mapa[i][j]=0;
              //           }
              //       }
              //
              //     }
                    Mix_PlayChannel( -1, win, 0 );
                    // mostrarmensaje[1]=0;
            }else{
              mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
              matiriaEscena2[0]=0;
              mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
              matiriaEscena2[1]=0;
              mapa[posicionesEscena2[2][0]][posicionesEscena2[2][1]]=19;
              matiriaEscena2[2]=0;
              puntos-=4;
              Mix_PlayChannel( -1, error, 0 );
            }
      }
    }
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN){
         moverCubo(MOV_ABAJO);
         if(esValido(posX,posZ) && mapa[posZ][posX]==17){

           posicionesEscena2[0][0] =posZ;
           posicionesEscena2[0][1]=posX;
           mapa[posZ][posX]=16; // libro
           matiriaEscena2[0]=1;
           puntos+=4;
           Mix_PlayChannel( -1, get, 0 );
         }
         if(esValido(posX,posZ) && mapa[posZ][posX]==18){

             if(matiriaEscena2[0]==1){
               posicionesEscena2[1][0] =posZ;
               posicionesEscena2[1][1]=posX;
               mapa[posZ][posX]=16;
               matiriaEscena2[1]=1;
               puntos+=4;

               Mix_PlayChannel( -1, get, 0 );
             }else{
               puntos=0;
               Mix_PlayChannel( -1, error, 0 );
             }
         }
         if(esValido(posX,posZ) && mapa[posZ][posX]==19){

             if(matiriaEscena2[1]==1){
               posicionesEscena2[2][0] =posZ;
               posicionesEscena2[2][1]=posX;
               mapa[posZ][posX]=16;
               matiriaEscena2[2]=1;
               puntos+=4;

               Mix_PlayChannel( -1, get, 0 );
             }else{
               mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
               matiriaEscena2[0]=0;
               puntos-=4;
               Mix_PlayChannel( -1, error, 0 );
             }
         }
         if(esValido(posX,posZ) && mapa[posZ][posX]==20){

             if(matiriaEscena2[2]==1){
               posicionesEscena2[3][0] =posZ;
               posicionesEscena2[3][1]=posX;
               mapa[posZ][posX]=16;
               matiriaEscena2[3]=1;
               puntos+=4;

               Mix_PlayChannel( -1, get, 0 );
             }else{
               mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
               matiriaEscena2[0]=0;
               mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
               matiriaEscena2[1]=0;
               puntos-=4;
               Mix_PlayChannel( -1, error, 0 );
             }
         }
         if(esValido(posX,posZ) && mapa[posZ][posX]==21){

             if(matiriaEscena2[3]==1){
               posicionesEscena2[4][0] =posZ;
               posicionesEscena2[4][1]=posX;
               mapa[posZ][posX]=16;
               matiriaEscena2[4]=1;
               puntos+=4;
               mostrarmensaje[1]=1;
               mensajetexto = "Felicidades has logrado conseguir todos los colores";
               mensaje1 = "Felicidades ya sabes los colores basicos, proximamente vamos a tener mas niveles para ti";
               glutSetWindow(IdSubSub);
               glutShowWindow();
               // for(int i=0;i<altoMapa;i++){
               //       for(int j=0;j<largoMapa;j++){
               //           if(mapa[i][j]==6){
               //             mapa[i][j]=0;
               //           }
               //       }
               //
               //     }
                     Mix_PlayChannel( -1, win, 0 );
                     // mostrarmensaje[1]=0;
             }else{
               mapa[posicionesEscena2[0][0]][posicionesEscena2[0][1]]=17;
               matiriaEscena2[0]=0;
               mapa[posicionesEscena2[1][0]][posicionesEscena2[1][1]]=18;
               matiriaEscena2[1]=0;
               mapa[posicionesEscena2[2][0]][posicionesEscena2[2][1]]=19;
               matiriaEscena2[2]=0;
               puntos-=4;
               Mix_PlayChannel( -1, error, 0 );
             }
       }
}
    //  Solicitar actualización de visualización

    if (key == GLUT_KEY_F2){
      if (info_banner) {
       glutSetWindow (IdSubSub2);
       glutHideWindow ();
       }
       else
      {
       glutSetWindow (IdSubSub2);
       glutShowWindow ();
      }
       info_banner = !info_banner;
    }

  display();
}

// función que permite interactuar con la escena mediante el teclado
void keyboard(unsigned char key, int x, int y){
    float t;

    switch(key) {
       // ROTAR CAMARA LA IZQUIERDA
    case '1':
        t=camX;
		light_position[0]= -100;
		light_position[2]= -100;
    light_position[1]= 100;
		display();
        break;
// ROTAR CAMARA LA DERECHA
    case '2':
    light_position[0]= 100;
    light_position[2]= 100;
    light_position[1]= 0;
		display();
        break;
// MOVER CAMARA HACIA ARRIBA
    case '3':
        if(camY<maxCamY){
            camY+=2;
            light_position[1] += 2;
        }
        //printf("Angulo de rotacion de la camara en torno al eje X: %i \n",((int)anguloCamaraX % 360));
        display();
        break;
// MOVER CAMARA HACIA ABAJO
    case '4':
        //anguloCamaraX--;
        if(camY>minCamY){
            camY-=2;
            light_position[1] -= 2;
        }
        //printf("Angulo de rotacion de la camara en torno al eje X: %i \n",((int)anguloCamaraX % 360));
        display();
        break;
    case 27:
        exit(0);
        break;
        case 's':
            if(start==1){
                start=0;
            }else{
                start=1;
            }
            display();
            break;
        case 'r':
            amin=0;
            aseg=0;
            ahr=0;
            //start=0;
            display();
            break;
            case ' ':
            if(start==0){
            start=1;
            }else{
              start=0;
            }

                display();
                break;

    }
}

//pantalla

void idle (void)
{
 glutSetWindow (IdMain);
 glutPostRedisplay ();
 glutSetWindow (IdSub);
 glutPostRedisplay ();
 glutSetWindow (IdSubSub);
 glutPostRedisplay ();
 glutSetWindow (IdSubSub2);
 glutPostRedisplay ();
}

/////

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1200, 800);
     IdMain =glutCreateWindow ("Aventuras Universitarias");
    parseCubos();
    init();
    //**********************SDL**************************++
    //Initialize
    init_sdl();
    load_files_sdl();
    Mix_PlayMusic(music, -1 );
    start =0;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutIdleFunc (idle);
    IdSub = glutCreateSubWindow (IdMain, 20, 20, 600 - 10, 600 / 10);
    glutTimerFunc(hrs,temporizador,3);
    glutTimerFunc(segs,temporizador,1);
    glutTimerFunc(mins,temporizador,2);
 glutDisplayFunc (pintarsubventana);
 glutReshapeFunc (tamanosubventana);
 IdSubSub = glutCreateSubWindow (IdMain, 20, 20, 600 - 10, 600 / 10);
 glutTimerFunc(hrs,temporizador,3);
 glutTimerFunc(segs,temporizador,1);
 glutTimerFunc(mins,temporizador,2);
glutDisplayFunc (pintarsubventana2);
glutReshapeFunc (tamanosubventana2);
IdSubSub2 = glutCreateSubWindow (IdMain, 20, 20, 600 - 10, 600 / 10);

glutDisplayFunc (pintarsubventana3);
glutReshapeFunc (tamanosubventana3);
    glutMainLoop();
    return 0;
}
