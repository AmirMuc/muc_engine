//
// Created by User on 16/09/2024.
//

#ifndef VEC2_H
#define VEC2_H

#include <cmath>


struct Vec2 {
    float x, y;

    // Constructor
    Vec2(float x = 0.0f, float y = 0.0f): x(x), y(y){}

    // Addition
    Vec2 operator+(const Vec2& other) const;

    // Subtraction
    Vec2 operator-(const Vec2& other) const;

    // Scalar multiplication
    Vec2 operator*(float scalar) const;

    // Dot product
    [[nodiscard]] float dot(const Vec2& other) const;

    // Magnitude (length of the vector)
    [[nodiscard]] float magnitude() const;

    Vec2 normal() const;

    // Normalize the vector (unit vector)
    [[nodiscard]] Vec2 normalize() const;

};

#endif //VEC2_H
