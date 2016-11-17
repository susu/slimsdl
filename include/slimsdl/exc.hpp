#ifndef SLIMSDL_EXC_HPP_INC
#define SLIMSDL_EXC_HPP_INC

#include <goodies/Exception.hpp>

namespace slimsdl {
    class SDLException : public goodies::BaseException {
        public:
            SDLException(const char* file, int line, std::string msg)
                : goodies::BaseException(file, line, msg) {}
    };
}

#endif
