#version 330 core

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;
//in vec4 vertexColor; 
//in vec2 TexCoord;
//uniform vec4 ourColor; 
//uniform sampler2D ourTexture;
//uniform sampler2D ourFace;
uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 cameraPos;
void main()
{
	//FragColor = vertexColor;
	//FragColor = texture(ourTexture,TexCoord) * texture(ourFace,TexCoord);
	
	
	vec3 lightDir = normalize(lightPos - FragPos);

	vec3 reflectVec = reflect(-lightDir ,Normal);
	vec3 cameraVec = normalize(cameraPos - FragPos);

	float specularAmount = pow(max(dot(reflectVec,cameraVec),0),32);
	vec3 specular = specularAmount * lightColor;

	vec3 diffuse = max(dot(lightDir , Normal),0) * lightColor;
	FragColor=vec4( (ambientColor  + diffuse + specular) * objColor ,1.0f);
}