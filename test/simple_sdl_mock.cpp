
#include "simple_sdl_mock.hpp"
#include <SDL2/SDL.h>


using namespace simplemock;
std::unique_ptr<SDLMock> SDLMock::m_instance = nullptr;

extern "C"
{
    int SDL_Init(uint32_t flags) {
        sdl().initialized = true;
        sdl().initFlags = flags;
        return 0;
    }

    uint32_t SDL_WasInit(uint32_t mask) {
        return sdl().initFlags;
    }

    void SDL_Quit() {
        simplemock::reset();
    }

    int IMG_Init(int flags) {
        sdl().imgInitialized = true;
        sdl().imgInitFlags = flags;
        return flags;
    }

    void IMG_Quit() {
        sdl().imgInitialized = false;
        sdl().imgInitFlags = 0;
    }

    SDL_Window* SDL_CreateWindow(const char* title,
                                 int x, int y,
                                 int width, int height, uint32_t flags)
    {
        auto stub = new WindowStub{
            .title = title,
            .x = x, .y = y,
            .width = width, .height = height,
            .flags = flags,
        };
        sdl().lastWindow = stub;
        return reinterpret_cast<SDL_Window*>(stub);
    }

    void SDL_DestroyWindow(SDL_Window* win) {
        delete sdl().lastWindow;
        sdl().lastWindow = nullptr;
    }
}

