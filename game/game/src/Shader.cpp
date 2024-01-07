#include <Shader.h>
#include <iostream>
#include <fstream>
#include <sstream>
#define GlEW_STATIC 
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

using namespace std;
Shader::Shader(const char * vertexPath,const char * fragmentPath) {

	ifstream vertexFile;
	ifstream fragmentFile;
	stringstream vertexSStream;
	stringstream fragmentSStream;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);

	// ����ڶ�ȡ�ļ�ʱ����ʧ�ܣ������� failbit ��־λ
	// ����ڵײ�����������ʱ�������� badbit ��־λ
	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmentFile.exceptions(ifstream::failbit || ifstream::badbit);

	try
	{
		if (!vertexFile.is_open() || !fragmentFile.is_open()) {
			throw exception("open file error");
		}
		//�����ַ���
		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();
		
		//�ַ���תstring
		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();

		//ת��ΪC����ַ���
		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();

		unsigned int vertex, fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex,1,&vertexSource,NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex,"VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");

		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		checkCompileErrors(ID, "PROGRAM");


		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

void Shader::use() {
	glUseProgram(ID);
}

void Shader::checkCompileErrors(unsigned int ID, std::string type) {
	
	int success;
	char infoLog[512];

	if (type!="PROGRAM")
	{
		//��ѯ��ɫ������ı�����Ϣ
		glGetShaderiv(ID,GL_COMPILE_STATUS,&success);
		if (!success)
		{
			glGetShaderInfoLog(ID,512,NULL,infoLog);
			cout << "shader compile error:" << infoLog << endl;
		}
		
	}
	else
	{
		glGetProgramiv(ID,GL_LINK_STATUS,&success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			cout << "program linking error:" << infoLog << endl;
		}
	}

};