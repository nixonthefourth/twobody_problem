#ifndef TWOBODY_PROBLEM_STELLAR_OBJECT_H
#define TWOBODY_PROBLEM_STELLAR_OBJECT_H

#include <string>
#include "Vec2.h"

// Class of the stellar objects
class stellar_object {
private: // Separation of concerns. Private parameters.
    const float mass; // Object's relative mass
    std::string name; // Name
    Vec2 position; // Relative position based on a prior Vec2 definition
    Vec2 velocity; // Current relative velocity

public: // Public accessors
    // Constructor
    stellar_object(float m, const std::string& n, const Vec2& pos, const Vec2& v)
    : mass(m), name(n), position(pos), velocity(v) {
    }

    // Getters
    float get_mass() const { return mass; } // Get mass
    const std::string& get_name() const { return name; } // Get name by reference
    Vec2& get_position() { return position; } // Get mutable position by reference
    Vec2& get_velocity() { return velocity; } // Get mutable velocity by reference
    const Vec2& get_position() const { return position; } // Get const position by reference
    const Vec2& get_velocity() const { return velocity; } // Get const velocity by reference

    // Setters
    void set_position(const Vec2& pos) { position = pos; } // Set Position
    void set_velocity(const Vec2& v) { velocity = v; } // Set Velocity
};

#endif