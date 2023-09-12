#include <iostream>
#include "Game.h"

int main() {
    Game* game = new Game(800, 600, "Sand Simulation", 3, 3);

    int windowWidth = 0, windowHeight = 0;
    while (!glfwWindowShouldClose(game->window)) {
        glfwGetWindowSize(game->window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(game->window);
    }

    glfwTerminate();
    delete game;
}