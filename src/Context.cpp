#include <slimsdl/Context.hpp>

#include <SDL2/SDL.h>

using namespace slimsdl;

Context::Context()
{
    SDL_Init(1);
}
