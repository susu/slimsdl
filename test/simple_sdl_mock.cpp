
#include "simple_sdl_mock.hpp"
#include <SDL2/SDL.h>
#include <goodies/enforce.hpp>
#include <goodies/Logger.hpp>

using namespace simplemock;
std::unique_ptr<SDLMock> SDLMock::m_instance = nullptr;

extern "C"
{
    int SDL_Init(uint32_t flags) {
        sdl().initialized = true;
        sdl().initFlags = flags;
        return sdl().initReturnValue;
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
        return flags & sdl().imgInitReturnMask;
    }

    void IMG_Quit() {
        sdl().imgInitialized = false;
        sdl().imgInitFlags = 0;
    }

    SDL_Window* SDL_CreateWindow(const char* title,
                                 int x, int y,
                                 int width, int height, uint32_t flags)
    {
        ENFORCE(sdl().lastWindow == nullptr,
                "A Window already defined! simplemock allows only one window at a time!");
        LOG_DEBUG("MOCK title=", title);
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
        LOG_DEBUG("MOCK");
        delete sdl().lastWindow;
        sdl().lastWindow = nullptr;
    }

    const char* SDL_GetWindowTitle(SDL_Window * window)
    {
        ENFORCE(sdl().lastWindow != nullptr,
                "Getting window title without WindowStub is not allowed!");
        return reinterpret_cast<WindowStub*>(window)->title.c_str();
    }

    SDL_Renderer* SDL_CreateRenderer(SDL_Window * window, int index, Uint32 flags)
    {
        ENFORCE(sdl().lastRenderer == nullptr,
                "A Renderer already defined! simplemock allows only one renderer at a time!");
        auto stub = new RendererStub{
            .window = reinterpret_cast<WindowStub*>(window),
            .index = index,
            .flags = flags
        };
        sdl().lastRenderer = stub;
        return reinterpret_cast<SDL_Renderer*>(stub);
    }

    void SDL_DestroyRenderer(SDL_Renderer * renderer)
    {
        delete sdl().lastRenderer;
        sdl().lastRenderer = nullptr;
    }
}

