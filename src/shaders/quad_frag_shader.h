#pragma once

const char* quad_frag_shader = R"glsl(
#version 330 core

out vec4 FragColor;

void main() {
	FragColor = vec4(0.2f, 0.3f, 0.8f, 1.0f);
}
)glsl";