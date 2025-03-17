#ifndef BTK_H
#define BTK_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#include <GLFW/glfw3.h>
#include <stdbool.h>

// macros
#define CLITERAL(type)      (type) // credit: raylib





// forward declarations
typedef struct _BTKApplication BTKApplication;
typedef struct _BTKApplicationFlags BTKApplicationFlags;
typedef enum _BTKApplicationRenderingBackend {
    OPENGL = 0,
    VULKAN = 1
} BTKApplicationRenderingBackend;


typedef struct _BTKWindow BTKWindow;
typedef struct _BTKWindowFlags BTKWindowFlags;


typedef void(*BTKWindowCloseCallbackFunc)(BTKWindow*);


struct _BTKWindow {
    GLFWwindow* win; 
    BTKApplication* app;

    struct {
        BTKWindowCloseCallbackFunc closeCallback = NULL;
    } callbacks;
};



struct _BTKWindowFlags {
    bool resizeable;
};



#define BTK_APPLICATION_FLAGS_DEFAULT CLITERAL(BTKApplicationFlags){.renderingBackend = OPENGL}
#define BTK_WINDOW_FLAGS_DEFAULT CLITERAL(BTKWindowFlags){.resizeable = true}


struct _BTKApplicationFlags {
    BTKApplicationRenderingBackend renderingBackend;
};




struct _BTKApplication{
    BTKApplicationFlags flags;
    BTKWindow** windows;
    uint32_t window_count;
};







// Window related functions
BTKWindow* btk_window_create(BTKApplication* app, const char* title, int width, int height, BTKWindowFlags flags);
void btk_window_destroy(BTKWindow* window);

void btk_window_set_close_callback(BTKWindow* window, BTKWindowCloseCallbackFunc callback);


// Top level application
BTKApplication* btk_application_create(BTKApplicationFlags flags);
void btk_application_destroy(BTKApplication* app);





void btk_application_run(BTKApplication* app);


#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BTK_H