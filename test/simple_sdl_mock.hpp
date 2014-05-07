#ifndef SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC
#define SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC

namespace simplemock
{
    static bool sdl_initialized = false;
    static int sdl_init_flags = 0;
}

extern "C"
{
    int SDL_Init(int flags)
    {
        simplemock::sdl_initialized = true;
        simplemock::sdl_init_flags = flags;
        return 0;
    }
}

#endif
