#ifndef TYPES_AND_DEFS_H
#define TYPES_AND_DEFS_H

#include <cstdint>
#include <array>


struct Vec2
{
    float x, y;
};

struct Vec3
{
    float x, y, z;

    // Multiplication operators
    Vec3 operator* (const Vec3& other) const {
        return Vec3{x * other.x, y * other.y, z * other.z};
    }

    Vec3 operator* (const float& scalar) const {
        return Vec3{x * scalar, y * scalar, z * scalar};
    }

    // Division operators
    Vec3 operator/ (const Vec3& other) const {
        // Avoid division by zero
        return Vec3{other.x != 0.0f ? x / other.x : 0.0f,
                    other.y != 0.0f ? y / other.y : 0.0f,
                    other.z != 0.0f ? z / other.z : 0.0f};
    }

    Vec3 operator/ (const float& scalar) const {
        // Avoid division by zero
        return scalar != 0.0f ? Vec3{x / scalar, y / scalar, z / scalar} : Vec3{0.0f, 0.0f, 0.0f};
    }

    // Compound assignment operators
    Vec3& operator*= (const Vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }
    Vec3& operator*=(float value) {
        x *= value;
        y *= value;
        z *= value;
        return *this;
    }

    Vec3& operator/= (const Vec3& other) {
        // Avoid division by zero
        if (other.x != 0.0f) x /= other.x;
        if (other.y != 0.0f) y /= other.y;
        if (other.z != 0.0f) z /= other.z;
        return *this;
    }

    Vec3& operator/= (const float& scalar) {
        // Avoid division by zero
        if (scalar != 0.0f) {
            x /= scalar;
            y /= scalar;
            z /= scalar;
        }
        return *this;
    }

    bool operator<(const Vec3& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }

    bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

};

// Implement the comparison operator for std::map key
struct Vec3Compare {
    bool operator()(const Vec3& lhs, const Vec3& rhs) const {
        return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y) || (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z < rhs.z);
    }
};

struct Cargo
{
    enum  measurement_t
    {
        M, CM, MM, INCH, MAX
    } measurement;

    float dimension;
};

Vec3 convertToMeters(Vec3& value, int8_t unit);
const void convertToMeters (float& value, int8_t unit);
const void convertToMeters(Cargo* values, int size);


Vec3 convertToCentimeters(Vec3& value, int8_t unit);

void convertToCentimeters(float& value, int8_t unit);
void convertToCentimeters(Cargo* values, int size);

#endif // TYPES_AND_DEFS_H