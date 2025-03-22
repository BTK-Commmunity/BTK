#include "btk.h"

#include <GLFW/glfw3.h>



#include <stdint.h>
#include <stdlib.h>



BTKApplication* btk_application_create(BTKApplicationFlags flags) {
    BTKApplication* app = malloc(sizeof(BTKApplication));
    if (!app) { return NULL; }

    app->window_count = 0;
    app->windows = NULL;

    app->flags = flags;

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11); // TODO: remove for non dev releases
    if (!glfwInit()) {
        BTK_LOG_ERROR("Failed to initialize GLFW");
        free(app);
        return NULL;
    }

    switch (app->flags.renderingBackend) {
        case OPENGL:
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            break;

        case VULKAN:
            BTK_LOG_WARN("Vulkan backend not implemented yet. Please switch to OpenGL for now");
            // glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // tell glfw to not create a context because we do that ourself in vulkan
            free(app);
            return NULL;
    }

    return app;
}


void btk_application_destroy(BTKApplication* app) {
    if (!app) { return; }
    if (app->windows) {
        for (uint32_t i = 0; i < app->window_count; i++) {
            btk_window_destroy(app->windows[i]);
        }
        free(app->windows);
    }
    free(app);
}


void btk_application_run(BTKApplication* app) {
    if (!app) { return; }
    while (1) {
        for (uint32_t i = 0; i < app->window_count; i++) {
            btk_window_poll_events(app->windows[i]);
            if (glfwWindowShouldClose(app->windows[i]->win)) {
                btk_window_destroy(app->windows[i]);
            }
        }

    }

}