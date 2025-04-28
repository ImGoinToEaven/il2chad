#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

struct vector2f {
    float x, y;

    float magnitude() const { return std::sqrt(x * x + y * y); }

    float magnitude_squared() const { return x * x + y * y; }

    float distance(const vector2f &other) const {
        float dx = x - other.x;
        float dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    float distance_squared(const vector2f &other) const {
        float dx = x - other.x;
        float dy = y - other.y;
        return dx * dx + dy * dy;
    }

    void normalize() {
        float mag = magnitude();
        if (mag > 0.0f) {
            x /= mag;
            y /= mag;
        }
    }

    vector2f normalized() const {
        vector2f result = *this;
        result.normalize();
        return result;
    }

    float dot(const vector2f &other) const { return x * other.x + y * other.y; }

    // Returns angle in radians between this vector and other
    float angle_to(const vector2f &other) const {
        float dotProd = dot(other);
        float mags = magnitude() * other.magnitude();
        if (mags > 0.0f) {
            return std::acos(dotProd / mags);
        }
        return 0.0f;
    }

    // Angle utilities
    static float deg_to_rad(float degrees) { return degrees * static_cast<float>(M_PI) / 180.0f; }

    static float rad_to_deg(float radians) { return radians * 180.0f / static_cast<float>(M_PI); }

    // Returns the angle of this vector in radians relative to positive x-axis
    float angle() const { return std::atan2(y, x); }

    // Returns the angle of this vector in degrees
    float angle_deg() const { return rad_to_deg(angle()); }

    // Creates a vector from angle (in radians) and magnitude
    static vector2f from_angle(float radians, float magnitude = 1.0f) {
        return vector2f(std::cos(radians) * magnitude, std::sin(radians) * magnitude);
    }

    static vector2f from_angle_deg(float degrees, float magnitude = 1.0f) {
        return from_angle(deg_to_rad(degrees), magnitude);
    }

    vector2f &operator=(const vector2f &other) = default;

    vector2f operator+(const vector2f &other) const { return vector2f(x + other.x, y + other.y); }

    vector2f &operator+=(const vector2f &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    vector2f operator-(const vector2f &other) const { return vector2f(x - other.x, y - other.y); }

    vector2f &operator-=(const vector2f &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vector2f operator*(float scalar) const { return vector2f(x * scalar, y * scalar); }

    vector2f &operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    vector2f operator/(float scalar) const { return vector2f(x / scalar, y / scalar); }

    vector2f &operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool operator==(const vector2f &other) const {
        const float epsilon = 0.0001f;
        return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon;
    }

    bool operator!=(const vector2f &other) const { return !(*this == other); }

    friend std::ostream &operator<<(std::ostream &os, const vector2f &vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    static vector2f zero() { return vector2f(0.0f, 0.0f); }
    static vector2f one() { return vector2f(1.0f, 1.0f); }
    static vector2f up() { return vector2f(0.0f, 1.0f); }
    static vector2f down() { return vector2f(0.0f, -1.0f); }
    static vector2f left() { return vector2f(-1.0f, 0.0f); }
    static vector2f right() { return vector2f(1.0f, 0.0f); }
};

inline vector2f operator*(float scalar, const vector2f &vec) { return vec * scalar; }
