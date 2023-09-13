#include <iostream>
#include <glad\glad.h>
#include "ShaderProgram.h"

unsigned int ShaderProgram::createShader(const char* src, GLenum type) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    return shader;
}

unsigned int ShaderProgram::createShader(std::initializer_list<const char*> srcs, GLenum type) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, srcs.size(), srcs.begin(), NULL);
    glCompileShader(shader);

    return shader;
}

ShaderProgram::ShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int _id = glCreateProgram();

    glAttachShader(_id, vertexShader);
    glAttachShader(_id, fragmentShader);
    glLinkProgram(_id);

    glDetachShader(_id, vertexShader);
    glDeleteShader(vertexShader);

    glDetachShader(_id, fragmentShader);
    glDeleteShader(fragmentShader);

    this->id = _id;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->id);
}

int ShaderProgram::getUniformLocation(const char* uniformName) {
    ShaderProgram& self = *this;

    if (self.uniformLocations.count(uniformName) == 0) {
        int loc = glGetUniformLocation(self.id, uniformName);
        self.uniformLocations[uniformName] = loc;
        return loc;
    }
    else {
        return self.uniformLocations[uniformName];
    }
}

void ShaderProgram::use() {
    glUseProgram(this->id);
}