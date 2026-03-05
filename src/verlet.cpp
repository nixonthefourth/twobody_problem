//
// Created by Mykyta Khomiakov on 04/03/2026.
//

#include "../include/verlet.h"
#include <cmath>
#include "Vec2.h"
#include "physics.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

namespace physics::verlet {

    // Module-level storage for orbit snapshots recorded during update()
    static std::vector<OrbitSnapshot> g_snapshots;

    /// @brief Updates the position vector by a given timestep.
    Vec2 update_position(const Vec2& position, const Vec2& velocity, const Vec2& acceleration, float dt) {
        Vec2 velocity_component     = velocity * dt;
        Vec2 acceleration_component = 0.5f * (acceleration * pow(dt, 2));
        return position + velocity_component + acceleration_component;
    }

    /// @brief Updates acceleration after updated position.
    Vec2 update_acceleration(float m, float distance, const Vec2& position) {
        return -1.f * (m / pow(distance, 3)) * position;
    }

    /// @brief Updates velocity after acquiring new position and acceleration vectors.
    Vec2 update_velocity(const Vec2& velocity, const Vec2& init_acceleration, const Vec2& upd_acceleration, float dt) {
        return velocity + 0.5f * (init_acceleration + upd_acceleration) * dt;
    }

    /// @brief Runs the Velocity Verlet integrator for 1000 steps and records every snapshot.
    void update(Vec2& position,
                Vec2& velocity,
                Vec2& acceleration,
                Vec2& pos_body_a,
                float dt,
                float m)
    {
        g_snapshots.clear();
        g_snapshots.reserve(1000);

        for (int i = 0; i < 10000; i++) {
            Vec2 new_position     = update_position(position, velocity, acceleration, dt);
            float distance        = physics::find_distance(pos_body_a, new_position);
            Vec2 new_acceleration = update_acceleration(m, distance, new_position);
            Vec2 new_velocity     = update_velocity(velocity, acceleration, new_acceleration, dt);

            position     = new_position;
            velocity     = new_velocity;
            acceleration = new_acceleration;

            g_snapshots.push_back({ i,
                position.x,     position.y,
                velocity.x,     velocity.y,
                acceleration.x, acceleration.y });
        }
    }

    /// @brief Writes recorded orbit snapshots to a CSV file.
    /// @param filename Target file path (e.g. "orbit_data.csv").
    void export_csv(const std::string& filename) {
        if (g_snapshots.empty()) {
            std::cerr << "export_csv: no snapshot data – call update() first." << std::endl;
            return;
        }

        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("export_csv: cannot open file: " + filename);
        }

        // Header row
        file << "step,x,y,vx,vy,ax,ay\n";

        for (const auto& s : g_snapshots) {
            file << s.step << ","
                 << s.x    << "," << s.y
                 << ","    << s.vx << "," << s.vy
                 << ","    << s.ax << "," << s.ay
                 << "\n";
        }

        file.close();
        std::cout << "Orbit data exported to: " << filename << std::endl;
    }
}