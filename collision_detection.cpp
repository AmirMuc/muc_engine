//
// Created by User on 16/09/2024.
//

#include "collision_detection.h"


std::pair<float, float> project_polygon(const std::vector<Vec2> &polygon,
                                        const Vec2 &axis)
{
    float min = axis.dot(polygon[0]);
    float max = min;
    for (const Vec2 &vertex: polygon)
    {
        float projection = axis.dot(vertex);
        if (projection < min) min = projection;
        if (projection > max) max = projection;
    }
    return {min, max};
}

bool overlap(float min_a, float max_a, float min_b, float max_b)
{
    return !(min_a > max_b || min_b > max_a);
}

bool is_colliding(const std::vector<Vec2> &polygon_a,
                  const std::vector<Vec2> &polygon_b)
{
    std::vector<Vec2> edges;

    for (size_t i = 0; i < polygon_a.size(); i++)
    {
        Vec2 edge = polygon_a[(i + 1) % polygon_a.size()] - polygon_a[i];
        edges.push_back(edge.normal().normalize());
    }
    for (size_t i = 0; i < polygon_b.size(); i++)
    {
        Vec2 edge = polygon_b[(i + 1) % polygon_b.size()] - polygon_b[i];
        edges.push_back(edge.normal().normalize());
    }

    for(const Vec2 axis : edges)
    {
        auto [min_a, max_a] = project_polygon(polygon_a, axis);
        auto [min_b, max_b] = project_polygon(polygon_b, axis);
        if(!overlap(min_a, max_a, min_b, max_b))
        {
            return false; // separating axis found
        }
    }

    return true; // collision, no separating axis
}
