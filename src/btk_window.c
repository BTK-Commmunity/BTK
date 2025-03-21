#include "btk.h"

#include <GLFW/glfw3.h>


#include <stdint.h>
#include <stdlib.h>







BTKWindow* btk_window_create(BTKApplication* app, const char* title, int width, int height, BTKWindowFlags flags) {
    if (!app) { return NULL; }

    BTKWindow* window = malloc(sizeof(BTKWindow));
    if (!window) { return NULL; }


    window->win = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window->win) {
        free(window);
        return NULL;
    }

    window->app = app;
    
    window->app->window_count++;
    window->app->windows = realloc(window->app->windows, window->app->window_count * sizeof(BTKWindow*));

    app->windows[app->window_count - 1] = window;

    return window;
}

void btk_window_destroy(BTKWindow* window) {
    if (!window) { return; }

    uint32_t index = UINT32_MAX;
    for (uint32_t i = 0; i < window->app->window_count; i++) {
        if (window->app->windows[i] == window) {
            index = i;
            break;
        }
    }

    if (index == UINT32_MAX) { return; }

    if (window->win) {
        glfwDestroyWindow(window->win);
    }

    for (uint32_t i = index; i < window->app->window_count - 1; i++) {
        window->app->windows[i] = window->app->windows[i + 1];
    }

    

    BTKWindow** newWindows = realloc(window->app->windows, window->app->window_count - 1 * sizeof(BTKWindow*));
    if (!newWindows) { return; }

    window->app->windows = newWindows;
    window->app->window_count--;
    



    free(window);
}


void btk_window_poll(BTKWindow* window) {
    glfwMakeContextCurrent(window->win);
    glfwPollEvents();
}

void btk_window_set_close_callback(BTKWindow* window, BTKWindowCloseCallbackFunc callback) {
    window->callbacks.closeCallback = callback;
}