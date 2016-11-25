#include <slimsdl/Context.hpp>
#include <slimsdl/ImageContext.hpp>
#include <slimsdl/Window.hpp>
#include <goodies/Logger.hpp>

#include <iostream>

using namespace slimsdl;

int main() {
    goodies::log::Logger::initialize(std::cout);

    Context context;
    ImageContext imageContext({IMGInitFlag::PNG});

    Window window("Simple SlimSDL Example", 10, 10, 100, 100, {WindowFlag::Shown});

    return 0;
}
