#pragma once
#include <unordered_map>

class ShaderProgram {
private:
	unsigned int id = 0;
	std::unordered_map<const char*, int> uniformLocations;

public:
	using ShaderSrcs = std::initializer_list<const char*>;

	ShaderProgram(ShaderSrcs vertexSrcs, ShaderSrcs fragmentSrcs);
	~ShaderProgram();

	int getUniformLocation(const char* uniformName);

	void use();
};