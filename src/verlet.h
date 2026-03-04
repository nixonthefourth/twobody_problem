//
// Created by Mykyta Khomiakov on 04/03/2026.
//

#ifndef TWOBODY_PROBLEM_VERLET_H
#define TWOBODY_PROBLEM_VERLET_H

#include "Vec2.h"

namespace physics::verlet {
    Vec2 update_position(const Vec2& position, const Vec2& velocity, const Vec2& acceleration, float dt);
    Vec2 update_acceleration(float m, float distance, const Vec2& position);
    Vec2 update_velocity(const Vec2& velocity, const Vec2& init_acceleration, const Vec2& upd_acceleration, float dt);
    void update(Vec2& position,
                    Vec2& velocity,
                    Vec2& acceleration,
                    Vec2& pos_body_a,
                    float dt,
                    float m);
}

#endif //TWOBODY_PROBLEM_VERLET_H