//
// Created by Mykyta Khomiakov on 04/03/2026.
//

#include "../include/verlet.h"
#include <cmath>
#include "Vec2.h"
#include "physics.h"
#include <iostream>

namespace physics::verlet {

    /// @brief Updates the position vector by a given timestep.
    /// @param position Current position vector.
    /// @param velocity Current velocity.
    /// @param acceleration Current acceleration.
    /// @param dt Timestep.
    /// @return Returns a new position at a new timestep.
    Vec2 update_position(const Vec2& position, const Vec2& velocity, const Vec2& acceleration, float dt) {
        // Break down equation into components
        Vec2 velocity_component = velocity * dt;
        Vec2 acceleration_component = 0.5 * (acceleration * pow(dt, 2));

        return position + velocity_component + acceleration_component;
    }

    /// @brief Updates acceleration after updated position.
    /// @param m Mass of the non-orbiting body.
    /// @param distance Distance between two bodies.
    /// @param position Updated position.
    /// @return Returns an updated acceleration vector.
    Vec2 update_acceleration(float m, float distance, const Vec2& position) {
        return -1 * (m / pow(distance, 3)) * position;
    }

    /// @brief Update velocity after acquiring new position and acceleration vectors.
    /// @param velocity Current velocity.
    /// @param init_acceleration Initial acceleration before update.
    /// @param upd_acceleration Updated acceleration in `update_acceleration()`.
    /// @param dt Timestep.
    /// @return Returns an updated velocity vector.
    Vec2 update_velocity(const Vec2& velocity, const Vec2& init_acceleration, const Vec2& upd_acceleration, float dt) {
        return velocity + 0.5 * (init_acceleration + upd_acceleration) * dt;
    }

    /// @brief Update function applying all integrators. Use within a loop.
    /// @param position Current position of the orbiting body.
    /// @param velocity Current velocity of the orbiting body.
    /// @param acceleration Current acceleration of the orbiting body.
    /// @param pos_body_a Position of the centre mass.
    /// @param dt Timestep.
    /// @param m Mass of the centre mass celestial body.
    void update(Vec2& position,
                Vec2& velocity,
                Vec2& acceleration,
                Vec2& pos_body_a,
                float dt,
                float m)
    {
        for (int i = 0; i < 1000; i++) {
            // New position
            Vec2 new_position = update_position(position, velocity, acceleration, dt);

            float distance = physics::find_distance(pos_body_a, new_position);

            // New acceleration
            Vec2 new_acceleration = update_acceleration(m, distance, new_position);

            // New velocity
            Vec2 new_velocity = update_velocity(velocity,
                acceleration,
                new_acceleration,
                dt);

            // Updated values
            position = new_position;
            velocity = new_velocity;
            acceleration = new_acceleration;

            std::cout << "=================================================" << std::endl;
            std::cout << "Current Position: " << position << std::endl;
            std::cout << "Current Velocity: " << velocity << std::endl;
            std::cout << "Current Acceleration: " << acceleration << std::endl;
        }
    }
}
