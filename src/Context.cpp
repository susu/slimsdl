#include <slimsdl/Context.hpp>

#include <SDL2/SDL.h>
#include <goodies/Logger.hpp>
#include <slimsdl/utils.hpp>
#include <slimsdl/exc.hpp>

using namespace slimsdl;

Context::Context()
{
    int flags = SDL_INIT_EVERYTHING;
    LOG_DEBUG("Initializing SDL with flags: ", flags);
    if (SDL_Init(flags) == -1)
        GOODIES_THROW(SDLException, "Cannot initialize SDL! Error: " << SDL_GetError());
}

Context::~Context()
{
    LOG_DEBUG("Shutting down SDL");
    SDL_Quit();
}
