#pragma once
struct Location {
    double x;
    double y;
    
    auto operator<=>(const Location&) const = default;
};



