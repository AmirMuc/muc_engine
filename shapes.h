//
// Created by User on 02/10/2024.
//

#ifndef SHAPES_H
#define SHAPES_H
#include "Vec2.h"
#include <vector>

struct AABB {
    Vec2 min;
    Vec2 max;

    AABB(const Vec2& min, const Vec2& max) : min(min), max(max) {}

    bool intersects(const AABB& other) const;

    bool contains(const Vec2& point) const;
};

AABB make_polygon_AABB(const std::vector<Vec2>& polygon);
#endif //SHAPES_H
