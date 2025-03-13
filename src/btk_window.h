#ifndef BTK_WINDOW_H
#define BTK_WINDOW_H

#include <stdbool.h>
#include <GLFW/glfw3.h>

typedef struct {
    GLFWwindow* window;
} BTKWindow;


typedef struct {
    bool resizeable;
} BTKWindowFlags;


BTKWindow* btk_window_create(const char* title, int height, int width, BTKWindowFlags flags);
void btk_window_destroy(BTKWindow* window);

#endif // BTK_WINDOW_H