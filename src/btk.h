#ifndef BTK_H
#define BTK_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#include <GLFW/glfw3.h>
#include <stdbool.h>

// macros
#if defined(__cplusplus)
    #define CLITERAL(type)      type
#else
    #define CLITERAL(type)      (type)
#endif



// forward declarations
typedef struct _BTKApplication BTKApplication;
typedef struct _BTKApplicationFlags BTKApplicationFlags;
typedef enum _BTKApplicationRenderingBackend {
    OPENGL = 0,
    VULKAN = 1
} BTKApplicationRenderingBackend;


struct _BTKWindow {
    GLFWwindow* win; 
    BTKApplication* app;
};



struct _BTKWindowFlags {
    bool resizeable;
};



typedef struct _BTKWindow BTKWindow;
typedef struct _BTKWindowFlags BTKWindowFlags;

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

// Top level application
BTKApplication* btk_application_create(BTKApplicationFlags flags);
void btk_application_destroy(BTKApplication* app);


void btk_application_run(BTKApplication* app);


#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BTK_H