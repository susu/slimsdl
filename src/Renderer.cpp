#include <slimsdl/Renderer.hpp>

#include <SDL2/SDL_render.h>
#include <slimsdl/Window.hpp>
#include <slimsdl/utils.hpp>
#include <goodies/Logger.hpp>

using namespace slimsdl;

std::ostream & slimsdl::operator<<(std::ostream& out, RendererFlag flag)
{
  switch (flag)
  {
    case RendererFlag::Software:      return out << "Software";
    case RendererFlag::Accelerated:   return out << "Accelerated";
    case RendererFlag::PresentVSync:  return out << "PresentVSync";
    case RendererFlag::TargetTexture: return out << "TargetTexture";
  }
  return out << "-unknown-";
}

Renderer::Renderer(const Window & window, std::set<RendererFlag> flags) {
    LOG_DEBUG("Create renderer for window: ", window,
              ", renderer flags: ", flagset_to_string(flags));
    m_renderer = SDL_CreateRenderer(window.getHandle(), -1, flagset_to_value(flags));
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
}
