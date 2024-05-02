#pragma once
#include <string>
#include <map>
#include "MObject.h"

class MObjectManager {
public:
    static std::map<int, MObject*> objects;
    
    static void Register(MObject* mObject);
    static int CreateObject();
    static bool SetObjectAttributeValue(int id, std::string sAttributeName, std::string newValue);
    static std::string GetObjectAttributeValue(int id, std::string sAttributeName);
    static int GetObjectAttributeCachedTime(int id, std::string strAttributeName);

    ~MObjectManager();
private:
    static MObject* FindObjectByID(int id);
    static int nextAvailableID;
};