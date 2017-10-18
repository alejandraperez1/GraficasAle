#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
#include<vector>

class Mesh {
public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount);
	void Draw(GLenum primitive);
	void SetPositionAttribute(glm::vec2 positions, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(glm::vec3 positions, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(glm::vec3 colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(glm::vec4 colors, GLenum usage, GLuint locationIndex);

private:
	GLuint _vertexArrayObject;
	GLuint _positionsVertexBufferObject;
	GLuint _colorsVertexBufferObject;
	GLint _vertexCount;
	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);


};
