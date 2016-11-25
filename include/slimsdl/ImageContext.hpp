#ifndef SLIMSDL_IMAGE_CONTEXT_HPP_INC
#define SLIMSDL_IMAGE_CONTEXT_HPP_INC

#include <set>
#include <ostream>
#include <SDL2/SDL_image.h>
#include <slimsdl/utils.hpp>

namespace slimsdl {

    enum class IMGInitFlag {
        JPG = IMG_INIT_JPG,
        PNG = IMG_INIT_PNG,
        TIF = IMG_INIT_TIF,
    };

    inline std::ostream& operator<<(std::ostream& out, IMGInitFlag flag) {
        switch (flag) {
            case IMGInitFlag::JPG: return out << "JPG";
            case IMGInitFlag::PNG: return out << "PNG";
            case IMGInitFlag::TIF: return out << "TIF";
        }
        return out << "-unknown-";
    }

    class ImageContext : NonTransferable
    {
        public:
            ImageContext(std::set<IMGInitFlag> flags);
            ~ImageContext();
    };
}

#endif
