//
// Created by User on 16/09/2024.
//

#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <vector>
#include "Vec2.h"

std::pair<float, float> project_polygon(const std::vector<Vec2> &polygon,
                                        const Vec2 &axis);

bool overlap(float min_a, float max_a, float min_b, float max_b);

bool is_colliding(const std::vector<Vec2> &polygon_a,
                  const std::vector<Vec2> &polygon_b);

#endif //COLLISION_DETECTION_H
