#pragma once

namespace QuadMesh {
	float VERTICES[] = {
	   -1.0f,  1.0f, 0.0f, // Top left
		1.0f,  1.0f, 0.0f, // Top right
		1.0f, -1.0f, 0.0f, // Bottom right
	   -1.0f, -1.0f, 0.0f, // Bottom left
	};

	unsigned int INDICES[] = {
		0, 1, 2,
		2, 3, 0
	};

	unsigned int generateVao() {
		unsigned int quadVao = 0;
		glGenVertexArrays(1, &quadVao);
		glBindVertexArray(quadVao);

		unsigned int quadVbo = 0;
		glGenBuffers(1, &quadVbo);
		glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), VERTICES, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

		unsigned int quadEbo = 0;
		glGenBuffers(1, &quadEbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadEbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);

		return quadVao;
	}
}