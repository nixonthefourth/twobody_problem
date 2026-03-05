//
// Created by Mykyta Khomiakov on 05/03/2026.
//

#include "../include/world.h"

#include "physics.h"
#include "stellar_object.h"
#include "Vec2.h"
#include "../include/verlet.h"

namespace world {
    void run() {
        // Define celestial objects
        stellar_object Star(1000, "The Star", Vec2(0.f, 0.f), Vec2(0.f, 0.f));
        stellar_object Telex(20, "Planet Telex", Vec2(100.f, 80.f), Vec2(0.f, 0.f));

        // Run Verlet Integrator
        float distance = physics::find_distance(Star.get_position(), Telex.get_position());
        Vec2 acceleration = physics::find_g_acceleration(Star.get_mass(), distance,
                                                           Star.get_position(), Telex.get_position());

        physics::verlet::update(Telex.get_position(),
                Telex.get_velocity(),
                acceleration,
                Star.get_position(),
                1,
                Star.get_mass());
    }
}