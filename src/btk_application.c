#include "btk_application.h"
#include "btk_window.h"
#include <GLFW/glfw3.h>
#include <btk/btk_application.h>
#include <stdbool.h>
#include <stdlib.h>



BTKApplication* btk_application_create(BTKApplicationFlags flags) {
    BTKApplication* app = malloc(sizeof(BTKApplication));

    if (!app) { return NULL; }
    
    app->window_count = 0;
    app->windows = NULL;

    if (!glfwInit()) { return NULL; }

    return app;
}

void btk_application_destroy(BTKApplication* app) {
    if (!app) { return; }

    free(app->windows);
    free(app);


    glfwTerminate();
}



void btk_application_run(BTKApplication* app) {
    while (app->window_count > 0) {
        for (int i = 0; i < app->window_count; i++) {
            if(glfwWindowShouldClose(app->windows[i]->window)) {
                btk_window_destroy(app->windows[i]);
            }
        }
    }
}

void btk_application_window_add(BTKApplication* app,BTKWindow* window) {
    if (!app) { return; }
    if (!window) { return; }

    size_t new_count = app->window_count + 1;

    BTKWindow** new_windows = realloc(app->windows, sizeof(BTKWindow*) * new_count);

    if (!new_windows) { return; }

    app->windows = new_windows;
    app->windows[app->window_count] = window;
    app->window_count = new_count;
}

