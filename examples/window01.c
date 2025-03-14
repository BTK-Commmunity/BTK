#include <btk/btk_application.h>
#include <btk/btk_window.h>
#include <stdbool.h>

int main() {
    BTKApplication* app = btk_application_create(BTK_APPLICATION_FLAGS_DEFAULT);

    BTKWindow* win = btk_window_create("Hello", 800, 600, (BTKWindowFlags){.resizeable = false});


    btk_application_window_add(app, win);

    btk_application_run(app);
}