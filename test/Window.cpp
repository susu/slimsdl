#include <igloo/igloo_alt.h>
#include <slimsdl/Window.hpp>
#include <slimsdl/Context.hpp>
#include "simple_sdl_mock.hpp"

using namespace igloo;
using slimsdl::Context;
using slimsdl::Window;
using slimsdl::WindowFlag;
using simplemock::sdl;

Describe(AWindow) {
    void SetUp() { simplemock::reset(); }

    It(creates_an_SDL_window_with_title_and_position) {
        Context context;
        Window window("mywintitle", 42, 43, 200, 300, {});
        auto lastWindow = sdl().lastWindow;
        AssertThat(lastWindow != nullptr, Equals(true));
        AssertThat(lastWindow->title, Equals("mywintitle"));
        AssertThat(lastWindow->x, Equals(42));
        AssertThat(lastWindow->y, Equals(43));
        AssertThat(lastWindow->width, Equals(200));
        AssertThat(lastWindow->height, Equals(300));
    }

    It(destroys_window_upon_destruction) {
        Context context;
        {
            Window window("title", 1, 2, 3, 4, {});
            AssertThat(sdl().lastWindow != nullptr, Equals(true));
        }
        AssertThat(sdl().lastWindow == nullptr, Equals(true));
    }

    It(creates_window_with_flags) {
        Context context;
        Window window("title", 1,2,3,4, {WindowFlag::FullScreen, WindowFlag::Shown});
        AssertThat(sdl().lastWindow->flags, Equals(SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN));
    }
};
