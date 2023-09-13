#include <iostream>
#include "Game.h"
#include "shaders\ShaderProgram.h"
#include "shaders\quad_vert_shader.h"
#include "shaders\quad_frag_shader.h"
#include "elements\QuadMesh.h"

int main() {
    Game* game = new Game(800, 600, "Sand Simulation", 3, 3);

    unsigned int vertexShader = ShaderProgram::createShader(quad_vert_shader, GL_VERTEX_SHADER);
    unsigned int fragmentShader = ShaderProgram::createShader(quad_frag_shader, GL_FRAGMENT_SHADER);
    ShaderProgram quadProgram(vertexShader, fragmentShader);

    int quadVao = QuadMesh::generateVao();

    int windowWidth = 0, windowHeight = 0;
    while (!glfwWindowShouldClose(game->window)) {
        glfwGetWindowSize(game->window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        quadProgram.use();
        glBindVertexArray(quadVao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwPollEvents();
        glfwSwapBuffers(game->window);
    }

    glfwTerminate();
    delete game;
}