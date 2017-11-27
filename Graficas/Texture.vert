#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;
in vec2 VertexTexCoord;




out vec3 InterpolatedColor;
out vec3 PixelPosition;
out vec3 InterpolatedNormal;
out vec2 InterpolatedTexCoord;


uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;
uniform mat4 modelMatrix;


void main()
{
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	PixelPosition = vec3 (modelMatrix * vec4 (VertexPosition, 1.0));
	InterpolatedNormal= normalMatrix* VertexNormal;
	InterpolatedTexCoord= VertexTexCoord;
	
}