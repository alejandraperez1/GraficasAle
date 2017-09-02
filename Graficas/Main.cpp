/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<glm/glm.hpp>
#include<vector> //Lista

GLuint vao; //Identificador del manager de VBOs para un conjunto de vertices

//Funcion que va a inicializar toda la menoria del programa.
void Initialize() {
	std::vector<glm::vec2> positions;// Vamos a crear una lista que va a almacenar las posiciones 
	//en 2 dimensiones de un triangulo.     Esto es en CPU y RAM.
	positions.push_back(glm::vec2(-1.0f, -1.0f)); //Posicionesde la "lista" (vector)
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	//Vamos a crear una lista para almacenar colores RGB
	std::vector<glm::vec3> colors; //Esta lista esta en CPU y RAM
	//Cuidado con la posicion, OpenGL los lee de izq a der.
	//RGB
	colors.push_back(glm::vec3(1.0f,0.0f, 0.0f));
	colors.push_back(glm::vec3( 0.0f,1.0f,0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f,1.0f));


	glGenVertexArrays(1, &vao);//Creamos un VAO y almacenamos el id en la variable vao.
	//Este es el manager de VBOs
	glBindVertexArray(vao); //Le decimos a OpenGL que lo queremos utilizar
	//Todos los VBOs que creemos a partir de este punto y hasta que desactivemos este VAo, se va a asociar a este manager

	//Entero sin signo GLuint, numero entero
	GLuint positionsVBO; //Identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	glGenBuffers(1, &positionsVBO); //Creamos un VBO y almacenamos el id en la variable positionsVBO
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //Le decimos a OpenGL que lo queremos utilizar como un atributo
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//Asignamos los datos al buffer y losmandamos a la tarjeta de video
	glEnableVertexAttribArray(0);//Quiero activar el atributo con indice 0 en la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);//Configuramos el atributo con indice 0 en la tarjeta de video.
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Desactivamos el uso del VBO de posiciones

	GLuint colorsVBO; //Ya estan en la tarjeta de video
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE,0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); //Ya no quiero utilizar el VAO. Ya no se asociaran mas VBOs a este VA
}


void MainLoop() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Borramos el buffer de color y profundidad.  SIEMPRE AL INICIO DE UN NUEVO FRAME


	//Paso 1 No lo podemos hacer aun

	//Paso 2 Activar un VAO
	glBindVertexArray(vao);

	//Paso 3 Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//Paso 4 Desactivamos el VAO
	glBindVertexArray(0);

	//Paso 5: Aun no lo podemos hacer


	glutSwapBuffers();
	//Intercambiamos los buffers (el que se estaba rendereando con el que se estaba mostrando)
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv); //Inicializamos freeglut.
	//Freeglut se encarga de generar y manejar ventanas. Lo utilizamos para crearuna ventana donde vamso a dibujar

	glutInitContextProfile(GLUT_CORE_PROFILE);
	//Tenemos que informar que queremos trabajar con el pipeline programable (OpenGL moderno)/

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

	Initialize(); //Configurar la memoria que la aplicacion va a necesitar

	glutMainLoop();//Iniciamos la aplicacion grafica.
	//El main se pausara en esta linea hasta que se cierre la ventana

	return 0;
}