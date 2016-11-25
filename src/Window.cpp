#include <slimsdl/Window.hpp>

#include <SDL2/SDL_video.h>
#include <goodies/Logger.hpp>

using namespace slimsdl;

Window::Window(std::string title, int x, int y, int width, int height)
{
    LOG_DEBUG("Create window: ", title);
    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, 0);
}

Window::~Window() {
    LOG_DEBUG("Destroy window");
    SDL_DestroyWindow(m_window);
}
