/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
#include<vector> //Lista de elementos
#include "InputFile.h"

GLuint vao; //Identificador del manager de VBOs para un conjunto de vertices

GLuint shaderProgram; //Identificador del manager de shaders (ShaderProgram)


double rad1 = 1.0;
double rad2 = 0.5;


double a = glm::radians(306.0);
double b = glm::radians(18.0);
double c = glm::radians(90.0);
double d = glm::radians(162.0);
double e = glm::radians(234.0);

double px = glm::cos(a);
double py = glm::sin(a);
double px1 = glm::cos(b);
double py1 = glm::sin(b);
double px2 = glm::cos(c);
double py2 = glm::sin(c);
double px3 = glm::cos(d);
double py3 = glm::sin(d);
double px4= glm::cos(e);
double py4 = glm::sin(e);




//Funcion que va a inicializar toda la menoria del programa.
void Initialize() {
	std::vector<glm::vec2> positions;// Vamos a crear una lista que va a almacenar las posiciones 
		//en 2 dimensiones de un triangulo.     Esto es en CPU y RAM.
	positions.push_back(glm::vec2((rad1*px), (rad1*py)));
	positions.push_back(glm::vec2((rad2*px), (rad2*py)));
	positions.push_back(glm::vec2((rad1*px1), (rad1*py1)));
	positions.push_back(glm::vec2((rad2*px1), (rad2*py1)));
	positions.push_back(glm::vec2((rad1*px2), (rad1*py2)));
	positions.push_back(glm::vec2((rad2*px2), (rad2*py2)));
	positions.push_back(glm::vec2((rad1*px3), (rad1*py3)));
	positions.push_back(glm::vec2((rad2*px3), (rad2*py3)));
	positions.push_back(glm::vec2((rad1*px4), (rad1*py4)));
	positions.push_back(glm::vec2((rad2*px4), (rad2*py4)));
	positions.push_back(glm::vec2((rad1*px), (rad1*py)));
	positions.push_back(glm::vec2((rad2*px), (rad2*py)));

	//Vamos a crear una lista para almacenar colores RGB
	std::vector<glm::vec3> colors; //Esta lista esta en CPU y RAM
		//Cuidado con la posicion, OpenGL los lee de izq a der.
		//RGB
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));





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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); //Ya no quiero utilizar el VAO. Ya no se asociaran mas VBOs a este VA

	InputFile ifile;

	//Leemos el código fuente del vertex shader con la clase auxiliar InputFile
	ifile.Read("Default.vert"); //Abre este achivo y leelo
	//Obtenemos los contenidos leidos y los almacenamos en un string vertexSource
	std::string vertexSource = ifile.GetContents(); //Ya lo leyo y ahora me regresa los contenidos. Se esta guardando en la variable "vertexSource"
	//Hacemos un cast (conversión de tipo de dato) porque no le podemos mandar strings a OpenGL. 
	//Necesitamos mandarle un const GLchar*
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	//Creamo un shader de tipo Vertex Shader y guardamos su id en la variable vertexShaderHandle
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	//Le mandamos el código fuente que leimos previamente a OpenGl
	glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
	//Le pedimos que lo compile.
	glCompileShader(vertexShaderHandle);

	GLint vertexShaderCompileSuccess = 0;
	glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &vertexShaderCompileSuccess);
	if (vertexShaderCompileSuccess == GL_FALSE)
	{
		GLint logLength = 0;
		glGetShaderiv(vertexShaderHandle, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0)
		{
			std::vector<GLchar> compileLog(logLength);
			glGetShaderInfoLog(vertexShaderHandle, logLength, &logLength, &compileLog[0]);

			for (int i = 0; i < logLength; i++)
			{
				std::cout << compileLog[i];
			}
			std::cout << std::endl;
		}
		std::cout << "Shader Defaul.vert did not compiled." << std::endl;
	}

	ifile.Read("Default.frag");
	std::string fragmentSource = ifile.GetContents();
	const GLchar* fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandle);

	//Creando el manger de los shaders. Almacenasmo el id en la variable shaderProgram
	shaderProgram = glCreateProgram();
	//Este manager va a administrar el vertex shader con identificador vertexShaderHandle
	glAttachShader(shaderProgram, vertexShaderHandle);
	//Este manager va a administrar el fragment shader con el identificador fragmentShaderHandle
	glAttachShader(shaderProgram, fragmentShaderHandle);
	//Asociamos el indice de buffer (VBO) de posiciones con el nombre de la variable correspondiente en el shader
	glBindAttribLocation(shaderProgram, 0, "VertexPosition");
	//Asociamos el indice de buffer (VBO) de colores con el nombre de la variable corrrepondiente en el shader
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//Verificamos que las etapas de los shaders pueden trabajar en conjunto
	glLinkProgram(shaderProgram);

}


 void MainLoop(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Borramos el buffer de color y profundidad.  SIEMPRE AL INICIO DE UN NUEVO FRAME
		
		//Paso 1 Activar el programa shader
	glUseProgram(shaderProgram);
	
	//Paso 2 Activar un VAO
	glBindVertexArray(vao);

		//Paso 3 Dibujamos
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);

		//Paso 4 Desactivamos el VAO
	glBindVertexArray(0);
	
		//Paso 5:Desactivar el programa shader(manager)
	glUseProgram(0);
		
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
		
		glutCreateWindow("Examen pentagono");
		//Creamos y abrimos la ventana con un titulo personalizado
		
		glutDisplayFunc(MainLoop);
	//Asociamos una funcion de render. Se mandara a llamar para dibujar un frame.
		
		glewInit(); //Inicializamos GLEW.
		//Esta liberia se encarga de obtener el API de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
		
		glClearColor(1.0f, 1.0f, 0.5f, 1.0f); //Configurar OpenGL
		//Colorpor default del buffer de color en el framebuffer.

		std::cout << glGetString(GL_VERSION) << std::endl;

		Initialize(); //Configurar la memoria que la aplicacion va a necesitar
		
		glutMainLoop();//Iniciamos la aplicacion grafica.
		//El main se pausara en esta linea hasta que se cierre la ventana

		return 0;
}