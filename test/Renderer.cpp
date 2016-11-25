#include <slimsdl/Renderer.hpp>

#include <memory>
#include <igloo/igloo_alt.h>
#include <slimsdl/Window.hpp>
#include "simple_sdl_mock.hpp"

using namespace igloo;

using slimsdl::Window;
using slimsdl::WindowFlag;
using slimsdl::Renderer;
using slimsdl::RendererFlag;
using simplemock::sdl;

Describe(ARenderer) {
    void SetUp() {
        simplemock::reset();
        window.reset(new Window("testwindow", 42, 43, 200, 300, {}));
    }

    std::unique_ptr<Window> window;

    It(can_be_instantiated_with_a_window) {
        Renderer renderer(*window, {});

        AssertThat(sdl().lastRenderer != nullptr, Equals(true));
        AssertThat(sdl().lastRenderer->window, Equals(sdl().lastWindow));
    }

    It(should_destroy_renderer_with_destruction) {
        {
            Renderer renderer(*window, {});
        }
        AssertThat(sdl().lastRenderer == nullptr, Equals(true));
    }

    It(should_create_renderer_with_flags) {
        Renderer renderer(*window, {RendererFlag::Accelerated, RendererFlag::PresentVSync});
        AssertThat(sdl().lastRenderer->flags,
                   Equals(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    }
};
