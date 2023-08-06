#pragma once
#include <ostream>

struct Location {
    float x;
    float y;
    
    auto operator<=>(const Location&) const = default;
};

inline std::ostream& operator<<(std::ostream& os, const Location& loc) {
    os << "{X:" << loc.x << ", Y:" << loc.y << "}";  
    return os;
}

