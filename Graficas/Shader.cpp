#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader() {
	_shaderHandle = 0;
}

Shader::~Shader() {
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type) {
	std::string vertexSource = path;
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	_shaderHandle = glCreateShader(type);
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	glCompileShader(_shaderHandle);
}
GLuint Shader::GetHandle() {
	return _shaderHandle;
}