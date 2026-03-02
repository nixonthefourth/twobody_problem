#ifndef TWOBODY_PROBLEM_STELLAR_OBJECT_H
#define TWOBODY_PROBLEM_STELLAR_OBJECT_H

#include <string>
#include "Vec2.h"

// Class of the stellar objects
class stellar_object {
private: // Separation of concerns. Private parameters.
    const int mass; // Object's relative mass
    std::string name; // Name
    Vec2 position; // Relative position based on a prior Vec2 definition
    Vec2 velocity; // Current relative velocity

public: // Public accessors
    stellar_object(int m, const std::string& n, const Vec2& pos, const Vec2& v)
    : mass(m), name(n), position(pos), velocity(v) {
    }

    // Getters
    int get_mass() const { return mass; } // Get mass
    const std::string& get_name() const { return name; } // Get name by reference
    const Vec2& get_position() const { return position; } // Get current position by reference
    const Vec2& get_velocity() const { return velocity; } // Get current velocity by reference

    // Setters
    // Set Name
    void set_name(const std::string& n) { if (n.length() > 0) name = n; }

    // Set Position
    void set_position(const Vec2& pos) { position = pos; }

    // Set Velocity
    void set_velocity(const Vec2& v) { velocity = v; }
};

#endif