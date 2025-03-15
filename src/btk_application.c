#include "btk.h"

#include <stdint.h>
#include <stdlib.h>



BTKApplication* btk_application_create(BTKApplicationFlags flags) {
    BTKApplication* app = malloc(sizeof(BTKApplication));
    if (!app) { return NULL; }

    app->window_count = 0;
    app->windows = NULL;


    return app;
}


void btk_application_destroy(BTKApplication* app) {
    if (app->windows) { free(app->windows); }
    free(app);

}