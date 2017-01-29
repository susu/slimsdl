#include <igloo/igloo_alt.h>
#include <slimsdl/Context.hpp>
#include <slimsdl/exc.hpp>
#include "simple_sdl_mock.hpp"
#include <SDL2/SDL.h>

using namespace igloo;
using simplemock::sdl;

Describe(AContext)
{
    void SetUp() {
        simplemock::reset();
    }

    It(can_be_instantiated)
    {
        // pre-check that is not initialized
        AssertThat(SDL_WasInit(0), Equals(0u));
        slimsdl::Context context;
    }

    It(should_call_sdl_init)
    {
        slimsdl::Context context;
        AssertThat(SDL_WasInit(0), Is().Not().EqualTo(0u));
    }

    It(should_initialize_sdl_for_everything)
    {
        slimsdl::Context context;
        AssertThat(SDL_WasInit(0), Equals(SDL_INIT_EVERYTHING));
    }

    It(should_quit_sdl_after_context_is_destroyed)
    {
        {
            slimsdl::Context context;
        }
        AssertThat(SDL_WasInit(0), Equals(0u));
    }

    It(should_throw_if_initialization_is_failed) {
        sdl().initReturnValue = -1;
        AssertThrows(slimsdl::SDLException, slimsdl::Context());
    }
};
