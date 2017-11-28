/*********************************************************
Materia: Gráficas Computacionales
Fecha: 28  de Noviembre del 2017
Autor: A01373993  Alejandra María Pérez Alemán
*********************************************************/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include <IL/il.h>
#include "Texture2D.h"


Camera _camera;
Mesh _mesh;

ShaderProgram _shaderProgram;
glm::vec3 LightColor;
glm::vec3 PixelPosition;
glm::vec3 LightPosition;
glm::vec3 CameraPosition;
Texture2D myTexture;
Texture2D tex2;
Texture2D p;
Transform _transform;
Transform _t2;
Transform _t3;
Transform _t4;
Transform _t5;
Transform _t6;
Transform _piso;
Transform _t2joint;
Transform _t3joint;
Transform _t4joint;
Transform _t5joint;
Transform _t6joint;
float angulo = 0.0f;
float delta = 0.05f;


// Función que va a inicializar toda la memoria del programa.
void Initialize()
{



	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-3.0f, -0.20f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -0.20f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.20f, 3.0f));
	// Cara lateral derecha
	positions.push_back(glm::vec3(3.0f, -0.20f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, 3.0f));
	// Cara Atras
	positions.push_back(glm::vec3(3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.20f, -3.0f));
	// Cara lateral izquierda
	positions.push_back(glm::vec3(-3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.20f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.20f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.20f, -3.0f));
	// Cara Top
	positions.push_back(glm::vec3(-3.0f, 0.20f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.20f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.20f, -3.0f));
	// Cara Abajo
	positions.push_back(glm::vec3(-3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -0.20f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -0.20f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.20f, 3.0f));


	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// Cara Atras
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	// Cara lateral Izquierda
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	// Cara Top
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	// Cara Abajo
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));


	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7,8,9,10,9,11,10,12,13,14,12,14,15,16,17,18,16,18,19,20,21,22,20,22,23 };

	std::vector<glm::vec3> Normal;
	//Cara Frente 
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara Derecha 
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Atras
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara Arriba 
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Abajo 
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2>TexCoords;
	//Cara Frente 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Derecha
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Izquierda 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Atras 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Arriba 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Abajo
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));


	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(Normal, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(TexCoords, GL_STATIC_DRAW, 3);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);


	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Texture.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Texture.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");
	_shaderProgram.LinkProgram();

	//Posiciones
	_transform.SetPosition(0.0f, 0.0f, -20.0f);
	_t2.SetPosition(3.20f, 0.0f, 0.0f);
	_t4.SetPosition(-3.20f, 0.0f, 0.0f);
	_t3.SetPosition(0.0f, 0.0f, 3.20f);
	_t5.SetPosition(0.0f, 0.0f, -3.20f);
	_t6.SetPosition(3.20f, 0.0f, 0.0f);
	_piso.SetPosition(0.0f, -10.0f, -20.0f);


	//Posiciones joint

	_t3joint.SetPosition(0.0f, 0.0f, 3.0f);
	_t5joint.SetPosition(0.0f, 0.0f, -3.0f);
	_t4joint.SetPosition(-3.0f, 0.0f, 0.0f);
	_t2joint.SetPosition(3.0f, 0.0f, 0.0f);
	_t6joint.SetPosition(3.0f, 0.0f, 0.0f);

	LightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	LightPosition = glm::vec3(-5.0, 5.0, 5.0);
	CameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	_camera.SetPosition(0.0f, 5.0f, 12.0f);
	
	_piso.SetScale(20.0f, 2.0f, 20.0f);

	myTexture.LoadTexture("Princess_Cookie1.png");
	tex2.LoadTexture("Gal.jpg");
	p.LoadTexture("descarga.jpg");
	





}

void MainLoop()
{
	angulo += delta;
	if (angulo >= 90.0f)
		delta = -0.05f;
	if (angulo <= 0.0f)
		delta = 0.05;

	_t2joint.SetRotation(0.0f, 0.0f, angulo);
	_t3joint.SetRotation(-angulo, 0.0f, 0.0f);
	_t4joint.SetRotation(0.0f, 0.0f, -angulo);
	_t5joint.SetRotation(angulo, 0.0f, 0.0f);
	_t6joint.SetRotation(0.0f, 0.0f, angulo);

	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.01f, 0.01f, 0.01f, true);

	_shaderProgram.Activate();




	//BASE
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();


	//CARA 2-DERECHA
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();

	//CARA 3- ABAJO

	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix() * _t3joint.GetModelMatrix() * _t3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix() * _t3joint.GetModelMatrix() * _t3.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _t3joint.GetModelMatrix() * _t3.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();

	//CARA 4- IZQUIERDA
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _t4joint.GetModelMatrix() * _t4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix() * _t4joint.GetModelMatrix() * _t4.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _t4joint.GetModelMatrix() * _t4.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();

	//CARA 5- ARRIBA
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix() * _t5joint.GetModelMatrix() * _t5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix() * _t5joint.GetModelMatrix() * _t5.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _t5joint.GetModelMatrix() * _t5.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();

	//Cara extra
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("Otra", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix()* _t6joint.GetModelMatrix() * _t6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix()* _t6joint.GetModelMatrix() * _t6.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _t2joint.GetModelMatrix() * _t2.GetModelMatrix()* _t6joint.GetModelMatrix() * _t6.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	tex2.Unbind();

	
	//Piso
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _piso.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _piso.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", LightColor);
	_shaderProgram.SetUniformf("LightPosition", LightPosition);
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_piso.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	p.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	p.Unbind();

	_shaderProgram.Deactivate();





	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();

}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 1000.0f, 60.0f,/*aR(aspectRatio)=width/height*/ (float) /*<- eso es tipo de variable al que quiero llegar*/width / (float)height);
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}