#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;


struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
	sampler2D diffuseMapTex;
};

uniform Material material;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

vec3 getLightDir()
{
	return (lightPos - FragPos);
}

vec3 getDiffuseLight() 
{	
	vec3 lightDir = getLightDir();
	vec3 lightDirNormalized = normalize(lightDir);
	vec3 normalNormalized = normalize(Normal);
	float lightNormalDot =  dot(normalize(Normal), normalize(lightDir));
	
	float diffuseIntensity = pow(max(0, lightNormalDot), 2);

	vec3 diffuseLight = diffuseIntensity * vec3(texture(material.diffuseMapTex, TexCoords)) * lightColor;
	return diffuseLight;
}

vec3 getSpecular()
{
	vec3 lightDir = getLightDir();
	vec3 viewDir = (cameraPos - FragPos);
	vec3 reflectedDir = reflect(-lightDir, Normal);

	float viewReflectedDot = dot(normalize(reflectedDir), normalize(viewDir));
	float specIntensity = pow(max(0, viewReflectedDot), material.shininess);

	return specIntensity * material.specular * lightColor;
}

void main()
{
	vec3 diffuseLight = getDiffuseLight();
	vec3 specular = getSpecular();
	vec3 ambientColor = material.ambient * vec3(texture(material.diffuseMapTex, TexCoords));
	vec3 totalLight = (diffuseLight  + ambientColor + specular);
	FragColor = vec4(totalLight, 1.0F);
}

