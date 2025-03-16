#include <btk/btk.h>



int main() {
    BTKApplication* app = btk_application_create(BTK_APPLICATION_FLAGS_DEFAULT);

    BTKWindow* window = btk_window_create(app, "Hello World", 800, 600, BTK_WINDOW_FLAGS_DEFAULT);

    BTKWindow* window2 = btk_window_create(app, "Hello World 2", 800, 600, BTK_WINDOW_FLAGS_DEFAULT);
    
    btk_application_run(app);
}