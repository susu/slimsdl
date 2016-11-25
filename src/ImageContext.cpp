#include <slimsdl/ImageContext.hpp>

#include <goodies/Logger.hpp>
#include <goodies/Exception.hpp>
#include <slimsdl/utils.hpp>
#include <slimsdl/exc.hpp>

using namespace slimsdl;

ImageContext::ImageContext(std::set<IMGInitFlag> flags)
{
    LOG_DEBUG("Initializing SDL_image context with flags: ", flagset_to_string(flags));

    auto value = flagset_to_value(flags);

    auto result = IMG_Init(value); // IMG_Init returns the bitmask of the
                                   // successfully initialized image formats.
    if (result != value)
        GOODIES_THROW(SDLException, "Cannot initialized SDL_image! Error: " << IMG_GetError());
}

ImageContext::~ImageContext()
{
    LOG_DEBUG("Shutting down SDL_image");
    IMG_Quit();
}
