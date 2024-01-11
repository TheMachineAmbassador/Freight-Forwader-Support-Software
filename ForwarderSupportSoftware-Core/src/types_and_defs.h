#ifndef TYPES_AND_DEFS_H
#define TYPES_AND_DEFS_H

#include <Windows.h>

#include <string>

#include <cassert>


struct Vec3
{
    float x, y, z;

    Vec3 operator* (const Vec3& data)
    {
        x *= data.x;
        y *= data.y;
        z *= data.z;
        return *this;
    }

    Vec3 operator*(const float& data)
    {
        x *= data;
        y *= data;
        z *= data;

        return *this;
    }

    Vec3& operator*= (const Vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    };

    Vec3& operator*= (const float& other) {
        x *= other;
        y *= other;
        z *= other;
        return *this;
    };
    Vec3 operator/ (const Vec3& data)
    {
        x *= data.x;
        y *= data.y;
        z *= data.z;
        return *this;
    }

    Vec3 operator/(const float& data)
    {
        x *= data;
        y *= data;
        z *= data;
        return *this;
    }

    Vec3& operator/= (const Vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    };

    Vec3& operator/= (const float& other) {
        x *= other;
        y *= other;
        z *= other;
        return *this;
    };
};

Vec3 convertToMeters(Vec3& value, int8_t unit);
const void convertToMeters (float& value, int8_t unit);

Vec3 convertToCentimeters(Vec3& value, int8_t unit);
const void convertToCentimeters(float& value, int8_t unit);

void CopyClipboard(std::string& output);

#endif // TYPES_AND_DEFS_H