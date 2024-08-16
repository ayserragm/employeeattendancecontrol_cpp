#include "employee.hpp"
#include <iostream>

Employee::Employee(std::string name, std::string surname, int employeeNumber, std::string entryTime, char entranceGate, std::string employeeType)
    : name(name), surname(surname), employeeNumber(employeeNumber), entryTime(entryTime), entranceGate(entranceGate), employeeType(employeeType)
{
    employeeCount++;
}

Employee::~Employee()
{
    employeeCount--;
}

int Employee::employeeCount = 0;

void Employee::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Employee Number: " << employeeNumber << std::endl;
    std::cout << "Entry Time: " << entryTime << std::endl;
    std::cout << "Entrance Gate: " << entranceGate << std::endl;
}

bool Employee::operator==(const Employee &other) const
{
    return (employeeNumber == other.employeeNumber);
}

std::ostream &operator<<(std::ostream &os, const Employee &emp)
{
    os << "Name: " << emp.name << std::endl;
    os << "Surname: " << emp.surname << std::endl;
    os << "Employee Number: " << emp.employeeNumber << std::endl;
    os << "Entry Time: " << emp.entryTime << std::endl;
    os << "Entrance Gate: " << emp.entranceGate << std::endl;
    return os;
}

std::string Employee::getName() const
{
    return name;
}

void Employee::setName(std::string newName)
{
    name = newName;
}

std::string Employee::getSurname() const
{
    return surname;
}

void Employee::setSurname(std::string newSurname)
{
    surname = newSurname;
}

int Employee::getEmployeeNumber() const
{
    return employeeNumber;
}

void Employee::setEmployeeNumber(int newEmployeeNumber)
{
    employeeNumber = newEmployeeNumber;
}
std::string Employee::getEntryTime() const
{
    return entryTime;
}

void Employee::setEntryTime(std::string newEntryTime)
{
    entryTime = newEntryTime;
}

char Employee::getEntranceGate() const
{
    return entranceGate;
}

void Employee::setEntranceGate(char newEntranceGate)
{
    entranceGate = newEntranceGate;
}
std::string Employee::getEmployeeType() const
{
    return employeeType;
}

void Employee::setEmployeeType(std::string newEmployeeType)
{
    employeeType = newEmployeeType;
}

int Employee::getEmployeeCount()
{
    return employeeCount;
}