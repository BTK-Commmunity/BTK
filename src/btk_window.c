#include "btk_window.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>




BTKWindow* btk_window_create(const char* title, int height, int width, BTKWindowFlags flags) {
    BTKWindow* win = malloc(sizeof(BTKWindow));
    win->window = glfwCreateWindow(width, height, title, NULL, NULL);


    return win;
}



void btk_window_destroy(BTKWindow* window) {
    glfwDestroyWindow(window->window);
}