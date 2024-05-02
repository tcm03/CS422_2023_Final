#include "MObject.h"
#include "MObjectManager.h"

MObject::MObject() {
    MObjectManager::Register(this);
}

MObject::~MObject() {
    for (auto it = Attributes.begin(); it != Attributes.end(); it++) {
        delete it->second;
    }
    Attributes.clear();
}

int MObject::GetCachedTime(const std::string& name) {
    if (Attributes.find(name) == Attributes.end()) {
        return -1;
    }
    return Attributes[name]->CachedTime;
}

// Question 2
std::string MObject::GetAttribute(const std::string& name) {
    if (Attributes.find(name) == Attributes.end()) {
        return "";
    }
    return Attributes[name]->Value;
}

// Question 2
void MObject::SetAttribute(const std::string& name, const std::string& value) {
    if (Attributes.find(name) == Attributes.end()) {
        MAttribute* m_attr = new MAttribute(name, value, MAttribute::DefaultCachedTime);
        Attributes[name] = m_attr;
    }
    else {
        Attributes[name]->Value = value;
    }
}