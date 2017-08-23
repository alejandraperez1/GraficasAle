/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>
#include<GL/glew.h>
#include<GL/freeglut.h>

void MainLoop() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Borramos el buffer de color y profundidad.  SIEMPRE AL INICIO DE UN NUEVO FRAME

	//WARNING!!!!  Esto es OpenGL clasico y no lo vamos a colver a usar en todo el semestre
	glBegin(GL_TRIANGLES); //Dibujar triangulos
	glColor3f(1.0f, 0.0f, 0.0f); //Asignar color
	glVertex2f(-1.0f, -1.0f); //f porque es flotante y 2 porque es x/y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);

	glEnd();
	//FIN DEL WARNING...

	glutSwapBuffers();
	//Intercambiamos los buffers (el que se estaba rendereando con el que se estaba mostrando)
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv); //Inicializamos freeglut.
	//Freeglut se encarga de generar y manejar ventanas. Lo utilizamos para crearuna ventana donde vamso a dibujar

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	//Tenemos que informar que queremos trabajar con el pipeline clasico (OpenGL viejito)

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Cuando alguien cierre la venta se deja de renderear y terminamos el programa
	//Freeglut pemrite configurar eventos que ocurren en la venta.

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Configuramos el framebuffer
	//RGBA: Buffer de TRUE COLOR( rojo, verde, azul y alpha)
	//DEPTH: Buffer de profundidad, que esta adelante y atras
	//DOUBLE: Buffer para renderear (evitamos parpadeos al renderear, evitamos el cuadro negro)

	glutInitWindowSize(400, 400);
	//Solicitamos una ventana 400x400 pixeles. 
	//No impide que el usuario cambien la ventana, solo dice que la ventana inicial sera de esas medidas

	glutCreateWindow("Hello World OpenGl");
	//Creamos y abrimos la ventana con un titulo personalizado

	glutDisplayFunc(MainLoop);
	//Asociamos una funcion de render. Se mandara a llamar para dibujar un frame.

	glewInit(); //Inicializamos GLEW.
	//Esta liberia se encarga de obtener el API de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f); //Configurar OpenGL
	//Colorpor default del buffer de color en el framebuffer.

	glutMainLoop();//Iniciamos la aplicacion grafica.
	//El main se pausara en esta linea hasta que se cierre la ventana

	return 0;
}