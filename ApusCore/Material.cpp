#include <iostream>

#include "Material.h"


void ApusCore::Material::_Compile() {
	program = glCreateProgram();
	glAttachShader(program, vs.id);
	glAttachShader(program, fs.id);
	glLinkProgram(program);
	glValidateProgram(program);
	glUseProgram(program);
}

void ApusCore::Material::Bind() {
	glUseProgram(program);
}

void ApusCore::Material::Destroy() {
	glDeleteProgram(program);
}
