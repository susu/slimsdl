#include <igloo/igloo_alt.h>

#include <slimsdl/ImageContext.hpp>

#include <slimsdl/Context.hpp>
#include <SDL2/SDL.h>
#include "simple_sdl_mock.hpp"

using namespace igloo;
using simplemock::sdl;

Describe(AnImageContext)
{
    void SetUp() {
        simplemock::reset();
    }

    It(can_initialize_SDL_image_context_to_given_image_type) {
        slimsdl::Context ctx;
        slimsdl::ImageContext imgContext({slimsdl::IMGInitFlag::PNG});
        AssertThat(sdl().imgInitFlags, Equals(IMG_INIT_PNG))
    }

    It(should_quit_img_after_context_is_destroyed) {
        {
            slimsdl::ImageContext imgContext({slimsdl::IMGInitFlag::PNG});
        }
        AssertThat(sdl().imgInitialized, Equals(false));
    }
};
