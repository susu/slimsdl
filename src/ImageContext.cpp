#include <slimsdl/ImageContext.hpp>

#include <slimsdl/utils.hpp>
// #include <mine/Logger.hpp>
// #include <mine/Exceptions.hpp>

using namespace slimsdl;

ImageContext::ImageContext(std::set<IMGInitFlag> flags)
{
  // LOG_DEBUG("Initializing SDL_image context with flags: ", flagsetToString(flags));

  auto value = flagset_to_value(flags);

  auto result = IMG_Init(value); // IMG_Init returns the bitmask of the
                                 // successfully initialized image formats.
  if (result != value)
  {
    // MINE_RAISE(SDLException, "Cannot initialized SDL_image! Error: " << IMG_GetError());
  }
  m_initializedImageFormats = result;
}

ImageContext::~ImageContext()
{
  // LOG_DEBUG("Shutting down SDL_image");
  IMG_Quit();
}
