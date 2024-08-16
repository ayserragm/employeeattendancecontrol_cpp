#include "database.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

Database::Database() : dynamicEmployees(nullptr), dynamicEmployeesCount(0)
{
    // Statik array için bellek ayırma
    staticEmployees = new Employee[10];

    // j. Dynamic memory allocation on objects
    dynamicEmployees = nullptr;
}

Database::~Database()
{
    // Statik array için bellek bırakma
    delete[] staticEmployees;

    // Dinamik array için bellek bırakma
    for (int i = 0; i < dynamicEmployeesCount; ++i)
    {
        delete dynamicEmployees[i];
    }
    delete[] dynamicEmployees;
}

void Database::storeInStaticArray(const Employee &employee)
{

    staticEmployees[employees.size()] = employee;
}

void Database::addToDynamicArray(const Employee &employee)
{
    Employee **temp = new Employee *[dynamicEmployeesCount + 1];
    memcpy(temp, dynamicEmployees, dynamicEmployeesCount * sizeof(Employee *));
    temp[dynamicEmployeesCount] = new Employee(employee);
    delete[] dynamicEmployees;
    dynamicEmployees = temp;
    dynamicEmployeesCount++;
}

void Database::deleteFromDynamicArray(int employeeNumber)
{
    for (int i = 0; i < dynamicEmployeesCount; ++i)
    {
        if (dynamicEmployees[i]->getEmployeeNumber() == employeeNumber)
        {
            delete dynamicEmployees[i];
            for (int j = i; j < dynamicEmployeesCount - 1; ++j)
            {
                dynamicEmployees[j] = dynamicEmployees[j + 1];
            }
            dynamicEmployeesCount--;
            break;
        }
    }
}
bool Database::employeeExists(int employeeNumber) const
{
    for (const auto &employee : employees)
    {
        if (employee.getEmployeeNumber() == employeeNumber)
        {
            return true;
        }
    }
    return false;
}

bool Database::addEmployee(const Employee &employee)
{
    if (employeeExists(employee.getEmployeeNumber()))
    {
        std::cout << "Employee with the same ID already exists. Please enter a different ID." << std::endl;
        return false;
    }
    employees.push_back(employee);
    return true;
}

std::vector<Employee> Database::viewAllEmployees() const
{
    if (employees.empty())
    {
        std::cout << "No employees to display." << std::endl;
    }
    else
    {
        std::cout << "Employee Information:" << std::endl;
        for (const auto &employee : employees)
        {
            std::cout << "Name: " << employee.getName() << std::endl;
            std::cout << "Surname: " << employee.getSurname() << std::endl;
            std::cout << "Employee Number: " << employee.getEmployeeNumber() << std::endl;
            std::cout << "Entry Time: " << employee.getEntryTime() << std::endl;
            std::cout << "Entrance Gate: " << employee.getEntranceGate() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }
    return employees;
}

void Database::updateEmployee(int employeeNumber, const Employee &updatedEmployee)
{
    for (auto &employee : employees)
    {
        if (employee.getEmployeeNumber() == employeeNumber)
        {
            employee = updatedEmployee;
            std::cout << "Employee information updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}

void Database::deleteEmployee(int employeeNumber)
{
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->getEmployeeNumber() == employeeNumber)
        {
            employees.erase(it);
            std::cout << "Employee deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}
void Database::markAttendance(const std::string &employeeName, const Attendance &attendance)
{
    for (auto &employee : employees)
    {
        if (employee.getName() == employeeName)
        {
            attendanceRecords.push_back(attendance);
            std::cout << "Attendance marked for employee: " << employeeName << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}
