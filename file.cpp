
#include "file.hpp"
#include <algorithm>

FileManager::FileManager(const std::string &fileName) : fileName(fileName) {}

// Verileri dosyaya yazma,Storing objects in vector
int FileManager::writeData(const std::vector<Employee> &employees)
{
    std::ofstream file(fileName);
    if (file.is_open())
    {
        for (const auto &employee : employees)
        {
            file << "Name: " << employee.getName() << " -Surname: " << employee.getSurname() << " -Employee Id: " << employee.getEmployeeNumber() << " -Entry Time: " << employee.getEntryTime() << " -The Entrance Gate: " << employee.getEntranceGate() << " Employee Type: " << employee.getEmployeeType() << std::endl;
        }
        file.close();
        std::cout << "Data has been written to file successfully." << std::endl;
        return 1;
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 0;
    }
}

// Dosyadan veri okuma. Adding objects in vector
std::vector<Employee> FileManager::readData()
{
    std::vector<Employee> employees;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string name, surname, entryTime;
            int employeeNumber;
            char entranceGate;
            if (std::getline(iss, name, ',') &&
                std::getline(iss, surname, ',') &&
                iss >> employeeNumber >> std::ws &&
                std::getline(iss, entryTime, ',') &&
                iss >> entranceGate)
            {
                employees.emplace_back(name, surname, employeeNumber, entryTime, entranceGate);
            }
        }
        file.close();
        std::cout << "Data has been read from file successfully." << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return employees;
}

bool FileManager::deleteEmployeeData(int employeeNumber)
{
    std::vector<Employee> employees = readData();

    std::vector<Employee> remainingEmployees;
    for (const auto &employee : employees)
    {
        if (employee.getEmployeeNumber() != employeeNumber)
        {
            remainingEmployees.push_back(employee);
        }
    }

    writeData(remainingEmployees);

    if (remainingEmployees.size() < employees.size())
    {
        std::cout << "Employee data deleted successfully from the file." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Employee not found in the file." << std::endl;
        return false;
    }
}
