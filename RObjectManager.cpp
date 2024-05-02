#include "RObjectManager.h"
#include "MObjectManager.h"

int RObjectManager::CreateObject() {
    return MObjectManager::CreateObject();
}

int RObjectManager::GetObjectAttributeCachedTime(int id, std::string strAttributeName) {
    return MObjectManager::GetObjectAttributeCachedTime(id, strAttributeName);
}

std::string RObjectManager::GetObjectAttributeValue(int id, std::string strAttributeName) {
    return MObjectManager::GetObjectAttributeValue(id, strAttributeName);
}

bool RObjectManager::SetObjectAttributeValue(int id, std::string strAttributeName, std::string newValue) {
    return MObjectManager::SetObjectAttributeValue(id, strAttributeName, newValue);
}