#pragma once
#include <unordered_map>
#include <initializer_list>

class ShaderProgram {
private:
	unsigned int id = 0;
	std::unordered_map<const char*, int> uniformLocations;

public:
	ShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
	~ShaderProgram();

	static unsigned int createShader(const char* src, GLenum type);
	static unsigned int createShader(std::initializer_list<const char*> srcs, GLenum type);

	int getUniformLocation(const char* uniformName);

	void use();
};