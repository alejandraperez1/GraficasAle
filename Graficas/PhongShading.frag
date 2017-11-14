#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;
uniform vec3 LightColor;

void main()
{
	FragColor = vec4(InterpolatedColor, 1.0f);
	vec3 ambient = 0.1f * LightColor;
}