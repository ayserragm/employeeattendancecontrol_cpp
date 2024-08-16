#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "employee.hpp"
#include <iostream>

class Manager : public Employee
{
public:
    Manager(std::string name, std::string surname, int employeeNumber, std::string entryTime, char entranceGate, std::string employeeType);

    void displayInfo() const override;
};

#endif
