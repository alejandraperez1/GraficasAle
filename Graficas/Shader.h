#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>

class Shader {
public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();

private:
	GLuint _shaderHandle;

};