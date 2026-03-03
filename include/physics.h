//
// Created by Mykyta Khomiakov on 02/03/2026.
//

#ifndef TWOBODY_PROBLEM_PHYSICS_H
#define TWOBODY_PROBLEM_PHYSICS_H
#include "Vec2.h"

float find_distance(const Vec2& a, const Vec2& b);
Vec2 find_g_acceleration(float m_a, float distance, const Vec2& a, const Vec2& b);
float find_esc_vel(float m, float distance);
float choose_vel(float escape_vel);
float find_energy(float vel, float distance, float m);
Vec2 find_vel_direction(const Vec2& a, const Vec2& b, float distance, float vel);

#endif //TWOBODY_PROBLEM_PHYSICS_H