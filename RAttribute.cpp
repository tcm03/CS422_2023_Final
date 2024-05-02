#include "RAttribute.h"
#include <iostream>

int RAttribute::DefaultCachedTime = 10; // in second

RAttribute::RAttribute(std::string name, std::string value, int cachedTime) {
    Name = name;
    LastKnownValue = value;
    CachedTime = cachedTime;
    time_t now = time(0);
    LastUpdate = *localtime(&now);
}

// Question 3
bool RAttribute::NeedToRefresh() {
    time_t now = time(0); // get the current time
    return difftime(now, mktime(&LastUpdate)) > CachedTime;
}

// Question 3
std::string RAttribute::GetValue() const {
    return LastKnownValue;
}

// Question 3
void RAttribute::SetValue(const std::string& value) {
    LastKnownValue = value;
    time_t now = time(0);
    LastUpdate = *localtime(&now);
}