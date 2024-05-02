#pragma once
#include <map>
#include "RAttribute.h"

class RObject {
protected:
    int ID;
    std::map<std::string, RAttribute*> Attributes;
public:
    RObject();
    ~RObject();
    
    // Question 4
    void SetAttribute(std::string strAttributeName, std::string newValue);
    // Question 5
    std::string GetAttribute(std::string strAttributeName);

    // for testing caching
    bool NeedToRefresh(std::string strAttributeName);
private:
    void AddNewAttribute(std::string strAttributeName, std::string value, int cachedTime);
};