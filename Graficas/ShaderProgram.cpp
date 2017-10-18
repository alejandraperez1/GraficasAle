#include "ShaderProgram.h"

#include <fstream>
#include <iostream>
#include <sstream>

ShaderProgram::ShaderProgram() {
	_programHandle = 0;
	_attachedShaders = _attachedShaders;
}

ShaderProgram::~ShaderProgram() {
	DeleteProgram();
}

void ShaderProgram::CreateProgram() {
	_programHandle= glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type) {
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram() {
	glAttachShader(_programHandle, _attachedShaders._Get_data);
}

void ShaderProgram::Activate() {
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate() {
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
	glBindAttribLocation(_programHandle, locationIndex, name.c_str);
}

void ShaderProgram::SetUniformf(std::string name, float value) {
	glBindAttribLocation(_programHandle, value, name.c_str);
	glLinkProgram(_programHandle);
}
void ShaderProgram::SetUniformf(std::string name, float x, float y) {

}
void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {

}
void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {

}
void ShaderProgram::DeleteAndDetachShaders() {
	glDetachShader(_programHandle, _attachedShaders.data);
	glDeleteShader(_attachedShaders.data);
}
void ShaderProgram::DeleteProgram() {
	glDetachShader(_programHandle, _attachedShaders.push_back);
	glDeleteShader(_programHandle);
}