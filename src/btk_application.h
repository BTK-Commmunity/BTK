#ifndef BTK_APPLICATION_H
#define BTK_APPLICATION_H


#include "btk_window.h"
#include "btk_internal.h"


typedef struct {
    BTKWindow** windows;
    int window_count;
} BTKApplication;


enum BTKRenderingBackendType {
    OPENGL = 0,
    VULKAN = 1
};

typedef struct {
    enum BTKRenderingBackendType renderingBackend;
} BTKApplicationFlags;



#define BTK_APPLICATION_FLAGS_DEFAULT CLITERAL(BTKApplicationFlags){ .renderingBackend = OPENGL}
BTKApplication* btk_application_create(BTKApplicationFlags flags);
void btk_application_destroy(BTKApplication* app);


void btk_application_run(BTKApplication* app);

void btk_application_window_add(BTKApplication* app, BTKWindow* window);



#endif // BTK_APPLICATION_H