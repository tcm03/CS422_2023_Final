#include <string>
#include "MAttribute.h"

int MAttribute::DefaultCachedTime = 10; // in second

MAttribute::MAttribute(std::string name, std::string value, int cachedTime) {
    Name = name;
    Value = value;
    CachedTime = cachedTime;
}

// MAttribute& MAttribute::operator =(const MAttribute& other) {
//     if (this == &other || this->Name != other.Name || this->Value == other.Value) {
//         return *this;
//     }
//     this->Value = other.Value;
//     this->CachedTime = other.CachedTime;
//     return *this;
// }