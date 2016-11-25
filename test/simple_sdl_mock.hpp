#ifndef SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC
#define SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC

#include <memory>

namespace simplemock
{
    struct WindowStub;

    class SDLMock {
        public:
            static SDLMock& instance() {
                if (!m_instance)
                    reset();
                return *m_instance;
            }

            static void reset() {
                m_instance.reset(new SDLMock());
            }

            // Mock interface
            // {
            int initReturnValue = 0;

            bool initialized = false;
            int initFlags = 0;

            bool imgInitialized = false;
            int imgInitFlags = 0;

            WindowStub* lastWindow = nullptr;
            // }
        private:
            static std::unique_ptr<SDLMock> m_instance;
    };

    static SDLMock& sdl() {
        return SDLMock::instance();
    }

    static void reset() {
        SDLMock::reset();
    }

    struct WindowStub {
        const char* title;
        int x; int y;
        int width; int height;
        uint32_t flags;
    };
}

#endif
