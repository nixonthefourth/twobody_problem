//
// Created by Mykyta Khomiakov on 04/03/2026.
//

#include "verlet.h"
#include <cmath>
#include "Vec2.h"

/// @brief Updates the position vector by a given timestep
/// @param position Current position vector
/// @param velocity Current velocity
/// @param acceleration Current acceleration
/// @param dt Timestep
/// @return Returns a new position at a new timestep
Vec2 update_position(const Vec2& position, const Vec2& velocity, const Vec2& acceleration, float dt) {
    // Break down equation into components
    Vec2 velocity_component = velocity * dt;
    Vec2 acceleration_component = 0.5 * (acceleration * pow(dt, 2));

    return position + velocity_component + acceleration_component;
}

/// @brief Updates acceleration after updated position
/// @param m Mass of the non-orbiting body
/// @param distance Distance between two bodies
/// @param position Updated position
/// @return Returns an updated acceleration vector
Vec2 update_acceleration(float m, float distance, const Vec2& position) {
    return -1 * (m / pow(distance, 3)) * position;
}

/// @brief Update velocity after acquiring new position and acceleration vectors
/// @param velocity Current velocity
/// @param init_acceleration Initial acceleration before update
/// @param upd_acceleration Updated acceleration in `update_acceleration()`
/// @param dt Timestep
/// @return Returns an updated velocity vector
Vec2 update_velocity(const Vec2& velocity, const Vec2& init_acceleration, const Vec2& upd_acceleration, float dt) {
    return velocity + 0.5 * (init_acceleration + upd_acceleration) * dt;
}