#version 330

in vec3 InterpolatedColor;
in vec3 PixelPosition;
in vec3 InterpolatedNormal;
in vec2 InterpolatedTexCoord;


out vec4 FragColor;


uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 CamaraPosition;
uniform sampler2D DiffuseTexture;

void main()
{
	
	
	vec3 ambient = 0.1f * LightColor;
	vec3 L= LightPosition-PixelPosition;
	L=normalize(L);
	vec3 diffuse= dot(InterpolatedNormal,L)* LightColor;
	vec3 R= reflect(-L, InterpolatedNormal);
	R=normalize(R);
	vec3 V= (CamaraPosition-PixelPosition);
	V=normalize(V);

	vec3 specular = 0.5f * pow(dot(V,R),32)*LightColor;
	vec3 phongShading= (ambient+ diffuse+ specular);

	FragColor= vec4(phongShading, 1.0f) * texture2D(DiffuseTexture, InterpolatedTexCoord);
	
	
}