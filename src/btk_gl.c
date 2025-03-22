#include "btk.h" 



#include "external/glad/glad.h"
#include <GLFW/glfw3.h>



// Internal functions
void framebuffer_size_callback_(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
}

void btk_gl_load(BTKApplication* app) {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        BTK_LOG_ERROR("Failed to initialize GLAD");
        return;
    }

    for (uint32_t i = 0; i < app->window_count; i++) {
        if (app->windows[i]->flags.resizeable) {
            glfwSetFramebufferSizeCallback(app->windows[i]->win, framebuffer_size_callback_);
        }
    }
}

void btk_gl_set_viewport(BTKWindow *window) {
    glfwMakeContextCurrent(window->win);
    glViewport(0, 0, btk_window_get_width(window), btk_window_get_height(window));
}




