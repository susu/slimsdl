#include <igloo/igloo_alt.h>

#include <slimsdl/ImageContext.hpp>
#include <slimsdl/Context.hpp>
#include <SDL2/SDL.h>

using namespace igloo;

Describe(AnImageContext)
{
    void SetUp() {
        SDL_Quit();
    }

    It(can_initialize_SDL_image_context_to_given_image_type) {
        slimsdl::Context ctx;
        slimsdl::ImageContext imgContext({slimsdl::IMGInitFlag::PNG});
        AssertThat(imgContext.getInitializedFormatRawFlag(), Equals(IMG_INIT_PNG))
    }
};
