#pragma once

#include <string>

constexpr int MAJOR_VERSION = 0;
constexpr int MINOR_VERSION = 6;
constexpr int PATCH_VERSION = 4;
constexpr std::string_view CODE_NAME = "ALPHA FISH";

inline std::string GetVersionString() {
    return std::to_string(MAJOR_VERSION) + "." +
        std::to_string(MINOR_VERSION) + "." +
        std::to_string(PATCH_VERSION) + 
        " (" + CODE_NAME.data() + ")";
}
