#include <slimsdl/Window.hpp>

#include <SDL2/SDL_video.h>
#include <goodies/Logger.hpp>
#include <slimsdl/utils.hpp>

using namespace slimsdl;

Window::Window(std::string title, int x, int y, int width, int height, std::set<WindowFlag> flags)
{
    LOG_DEBUG("Create window: ", title);
    m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flagset_to_value(flags));
    LOG_DEBUG("Window created, ID=", SDL_GetWindowID(m_window));
}

Window::~Window() {
    LOG_DEBUG("Destroy window with ID=", SDL_GetWindowID(m_window));
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
