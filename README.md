# BTK - Better Toolkit 

## Overview
BTK is a modern, lightweight, and self-contained GUI framework designed to be a **stable, high-performance** alternative to GTK. It features **GPU-accelerated rendering** using OpenGL and aims to be **free from GNOME's breaking changes and dependency hell**.

## Features
- **Vulkan-based rendering** – Fully hardware-accelerated UI with high performance.
- **No external dependencies** – No GLib, no GNOME clutter, no unnecessary runtime dependencies.
- **Cross-platform** – Initially targeting Linux and Windows, with potential macOS support.
- **Lightweight and fast** – Minimal overhead compared to Qt or GTK.
- **Modular and extendable** – Designed for flexibility and easy integration into applications.
- **C99 compliant** – Ensures compatibility and stability across different compilers and platforms.

## Why BTK?
GTK has become increasingly bloated, unstable, and dependent on the GNOME ecosystem, while Qt's licensing model can be restrictive. BTK provides a **modern, Vulkan-powered** alternative that remains lightweight and stable.

## Requirements
- **Vulkan** (must be installed on the system)
- **GLFW** (for window management, will be included statically in builds)
- **C/C++ Compiler** (GCC/Clang/MSVC)


## Usage
```c
// Example code for creating a window
BTK_Window *window = btk_create_window("Hello, BTK!", 800, 600);
btk_main_loop(window);
```

## Roadmap
- [ ] Basic OpenGL rendering
- [ ] Windowing and event handling (via GLFW)
- [ ] UI widget system
- [ ] Theming system
- [ ] Linux & Windows support
- [ ] macOS support (future)

## Contributing
Contributions are welcome! Feel free to open issues, submit pull requests, or discuss ideas.



