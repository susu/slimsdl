#include <igloo/igloo_alt.h>

#include <slimsdl/Context.hpp>

// #include "sdl_mock.hpp"
#include "simple_sdl_mock.hpp"

using namespace igloo;

Describe(AContext)
{
    It(can_be_instantiated)
    {
        slimsdl::Context context;
    }

    It(should_call_sdl_init)
    {
        slimsdl::Context context;
        AssertThat(simplemock::sdl_initialized, Equals(true));
    }
};
