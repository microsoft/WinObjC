#include "shadower.h"
#include "teges.h"

//#include <stdio.h>
//#include <string.h>
//#include <math.h>

ShaderTrl::ShaderTrl(const char* _resourceString, GLenum _type) : SimpleTrl(_resourceString) {
	type = _type;
}

bool ShaderTrl::equals(ShaderTrl* trl) {
	if(type == trl->type && SimpleTrl::equals(trl)) return true;
	else return false;
}

char* ShaderTrl::getString() {
	return resourceString;
}


Shader::~Shader() {
	logger(3, "Freeing shader %s", resourceLocation->getString());
	//glDeleteShader(handle);
}


Shadering::Shadering(Teges* _engine) : TegesObject(_engine), shadower(_engine->getShadower())
{ }


Shadower::Shadower(const char* _resourceDir, bool _shadersEnabled)
	: resourceDir(_resourceDir), ShaderManager(_shadersEnabled)
{
	//TODO: Check for opengl2 or load extenstions
}


Shadower::~Shadower()
{ }


Shader* Shadower::createResource() {
	return new Shader;
}


GLuint* Shadower::loadResource(ShaderTrl* resourceLocation) {
	char* fileName = new char[strlen(resourceDir) + strlen(resourceLocation->resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceLocation->resourceString);
	logger(2, "Loading %s", fileName, resourceLocation->type);
	GLuint* ret = new GLuint;
	*ret = glCreateShader(resourceLocation->type);

	FILE* inputFile = fopen(fileName, "r");
	if(inputFile == NULL) {
		return NULL;
	}

	fseek(inputFile, 0, SEEK_END);
	GLint len = ftell(inputFile) + 1;
	rewind(inputFile);
	char* source = new char[len];
	source[0] = '\0';
	char line[1024];

	while(fgets(line, 1024, inputFile) != NULL) {
		strncat(source, line, 1024);
	}

	const GLchar* src = source;

	glShaderSource(*ret, 1, &src, &len);
	glCompileShader(*ret);

	int ok;
	glGetShaderiv(*ret, GL_COMPILE_STATUS, &ok);

	if(ok != GL_TRUE) {
		char errorlog[8192];
		GLsizei len;
		glGetShaderInfoLog(*ret, 8192, &len, errorlog);
		logger(-1, "Problems with shader compilation! Errorlog:\n%s", errorlog);
	}

	delete [] source;
	return ret;
}

