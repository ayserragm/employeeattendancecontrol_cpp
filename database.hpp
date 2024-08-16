#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include "employee.hpp"
#include "attendance.hpp"
#include "manager.hpp"
class Database
{
private:
    std::vector<Employee> employees;
    std::vector<Manager> managers;
    std::vector<Attendance> attendanceRecords;
    Employee *staticEmployees;
    Employee **dynamicEmployees;
    int dynamicEmployeesCount;

public:
    Database();

    ~Database();

    bool addEmployee(const Employee &employee);
    std::vector<Employee> viewAllEmployees() const;
    void updateEmployee(int employeeNumber, const Employee &updatedEmployee);
    void deleteEmployee(int employeeNumber);
    void markAttendance(const std::string &employeeId, const Attendance &attendance);
    bool employeeExists(int employeeNumber) const;
    void storeInStaticArray(const Employee &employee);
    void addToDynamicArray(const Employee &employee);
    void deleteFromDynamicArray(int employeeNumber);
};

#endif