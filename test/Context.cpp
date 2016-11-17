#include <igloo/igloo_alt.h>

#include <slimsdl/Context.hpp>

// #include "sdl_mock.hpp"
// #include "simple_sdl_mock.hpp"
#include <SDL2/SDL.h>

using namespace igloo;

Describe(AContext)
{

    void SetUp() {
        SDL_Quit();
    }

    It(can_be_instantiated)
    {
        // pre-check that is not initialized
        AssertThat(SDL_WasInit(0), Equals(0));
        slimsdl::Context context;
    }

    It(should_call_sdl_init)
    {
        slimsdl::Context context;
        AssertThat(SDL_WasInit(0), Is().Not().EqualTo(0));
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
        AssertThat(SDL_WasInit(0), Equals(0));
    }
};
