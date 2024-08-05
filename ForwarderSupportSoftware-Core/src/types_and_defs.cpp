#include "types_and_defs.h"

Vec3 convertToMeters(Vec3& value, int8_t unit) {
    switch (unit) {
    case 0: return value * 1.0f;     // meters
    case 1: return value * 0.01f;    // centimeters
    case 2: return value * 0.001f;   // millimeters
    case 3: return value * 0.0254f;  // inches
    }
    return value;
}

const void convertToMeters(float& value, int8_t unit) {
    switch (unit) {
    case 0: value *= 1.0f; break;     // meters
    case 1: value *= 0.01f; break;    // centimeters
    case 2: value *= 0.001f; break;   // millimeters
    case 3: value *= 0.0254f; break;  // inches
    }
}

const void convertToMeters(Cargo* values, int size)
{
    for (int i = 0; i < size; i++)
    {
        switch (values[i].measurement) {
            case 0: values[i].dimension *= 1.0f; break;     // meters
            case 1: values[i].dimension *= 0.01f; break;    // centimeters
            case 2: values[i].dimension *= 0.001f; break;   // millimeters
            case 3: values[i].dimension *= 0.0254f; break;  // inches
        }
    }
}


Vec3 convertToCentimeters(Vec3& value, int8_t unit) {
    switch (unit) {
    case 0: // meters
        return value * 100.0f;
    case 1: // centimeters
        return value;
    case 2: // mm
        return value / 10.0f;
    case 3: // inches
        return value * 2.54f;
    default:
        return value;
    }
}

void convertToCentimeters(float& value, int8_t unit) {
    switch (unit) {
    case 0: // meters
        value *= 100.0f; break;
    case 1: // centimeters
        value; break;
    case 2: // mm
        value /= 10.0f; break;
    case 3: // inches
        value *= 2.54f; break;
    default:
        value; break;
    }
}

void convertToCentimeters(Cargo* values, int size) {
    for (int i = 0;i<size;i++)
    {
        switch (values[i].measurement) {
        case Cargo::measurement_t::M: // meters
            values[i].dimension *= 100.0f;
            break;
        case Cargo::measurement_t::CM: // centimeters
            values[i].dimension;

            break;
        case Cargo::measurement_t::MM: // mm
            values[i].dimension /= 10.0f;
            break;
        case Cargo::measurement_t::INCH: // inches
            values[i].dimension *= 2.54f;
            break;
        default:
            values[i].dimension;

            break;
        }
    }
}
