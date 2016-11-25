#ifndef SLIMSDL_WINDOW_HPP_INC
#define SLIMSDL_WINDOW_HPP_INC

#include <string>

struct SDL_Window;

namespace slimsdl
{
    class Window
    {
        public:
            Window(std::string title, int x, int y, int width, int height);
            ~Window();
        private:
            SDL_Window* m_window;
    };
}

#endif
