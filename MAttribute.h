#pragma once
#include <string>

class MAttribute {
public:
    std::string Name;
    std::string Value;
    int CachedTime;
    static int DefaultCachedTime; // seconds

    MAttribute(std::string name, std::string value, int cachedTime);
    //MAttribute& operator =(const MAttribute& other);
};