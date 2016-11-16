#ifndef SLIMSDL_UTILS_HPP_INC
#define SLIMSDL_UTILS_HPP_INC

#include <type_traits>
#include <set>
#include <string>
#include <sstream>

namespace slimsdl {
    /**
     *  non-copyable AND non-moveable either
     */
    struct NonTransferable
    {
        NonTransferable() = default;
        ~NonTransferable() = default;

        NonTransferable(const NonTransferable&) = delete;
        NonTransferable& operator=(const NonTransferable&) = delete;

        NonTransferable(NonTransferable&&) = delete;
        NonTransferable& operator=(NonTransferable&&) = delete;
    };

    template<typename T>
    auto to_underlying_cast(T value) -> typename std::underlying_type<T>::type
    {
        return static_cast<typename std::underlying_type<T>::type>(value);
    }

    template<typename T>
    T from_underlying_cast(typename std::underlying_type<T>::type value)
    {
        return static_cast<T>(value);
    }

    template<typename T>
    std::string flagset_to_string(const std::set<T> & flagset)
    {
        static_assert(std::is_enum<T>::value == true, "T must be enum!");
        std::ostringstream os;
        os << "{";
        for (auto flag : flagset)
        {
            os << flag << ", ";
        }
        os << "}";
        return os.str();
    }

    template<typename T>
    auto flagset_to_value(const std::set<T> & flagset) -> typename std::underlying_type<T>::type
    {
        typename std::underlying_type<T>::type ret = 0;
        for (auto flag : flagset)
            ret |= to_underlying_cast(flag);
        return ret;
    }
}

#endif
