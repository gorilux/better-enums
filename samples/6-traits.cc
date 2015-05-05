// Using traits to capture project conventions on enums.

#include <iostream>
#include <enum.h>

// Adopt the convention that the first value in an enum is the default value.
template <typename Enum>
constexpr const Enum default_()
{
    return enum_::traits<Enum>::first;
}

// Make it possible to override the convention for specific enums.
#define ENUM_DEFAULT(Enum, Default)                                            \
    template <>                                                                \
    constexpr const Enum default_<Enum>()                                      \
    {                                                                          \
        return Enum::Default;                                                  \
    }



// Default will be Red, because it is first.
ENUM(Channel, int, Red, Green, Blue);

// Default will be TrueColor, even though it is not first.
ENUM(Depth, int, HighColor, TrueColor);
ENUM_DEFAULT(Depth, TrueColor);



int main()
{
    // Default construction can now be simulated for some purposes, and the
    // default value is still declared in one place, not all over the program
    // code.
    Depth   depth = default_<Depth>();
    std::cout << enum_::to_string(depth) << std::endl;

    std::cout << enum_::to_string(default_<Channel>()) << std::endl;
    std::cout << enum_::to_string(default_<Depth>())   << std::endl;

    return 0;
}



// Also works at compile-time.
constexpr auto  value = default_<Channel>();
