#include <iostream>
#include "RObject.h"
#include "MObject.h"
#include "RObjectManager.h"
#include "MObjectManager.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // created at the client side
    RObject student1;
    student1.SetAttribute("name", "Harry Potter");
    student1.SetAttribute("age", "18");
    student1.SetAttribute("house", "Gryffindor");
    // queried at the client side
    std::cout << "Name of student 1: " << student1.GetAttribute("name") << "\n";
    std::cout << "Age of student 1: " << student1.GetAttribute("age") << "\n";
    std::cout << "House of student 1: " << student1.GetAttribute("house") << "\n";

    // created at the server side
    MObject student2;
    student2.SetAttribute("name", "Hermione Granger");
    student2.SetAttribute("age", "18");
    student2.SetAttribute("house", "Gryffindor");
    // queried at the client side
    std::cout << "Name of student 2: " << RObjectManager::GetObjectAttributeValue(student2.ID, "name") << "\n";
    std::cout << "Age of student 2: " << RObjectManager::GetObjectAttributeValue(student2.ID, "age") << "\n";
    std::cout << "House of student 2: " << RObjectManager::GetObjectAttributeValue(student2.ID, "house") << "\n";

    // updated at the server side
    MObjectManager::SetObjectAttributeValue(1, "name", "Ron Weasley");
    std::cout << "Refreshing status of student 1: " << student1.NeedToRefresh("name") << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(11000)); // wait for 11s
    std::cout << "Refreshing status of student 1: " << student1.NeedToRefresh("name") << "\n";
    // queried at the client side
    std::cout << "Name of student 1: " << student1.GetAttribute("name") << "\n";
    std::cout << "Age of student 1: " << student1.GetAttribute("age") << "\n";
    std::cout << "House of student 1: " << student1.GetAttribute("house") << "\n";

    return 0;
}