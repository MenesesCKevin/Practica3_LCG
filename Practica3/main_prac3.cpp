//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Meneses Cornejo Kevin Osmar			******//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
/*Funcion que dibuja un prisma rectangular, recibe como parametros, el RGB de cada cara, la base y la altura
void prisma(float sr,float sg,float sb, float ir, float ig, float ib, float dr, float dg, float db, float izr, float izg, float izb, float fr, float fg, float fb, float ar, float ag, float ab, float b,float h)
Todos los valores pueden ser flotantes o enteros

sr,sg,sb son los tres colores para pintar la cara superior
ir,ig,ib son los tres colores para pintar la cara inferior
dr,dg,db son los tres colores para pintar la cara derecha
izr,izg,izb son los tres colores para pintar la cara izquierda
fr,fg,gb son los tres colores para pintar la cara frontal
ar,ag,ab son los tres colores para pintar la cara de abajo
b es la variable que modifica la base
h es la variable que modifica la altura


*/

void prisma(float sr,float sg,float sb, float ir, float ig, float ib, float dr, float dg, float db, float izr, float izg, float izb, float fr, float fg, float fb, float ar, float ag, float ab, float b,float h)
{//orden en el que se esta dibujando el prisma 
	GLfloat vertice [8][3] = {
				{0.5*b ,-0.5*h, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5*b,-0.5*h, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5*b ,-0.5*h, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5*b ,-0.5*h, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5*b ,0.5*h, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5*b ,0.5*h, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5*b ,0.5*h, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5*b ,0.5*h, 0.5},    //Coordenadas V�rtice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(sr,sg,sb);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(ir, ig, ib);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glColor3f(dr, dg, db);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(izr, izg, izb);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(fr, fg, fb);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
		glColor3f(ar, ag, ab);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner C�digo Aqu�.
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glTranslatef(0.0 + transX, 0.0 + transZ, -5.0 + transY); //transalada el objeto
	//Se invoca la funcion prisma 
	
	prisma(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1, 2);
	/*
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glTranslatef(0.0+transX, 0.0+transZ, -5.0+transY); //transalada el objeto
	prisma();
	glTranslatef(0.0, 1.0, 0.0);
	prisma();
	glTranslatef(0.0, 1.0, 0.0);
	prisma();
	glTranslatef(0.0, 1.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(0.0, -1.0, 0.0);
	prisma();
	glTranslatef(0.0, -1.0, 0.0);
	prisma();
	glTranslatef(1.0, 2.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(0.0, -1.0, 0.0);
	prisma();
	glTranslatef(0.0, -1.0, 0.0);
	prisma();
	glTranslatef(0.0, -1.0, 0.0);
	prisma();

	glTranslatef(3.0, 0.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(-2.0, 1.0, 0.0);
	prisma();
	glTranslatef(0.0, 1.0, 0.0);
	prisma();
	glTranslatef(0.0, 1.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	glTranslatef(1.0, 0.0, 0.0);
	prisma();
	*/
    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 't':
	case 'T':
		angleZ += 0.2f;
		printf("Rotacion en Z: %f\n", angleZ);
		break;
	case 'g':
	case 'G':
		angleZ -= 0.2f;
		printf("Rotacion en Z: %f\n", angleZ);
		break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;
		case 'q':
		case 'Q':
			transY += 0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'e':
		case 'E':
			transY -= 0.2f;
			printf("Posicion en Y: %f\n", transX);
			break;
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



