#include "Mesh.h"

#include <fstream>
#include <iostream>
#include <sstream>

Mesh::Mesh() {
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &_vertexArrayObject);
}

void Mesh::CreateMesh(GLint vertexCount) {
	_vertexCount = vertexCount;
	glGenVertexArrays(vertexCount,&_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive) {
	glBindVertexArray(_vertexArrayObject);
	glDrawArrays(GL_TRIANGLE_STRIP, primitive, _vertexCount);
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(glm::vec2 positions, GLenum usage, GLuint locationIndex) {
	glGenBuffers(_vertexCount, &_positionsVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, _positionsVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions)*locationIndex, &usage, GL_STATIC_DRAW);
	
}

void Mesh::SetPositionAttribute(glm::vec3 positions, GLenum usage, GLuint locationIndex) {
	glGenBuffers(_vertexCount, &_positionsVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, _positionsVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions)*locationIndex, &usage, GL_STATIC_DRAW);
}

void Mesh::SetColorAttribute(glm::vec3 colors, GLenum usage, GLuint locationIndex) {
	glGenBuffers(_vertexCount, &_colorsVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, _colorsVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors)*locationIndex, &usage, GL_STATIC_DRAW);
}

void Mesh::SetColorAttribute(glm::vec4 colors, GLenum usage, GLuint locationIndex) {
	glGenBuffers(_vertexCount, &_colorsVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, _colorsVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors)*locationIndex, &usage, GL_STATIC_DRAW);
}

void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components) {
	
}