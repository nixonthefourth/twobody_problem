//
// Created by Mykyta Khomiakov on 02/03/2026.
//

#ifndef TWOBODY_PROBLEM_PHYSICS_H
#define TWOBODY_PROBLEM_PHYSICS_H
#include "Vec2.h"

namespace physics {
    /// @brief Finds distance between two stellar bodies.
    /// @param a The heavier body.
    /// @param b The lighter orbiting body.
    /// @details Follows a simple Pythagorean of squaring two distances and subtracting them.
    ///          Two subtracted squares are added and their square root is taken.
    /// @return Returns the equation as a float directly.
    float find_distance(const Vec2& a, const Vec2& b);

    /// @brief Finds the gravitational acceleration between two bodies.
    /// @param m_a Mass of the heavier body in the system.
    /// @param distance Distance between those objects found in find_distance(a, b).
    /// @param a The vector position of the heavier body.
    /// @param b The vector position of the lighter orbiting body.
    /// @details Simplifies Newton's `F=ma` and `F=G*(Mm/r^3)*r_vector.
    ///          Finds vector distance between the two objects for r_vector.
    /// @return Returns the acceleration
    Vec2 find_g_acceleration(float m_a, float distance, const Vec2& a, const Vec2& b);

    /// @brief Finds escape velocity.
    /// @param m Mass of the heavier object, since the lighter mass is disregarded
    ///          due to transformation of Newtonian formulae regarding attraction and acceleration.
    /// @param distance Distance between two bodies calculated in `find_distance(a, b)`.
    /// @return Returns a square root of two stellar masses divided by distance.
    float find_esc_vel(float m, float distance);

    /// @brief Randomised velocity choice assuming the object doesn't escape the system.
    /// @param escape_vel The escape velocity found in `find_esc_vel(m, distance)`.
    /// @details Generates a seed with the Mersenne Twister Engine and applied
    ///          uniform real distribution to find the value between 0.0 and the calculated
    ///          escape velocity.
    /// @return Returns the randomised float value.
    float choose_vel(float escape_vel);

    /// @brief Finds the total energy of the object.
    /// @param vel Velocity of the second object in the system.
    /// @param distance Distance between two objects.
    /// @param m Mass of the heavier object.
    /// @return Returns the formulae as a float value.
    float find_energy(float vel, float distance, float m);

    /// @brief Finds the direction of the current velocity.
    /// @param a The current coordinates of the heavier object.
    /// @param b The current coordinates of the orbiting object.
    /// @param distance Distance between the two objects.
    /// @param vel Current velocity of the orbiting object.
    Vec2 find_vel_direction(const Vec2& a, const Vec2& b, float distance, float vel);
}

#endif //TWOBODY_PROBLEM_PHYSICS_H