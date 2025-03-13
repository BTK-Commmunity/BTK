#ifndef BTK_APPLICATION_H
#define BTK_APPLICATION_H


#include "btk_window.h"


typedef struct {
    BTKWindow** windows;
    int window_count;
} BTKApplication;


typedef struct {} BTKApplicationFlags;


BTKApplication* btk_application_create();
void btk_application_destroy(BTKApplication* app);


void btk_application_run(BTKApplication* app);

void btk_application_window_add(BTKApplication* app,BTKWindow* window);



#endif // BTK_APPLICATION_H