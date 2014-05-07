#ifndef SLIMTEST_SDL_MOCK_HPP_INC
#define SLIMTEST_SDL_MOCK_HPP_INC

#include <tuple>
#include <type_traits>
#include <functional>

namespace mock
{
    class MockRepository
    {
        public:
            template<typename Function>
            MockRepository& expectCall(Function fun)
            {
                return *this;
            }

            template<typename Call>
            auto call(Call call) -> typename decltype(call.m_function)::result_type
            {}
    };

    inline MockRepository& get()
    {
        static MockRepository repo;
        return repo;
    }

    template<typename Function, typename... Args>
    class Call
    {
        public:
            static_assert(std::is_function<Function>::value == true, "template parameter Function must be a function!");

            typedef decltype(Function()) ResultType;

            Call(Function fun, Args&&... args)
                : m_args(args...)
            {}

        private:
            friend class MockRepository;

            std::tuple<Args...> m_args;
            std::function<Function> m_function;
    };

    template<typename Function, typename... Args>
    Call<Function, Args...> createCallObject(Function fun, Args&&... args)
    {
        return Call<Function, Args...>(fun, std::forward<Args>(args)...);
    }
}

extern "C"
{
    // TODO
    int SDL_Init(int flags)
    {
        return mock::get().call(mock::createCallObject<int(int)>(SDL_Init, flags));
    }
}

#endif
