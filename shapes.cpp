//
// Created by User on 02/10/2024.
//

#include "shapes.h"
#include "collision_detection.h"

#include <vector>


bool AABB::intersects(const AABB &other) const
{
    return (min.x <= other.max.x && max.x >= other.min.x &&
            min.y <= other.max.y && max.y >= other.min.y);
}

bool AABB::contains(const Vec2 &point) const
{
    return (point.x >= min.x && point.x <= max.x &&
            point.y >= min.y && point.y <= max.y);
}

AABB make_polygon_AABB(const std::vector<Vec2>& polygon)
{
    auto [x_min, x_max] = project_polygon(polygon, {1,0});
    auto [y_min, y_max] = project_polygon(polygon, {0,1});
    Vec2 min = {x_min, y_min};
    Vec2 max = {x_max, y_max};
    return AABB(min, max);
}
