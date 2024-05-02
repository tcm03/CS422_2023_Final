#include "MObjectManager.h"

int MObjectManager::nextAvailableID = 1;

std::map<int, MObject*> MObjectManager::objects;

void MObjectManager::Register(MObject* mObject) {
    mObject->ID = nextAvailableID++;
    objects[mObject->ID] = mObject;
}

int MObjectManager::CreateObject() {
    MObject* mObject = new MObject();
    return mObject->ID;
}

MObject* MObjectManager::FindObjectByID(int id) {
    if (objects.find(id) != objects.end()) {
        return objects[id];
    }
    return nullptr;
}

bool MObjectManager::SetObjectAttributeValue(int id, std::string sAttributeName, std::string newValue) {
    MObject* m_obj = FindObjectByID(id);
    if (m_obj == nullptr)
        return false;
    m_obj->SetAttribute(sAttributeName, newValue);
    return true;
}

std::string MObjectManager::GetObjectAttributeValue(int id, std::string sAttributeName) {
    MObject* m_obj = FindObjectByID(id);
    if (m_obj == nullptr)
        return "";
    return m_obj->GetAttribute(sAttributeName);
}

int MObjectManager::GetObjectAttributeCachedTime(int id, std::string strAttributeName) {
    MObject* m_obj = FindObjectByID(id);
    if (m_obj == nullptr)
        return MAttribute::DefaultCachedTime;
    return m_obj->GetCachedTime(strAttributeName);
}

MObjectManager::~MObjectManager() {
    for (auto it = objects.begin(); it != objects.end(); it++) {
        delete it->second;
    }
    objects.clear();
}