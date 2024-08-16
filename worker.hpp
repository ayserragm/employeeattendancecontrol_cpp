#ifndef WORKER_HPP
#define WORKER_HPP

#include "employee.hpp"

class Worker : public Employee
{
public:
    Worker(std::string name, std::string surname, int employeeNumber, std::string entryTime, char entranceGate, std::string employeeType);

    void displayInfo() const override;
};

#endif
