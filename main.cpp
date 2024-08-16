#include <iostream>
#include <string>
#include <memory>
#include "database.hpp"
#include "employee.hpp"
#include "file.hpp"
#include "attendance.hpp"
#include "manager.hpp"
#include "worker.hpp"

using namespace std;

int main()
{
    Database db;
    FileManager fileManager("employee.txt");
    std::string employeeName;
    std::string currentDate = "2024-02-02";
    std::string currentTimeIn = "09:00:00";
    std::string currentTimeOut = "17:00:00";
    AttendanceStatus currentStatus = AttendanceStatus::PRESENT;
    Attendance attendance(currentDate, currentTimeIn, currentTimeOut, currentStatus);
    std::string entryTime = "";

    // j. Dynamic memory allocation on objects
    std::cout << "-------------------------" << std::endl;
    Employee *empPtr = new Employee("Emrullah", "Gumustakim", 1, "09:00", 'A', "Manager");
    db.addEmployee(*empPtr);

    empPtr->displayInfo();

    std::vector<Employee> empVector;
    empVector.push_back(*empPtr);
    fileManager.writeData(empVector);
    delete empPtr;
    std::cout << "-------------------------" << std::endl;

    employees.push_back(std::make_unique<Manager>("Ayse Serra", "Gumustakim", 2, "10:00", 'B', "Manager"));
    employees.push_back(std::make_unique<Worker>("Ulker", "Gumustakim", 3, "09:00", 'A', "Worker"));

    for (const auto &emp : employees)
    {
        db.addEmployee(*emp);
    }
    fileManager.writeData(db.viewAllEmployees());

    // m. Static member and static member function
    std::cout << "Total number of employees: " << Employee::getEmployeeCount() << std::endl;

    int choice;
    do
    {
        cout << "Employee Attendance Control System" << std::endl;
        cout << "1. Add Employee" << std::endl;
        cout << "2. View Employee Information" << std::endl;
        cout << "3. Update Employee Information" << std::endl;
        cout << "4. Delete Employee" << std::endl;
        cout << "5. Mark Attendance" << std::endl;
        cout << "6. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Employee ekleme işlemi
            std::string newName, newSurname, newEntryTime, employee_type;
            int newEmployeeNumber;
            char newEntranceGate;

            std::cout << "Enter employee name: ";
            std::cin >> newName;

            std::cout << "Enter employee surname: ";
            std::cin >> newSurname;

            do
            {
                std::cout << "Enter employee number: ";
                std::cin >> newEmployeeNumber;

                if (newEmployeeNumber == 1 || newEmployeeNumber == 2 || newEmployeeNumber == 3)
                {
                    std::cout << "Employee with this ID already exists. Please enter a different ID." << std::endl;
                }
            } while (newEmployeeNumber == 1 || newEmployeeNumber == 2 || newEmployeeNumber == 3);

            std::cout << "Enter employee entry time: ";
            std::cin >> newEntryTime;
            entryTime = newEntryTime;

            std::cout << "Enter employee entrance gate: ";
            std::cin >> newEntranceGate;

            std::cout << "Enter employee type: ";
            std::cin >> employee_type;

            Employee newEmployee(newName, newSurname, newEmployeeNumber, entryTime, newEntranceGate, employee_type);
            if (db.addEmployee(newEmployee))
            {
                fileManager.writeData(db.viewAllEmployees());
                std::cout << "Employee added successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee could not be added due to duplicate ID." << std::endl;
            }
            break;
        }

        case 2:
            // Employee bilgilerini görüntüleme işlemi
            db.viewAllEmployees();
            break;
        case 3:
        {
            // Employee bilgilerini güncelleme işlemi
            int empNumberToUpdate;
            std::cout << "Enter employee number to update: ";
            std::cin >> empNumberToUpdate;

            std::string newName, newSurname, newEntryTime;
            char newEntranceGate;

            std::cout << "Enter new name: ";
            std::cin >> newName;

            std::cout << "Enter new surname: ";
            std::cin >> newSurname;

            std::cout << "Enter new entry time: ";
            std::cin >> newEntryTime;

            std::cout << "Enter new entrance gate: ";
            std::cin >> newEntranceGate;

            Employee updatedEmployee(newName, newSurname, empNumberToUpdate, newEntryTime, newEntranceGate);

            db.updateEmployee(empNumberToUpdate, updatedEmployee);

            fileManager.writeData(db.viewAllEmployees());
            break;
        }

        case 4:
        {
            // Employee silme işlemi
            int empNumberToDelete;
            std::cout << "Enter employee number to delete: ";
            std::cin >> empNumberToDelete;
            db.deleteEmployee(empNumberToDelete);

            fileManager.deleteEmployeeData(empNumberToDelete);
            break;
        }
        case 5:
        {
            // Mark Attendance işlemi
            int employeeNumber;
            std::cout << "Enter employee number: ";
            std::cin >> employeeNumber;
            attendance.markAttendance(employeeNumber, entryTime);
            break;
        }

        case 6:
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
