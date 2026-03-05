//
// Created by Mykyta Khomiakov on 04/03/2026.
//

#ifndef TWOBODY_PROBLEM_VERLET_H
#define TWOBODY_PROBLEM_VERLET_H

#include "Vec2.h"
#include <string>
#include <vector>

namespace physics::verlet {

    /// @brief Stores a single timestep snapshot of the orbiting body.
    struct OrbitSnapshot {
        int   step;
        float x;
        float y;
        float vx;
        float vy;
        float ax;
        float ay;
    };

    // Integration steps
    Vec2 update_position(const Vec2& position, const Vec2& velocity, const Vec2& acceleration, float dt);
    Vec2 update_acceleration(float m, float distance, const Vec2& position);
    Vec2 update_velocity(const Vec2& velocity, const Vec2& init_acceleration, const Vec2& upd_acceleration, float dt);

    void update(Vec2& position,
                Vec2& velocity,
                Vec2& acceleration,
                Vec2& pos_body_a,
                float dt,
                float m);

    /// @brief Writes the recorded orbit snapshots to a CSV file.
    /// @param filename Target file path (e.g. "orbit_data.csv").
    void export_csv(const std::string& filename);
}

#endif //TWOBODY_PROBLEM_VERLET_H