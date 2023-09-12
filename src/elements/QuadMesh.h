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
		unsigned int QuadVao = 0;
		glGenVertexArrays(1, &QuadVao);
		glBindVertexArray(QuadVao);

		unsigned int QuadVbo = 0;
		glGenBuffers(1, &QuadVbo);
		glBindBuffer(GL_ARRAY_BUFFER, QuadVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), VERTICES, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

		unsigned int QuadEbo = 0;
		glGenBuffers(1, &QuadEbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QuadEbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return QuadVao;
	}
}