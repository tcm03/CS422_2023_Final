#pragma once
#include <string>
#include <map>
#include "MAttribute.h"

class MObject {
public:
    int ID;

    MObject();
    ~MObject();
    std::string GetAttribute(const std::string& name); // Question 2
    void SetAttribute(const std::string& name, const std::string& value); // Question 2
    int GetCachedTime(const std::string& name);
protected:
    std::map<std::string, MAttribute*> Attributes;
};