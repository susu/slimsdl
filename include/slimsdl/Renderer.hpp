#ifndef SLIMSDL_RENDERER_HPP_INC
#define SLIMSDL_RENDERER_HPP_INC

#include <slimsdl/utils.hpp>
#include <SDL2/SDL_render.h>

struct SDL_Renderer;

namespace slimsdl {
    class Window;

    enum class RendererFlag : uint32_t
    {
      Software      = SDL_RENDERER_SOFTWARE,
      Accelerated   = SDL_RENDERER_ACCELERATED,
      PresentVSync  = SDL_RENDERER_PRESENTVSYNC,
      TargetTexture = SDL_RENDERER_TARGETTEXTURE,
    };

    std::ostream & operator<<(std::ostream& out, RendererFlag flag);

    class Renderer : NonTransferable {
        public:
            Renderer(const Window & window, std::set<RendererFlag> flags);
            ~Renderer();
        private:
            SDL_Renderer* m_renderer = nullptr;
    };
}

#endif
