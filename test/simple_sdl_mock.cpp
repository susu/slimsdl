
#include "simple_sdl_mock.hpp"


std::unique_ptr<simplemock::SDLMock> simplemock::SDLMock::m_instance = nullptr;
using simplemock::sdl;

extern "C"
{
    int SDL_Init(int flags) {
        sdl().initialized = true;
        sdl().initFlags = flags;
        return 0;
    }

    int SDL_WasInit(int mask) {
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
}

