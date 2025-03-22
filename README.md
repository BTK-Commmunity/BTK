
# BTK - Better Toolkit

BTK is designed to be a easier to use and more lightweight alternative to GTK

## Features

- Cross platform
- Easy to understand API


## Installation

Install BTK from source

```bash
  git clone https://github.com/BTK-Community/BTK
  cd BTK
  make
```


## Dependencies
### Build requirements 
- C99 supporting compiler
- ar [Only for static library builds]
- GNU Make
- pkg-config
- OpenGL
- GLFW

### Runtime dependencies
- OpenGL
- GLFW


    
## Usage/Examples

```c
#include <btk/btk.h>

int main() {
    BTKApplication* app = btk_application_create(BTK_APPLICATION_FLAGS_DEFAULT);

    BTKWindow* window = btk_window_create(app, "Hello World", 800, 600, BTK_WINDOW_FLAGS_DEFAULT);

    
    btk_application_run(app);
}
```


## Contributing

Contributions are always welcome!

See `CONTRIBUTING.md` for ways to get started.

Please adhere to this project's `code of conduct`.


## Documentation

[Documentation](https://btk-community.github.io/BTK/)


## Feedback

If you have any feedback, please reach out to us in the issues section


## License
[3 Clause No-Ai BSD](https://github.com/non-ai-licenses/non-ai-licenses/blob/main/NON-AI-BSD3)



## Authors

- [@susguy446](https://www.github.com/susguy446)

