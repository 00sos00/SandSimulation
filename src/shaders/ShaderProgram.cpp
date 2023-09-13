#include <iostream>
#include <vector>
#include <glad\glad.h>
#include "ShaderProgram.h"

void checkCompilation(unsigned int shader, GLenum type) {
    int compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (compiled == GL_TRUE) return;

    int logSize = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
    std::vector<char> infoLog(logSize);
    glGetShaderInfoLog(shader, logSize, NULL, &infoLog[0]);

    switch (type) {
    case GL_VERTEX_SHADER:
        std::cout << "VERTEX_SHADER_ERROR: ";
        break;
    case GL_FRAGMENT_SHADER:
        std::cout << "FRAGMENT_SHADER_ERROR: ";
        break;
    default:
        std::cout << "UNKNOWN_SHADER_ERROR: ";
        break;
    }

    for (char c : infoLog) {
        std::cout << c;
    }
}

void checkLinkage(unsigned int program) {
    int linked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    if (linked == GL_TRUE) return;

    int logSize = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);

    std::vector<char> infoLog(logSize);
    glGetProgramInfoLog(program, logSize, NULL, &infoLog[0]);

    std::cout << "LINKAGE_ERROR: ";
    for (char c : infoLog) {
        std::cout << c;
    }
}

unsigned int createShader(ShaderProgram::ShaderSrcs srcs, GLenum type) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, srcs.size(), srcs.begin(), NULL);
    glCompileShader(shader);

    checkCompilation(shader, type);

    return shader;
}

ShaderProgram::ShaderProgram(ShaderProgram::ShaderSrcs vertexSrcs, ShaderProgram::ShaderSrcs fragmentSrcs) {
    unsigned int vertexShader = createShader(vertexSrcs, GL_VERTEX_SHADER);
    unsigned int fragmentShader = createShader(fragmentSrcs, GL_FRAGMENT_SHADER);
    unsigned int _id = glCreateProgram();

    glAttachShader(_id, vertexShader);
    glAttachShader(_id, fragmentShader);
    glLinkProgram(_id);

    checkLinkage(_id);

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