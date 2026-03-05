//
// Created by Mykyta Khomiakov on 05/03/2026.
//

#include "../include/world.h"

#include "physics.h"
#include "stellar_object.h"
#include "Vec2.h"
#include "../include/verlet.h"

#include <cstdlib>   // std::system
#include <iostream>

namespace world {
    void run() {
        // Define celestial objects
        stellar_object Star(1000, "The Star", Vec2(30.f, 30.f), Vec2(0.f, 0.f));
        stellar_object Telex(20, "Planet Telex", Vec2(100.f, 80.f), Vec2(0.f, 0.f));

        // Add initial velocity to the planet
        float distance = physics::find_distance(Star.get_position(), Telex.get_position());
        float chosen_velocity = physics::choose_vel(physics::find_esc_vel(Star.get_mass(), distance));
        Vec2 velocity_direction = physics::find_vel_direction(Star.get_position(), Telex.get_position(),
            distance, chosen_velocity);

        Telex.set_velocity(velocity_direction);

        // Run Verlet Integrator
        Vec2 acceleration = physics::find_g_acceleration(Star.get_mass(), distance,
                                                           Star.get_position(), Telex.get_position());

        physics::verlet::update(Telex.get_position(),
                Telex.get_velocity(),
                acceleration,
                Star.get_position(),
                1,
                Star.get_mass());

        // Export simulation data to CSV, then plot via Python
        physics::verlet::export_csv(PROJECT_ROOT "/data/orbit_data.csv");

        std::cout << "\nLaunching Python plotter..." << std::endl;
        int result = std::system(
            "python3 " PROJECT_ROOT "/scripts/plot_orbit.py "
                       PROJECT_ROOT "/data/orbit_data.csv"
        );
        if (result != 0) {
            std::cerr << "Warning: Python plot script failed or was not found." << std::endl;
        }
    }
}