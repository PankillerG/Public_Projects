#include <iostream>
#include <string>

std::string DetectType(const unsigned char* data, size_t size) {
    bool flag_1 = false, flag_2 = false, flag_3 = false;
    if (size >= 2) {
        if (static_cast<int>(*data) == 80) {
            data++;
            if (static_cast<int>(*data) == 75) {
                return "zip";
            }
        }
    }
    if (size >= 3) {
        if (static_cast<int>(*data) == 255) {
            data++;
            if (static_cast<int>(*data) == 216) {
                data++;
                if (static_cast<int>(*data) == 255) {
                    return "jpg";
                }
            }
        }
    }
    if (size >= 3) {
        if (static_cast<int>(*data) == 37) {
            data++;
            if (static_cast<int>(*data) == 80) {
                data++;
                if (static_cast<int>(*data) == 68) {
                    data++;
                    if (static_cast<int>(*data) == 70) {
                        return "pdf";
                    }
                }
            }
        }
    }
    return "other";
}
