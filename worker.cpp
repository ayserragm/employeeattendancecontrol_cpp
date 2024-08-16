#include "worker.hpp"
#include <iostream>

Worker::Worker(std::string name, std::string surname, int employeeNumber, std::string entryTime, char entranceGate, std::string employeeType)
    : Employee(name, surname, employeeNumber, entryTime, entranceGate, "Worker") {}

void Worker::displayInfo() const
{
    std::cout << "Worker Information:" << std::endl;
    Employee::displayInfo();
}