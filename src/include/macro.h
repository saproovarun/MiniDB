#pragma once

#include <cctype>
#include <algorithm>


#define TO_UPPER(src) ([](std::string s) -> std::string {\
    for(auto &c : s) c = std::toupper(c);\
    return s;}(src))


#define TO_LOWER(src) ([](std::string s) -> std::string {\
    for(auto &c : s) c = std::tolower(c);\
    return s;}(src))

