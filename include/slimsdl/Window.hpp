#ifndef SLIMSDL_WINDOW_HPP_INC
#define SLIMSDL_WINDOW_HPP_INC

#include <string>
#include <set>
#include <SDL2/SDL_video.h>

namespace slimsdl
{
    enum class WindowFlag : uint32_t
    {
      FullScreen =        SDL_WINDOW_FULLSCREEN,         // fullscreen window
      FullScreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP, // fullscreen window at the current desktop resolution
      OpenGL =            SDL_WINDOW_OPENGL,             // window usable with OpenGL context
      Shown =             SDL_WINDOW_SHOWN,              // window is visible
      Hidden =            SDL_WINDOW_HIDDEN,             // window is not visible
      Borderless =        SDL_WINDOW_BORDERLESS,         // no window decoration
      Resizable =         SDL_WINDOW_RESIZABLE,          // window can be resized
      Minimized =         SDL_WINDOW_MINIMIZED,          // window is minimized
      Maximized =         SDL_WINDOW_MAXIMIZED,          // window is maximized
      InputGrabbed =      SDL_WINDOW_INPUT_GRABBED,      // window has grabbed input focus
      InputFocus =        SDL_WINDOW_INPUT_FOCUS,        // window has input focus
      MouseFocus =        SDL_WINDOW_MOUSE_FOCUS,        // window has mouse focus
      Foreign =           SDL_WINDOW_FOREIGN,            // window not created by SDL
      HighDPI =           SDL_WINDOW_ALLOW_HIGHDPI,      // window should be created in high-DPI mode if supported (available since SDL 2.0.1)
    };

    std::ostream& operator<<(std::ostream& out, WindowFlag);

    class Window
    {
        public:
            Window(std::string title, int x, int y, int width, int height, std::set<WindowFlag> flags);
            ~Window();
        private:
            SDL_Window* m_window;
    };
}

#endif
