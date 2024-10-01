//
// Created by User on 16/09/2024.
//

#include "Vec2.h"


// Addition
Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

// Subtraction
Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

// Scalar multiplication
Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

// Dot product
float Vec2::dot(const Vec2& other) const {
    return (x * other.x + y * other.y);
}

// Magnitude (length of the vector)
float Vec2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::normal() const
{
    return Vec2(-y, x);
}

// Normalize the vector (unit vector)
Vec2 Vec2::normalize() const {
    float mag = magnitude();
    return (mag > 0) ? Vec2(x / mag, y / mag) : Vec2(0, 0);
}
