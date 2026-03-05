//
// Created by Mykyta Khomiakov on 02/03/2026.
//

#ifndef TWOBODY_PROBLEM_VEC2_H
#define TWOBODY_PROBLEM_VEC2_H
#include <iostream>

/// @brief Creates a position vector of a stellar object
/// @param x Horizontal vector component
/// @param y Vertical vector component
struct Vec2 {
    float x;
    float y;

    // Constructors
    Vec2() : x(0.f), y(0.f) {}
    Vec2(float xVal, float yVal) : x(xVal), y(yVal) {}

    /// @brief Scalar multiplication
    /// @param scalar Scalar constant by which vector is multiplied
    /// @details Allows to multiply Vec2 structure by `scalar` parameter only.
    /// @return Returns the multiplied Vec2 implicitly.
    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    /// @brief In-place multiplication via `*=`
    /// @param scalar Scalar constant by which vector is multiplied
    /// @return Returns a multiplied Vec2 structure
    Vec2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    /// @brief Perpendicular vector
    /// @details Flips the vector from assumed radius to perpendicular
    /// @return Returns the same Vec2 structure, however containing -y and +x
    Vec2 perpendicular() const {
        return Vec2(-y, x);
    }

    /// @brief Scalar division.
    /// @param scalar Scalar constant by which the vector is multiplied.
    /// @details Checks whether the constant is non-zero to allow operation.
    /// @return Returns a new Vec2 value of divided `x` and `y`
    Vec2 operator/(float scalar) const {
        if (scalar != 0.f) {
            return Vec2(x / scalar, y / scalar);
        }
    }

    /// @brief In-place scalar division.
    /// @param scalar Scalar constant by which the vector is multiplied.
    /// @details Checks whether the constant is non-zero to allow operation.
    /// @return Returns a divided Vec2 structure.
    Vec2& operator/=(float scalar) {
        if (scalar != 0.f) {
            x /= scalar;
            y /= scalar;
            return *this;
        }
    }

    /// @brief Allows subtraction between two Vec2 structures
    /// @param other Simply takes the Vec2 objects by reference
    /// @details Allows subtraction from either positions
    /// @return Returns the direct Vec2 subtraction.
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    /// @brief Allows in-place subtraction
    /// @param other Simply takes the Vec2 structure by reference
    /// @details Allows subtraction from the Vec2 structure
    /// @return Returns the in-place Vec2 subtraction.
    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    /// @brief Addition of two Vec2 structures.
    /// @param other Simply takes the Vec2 structure by reference.
    /// @return Returns added Vec2 structures.
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    /// @brief In-place addition of the Vec2 structures.
    /// @param other Other Vec2 structure at hand.
    /// @return Returns the referenced Vec2 as an added value.
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

};

/// @brief Reverse operand positioning through accessing `*` operator.
/// @param scalar Scalar multiplication constant.
/// @param v Value by reference of the Vec2 structure.
/// @return Returns multiplied value of Vec2 as `k * (i, j)`.
inline Vec2 operator*(float scalar, const Vec2& v) {
    return Vec2(v.x * scalar, v.y * scalar);
}

/// @brief Stream output for Vec2, e.g. std::cout << position.
/// @return Returns a value of Vec2 inc std::cout fashion
inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

#endif //TWOBODY_PROBLEM_VEC2_H