#include <slimsdl/Context.hpp>
#include <slimsdl/ImageContext.hpp>
#include <goodies/Logger.hpp>

#include <iostream>

using namespace slimsdl;

int main() {
    goodies::log::Logger::initialize(std::cout);

    Context context;
    ImageContext imageContext({IMGInitFlag::PNG});

    return 0;
}
