/**
 * @file btk.h
 * @author SusgUY446
 * @brief A lightweight easy to use GTK alternative
 * @version 0.1
 * @date 2025-03-17
 * 
 * @copyright Copyright SusgUY446 (c) 2025
 * 
*/


#ifndef BTK_H
#define BTK_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdint.h>




typedef enum BTKApplicationRenderingBackend {
    OPENGL = 0,
    VULKAN = 1  
} BTKApplicationRenderingBackend;

typedef struct BTKApplication BTKApplication;
typedef struct BTKApplicationFlags BTKApplicationFlags;



typedef struct BTKWindow BTKWindow;
typedef struct BTKWindowFlags BTKWindowFlags;


// Window callbacks
typedef void(*BTKWindowCloseCallbackFunc)(BTKWindow*);

/**
 * @brief 
 * @param resizeable If the window should be resizeable by the end user
 */ 
struct BTKWindowFlags {
    bool resizeable;
};

struct BTKWindow {
    GLFWwindow* win;
    BTKApplication* app;

    struct {
        BTKWindowCloseCallbackFunc closeCallback;
    } callbacks;
};












#define BTK_WINDOW_FLAGS_DEFAULT (BTKWindowFlags){.resizeable = true}
#define BTK_APPLICATION_FLAGS_DEFAULT (BTKApplicationFlags){.renderingBackend = OPENGL}

struct BTKApplicationFlags {
    BTKApplicationRenderingBackend renderingBackend;
};



struct BTKApplication {
    BTKApplicationFlags flags;
    BTKWindow** windows;
    uint32_t window_count;
};






BTKWindow* btk_window_create(BTKApplication* app, const char* title, int width, int height, BTKWindowFlags flags);


void btk_window_destroy(BTKWindow* window);


void btk_window_set_close_callback(BTKWindow* window, BTKWindowCloseCallbackFunc callback);


BTKApplication* btk_application_create(BTKApplicationFlags flags);



void btk_application_destroy(BTKApplication* app);


void btk_application_run(BTKApplication* app);


#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BTK_H
