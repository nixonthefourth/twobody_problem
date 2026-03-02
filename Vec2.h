//
// Created by Mykyta Khomiakov on 02/03/2026.
//

#ifndef TWOBODY_PROBLEM_VEC2_H
#define TWOBODY_PROBLEM_VEC2_H

// Creates position vector of a stellar object
struct Vec2 {
    float x;
    float y;

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(const x_val, float y_val) : x(y_val), y(y_val) {}
};

#endif //TWOBODY_PROBLEM_VEC2_H