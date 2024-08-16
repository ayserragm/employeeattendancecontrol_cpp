#include "manager.hpp"
#include <iostream>

Manager::Manager(std::string name, std::string surname, int employeeNumber, std::string entryTime, char entranceGate, std::string employeeType)
    : Employee(name, surname, employeeNumber, entryTime, entranceGate, "Manager") {}

void Manager::displayInfo() const
{
    std::cout << "Manager Information:" << std::endl;
    Employee::displayInfo();
}
