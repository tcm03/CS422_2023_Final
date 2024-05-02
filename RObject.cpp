#include "RObject.h"
#include "RAttribute.h"
#include "RObjectManager.h"
#include <cassert>

RObject::RObject() {
    ID = RObjectManager::CreateObject();
}

void RObject::AddNewAttribute(std::string strAttributeName, std::string value, int cachedTime) {
    Attributes[strAttributeName] = new RAttribute(strAttributeName, value, cachedTime);
    if (RObjectManager::SetObjectAttributeValue(this->ID, strAttributeName, value) == false) {
        // if the server doesn't contain this object, it shouldn't be cached at the client side
        assert(false);
    }
}

// Question 4
void RObject::SetAttribute(std::string strAttributeName, std::string newValue) {
    if (Attributes.find(strAttributeName) == Attributes.end()) {
        AddNewAttribute(strAttributeName, newValue, RAttribute::DefaultCachedTime);
    }
    else {
        Attributes[strAttributeName]->SetValue(newValue);
        if (RObjectManager::SetObjectAttributeValue(this->ID, strAttributeName, newValue) == false) {
            // if the server doesn't contain this object, it shouldn't be cached at the client side
            assert(false);
        }
    }
}

// Question 5
std::string RObject::GetAttribute(std::string strAttributeName) {
    if (Attributes.find(strAttributeName) == Attributes.end()) {
        std::string m_value = RObjectManager::GetObjectAttributeValue(this->ID, strAttributeName);
        int m_cachedTime = RObjectManager::GetObjectAttributeCachedTime(this->ID, strAttributeName);
        AddNewAttribute(strAttributeName, m_value, m_cachedTime);
    }
    else {
        std::string Rvalue = RObjectManager::GetObjectAttributeValue(this->ID, strAttributeName);
        Attributes[strAttributeName]->SetValue(Rvalue);
    }
    return Attributes[strAttributeName]->GetValue();
}

// for testing caching
bool RObject::NeedToRefresh(std::string strAttributeName) {
    if (Attributes.find(strAttributeName) == Attributes.end()) {
        return false;
    }
    return Attributes[strAttributeName]->NeedToRefresh();
}

RObject::~RObject() {
    for (auto it = Attributes.begin(); it != Attributes.end(); it++) {
        delete it->second;
    }
    Attributes.clear();
}

