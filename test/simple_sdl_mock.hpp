#ifndef SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC
#define SLIMTEST_SDL_SIMPLE_SDL_MOCK_HPP_INC

#include <memory>

namespace simplemock
{
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
            bool initialized = false;
            int initFlags = 0;

            bool imgInitialized = false;
            int imgInitFlags = 0;
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
}

#endif
