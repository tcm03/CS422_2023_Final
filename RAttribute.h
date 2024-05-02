#pragma once
#include <string>
#include <ctime>

class RAttribute {
public:
    std::string Name;
    int CachedTime;
    tm LastUpdate;
    static int DefaultCachedTime;

    RAttribute(std::string name, std::string value, int cachedTime);

    std::string GetValue() const; // Question 3
    void SetValue(const std::string& value); // Question 3
    bool NeedToRefresh(); // Question 3
private:
    std::string LastKnownValue;
};