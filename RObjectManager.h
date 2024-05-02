#pragma once
#include <string>

class RObjectManager {
public:
    static int CreateObject();
    static std::string GetObjectAttributeValue(int id, std::string strAttributeName);
    static int GetObjectAttributeCachedTime(int id, std::string strAttributeName);
    static bool SetObjectAttributeValue(int id, std::string strAttributeName, std::string newValue);
};