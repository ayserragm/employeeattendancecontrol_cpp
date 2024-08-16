#ifndef FILE_HPP
#define FILE_HPP

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "employee.hpp"

class FileManager
{
public:
    FileManager(const std::string &fileName);

    int writeData(const std::vector<Employee> &employees);
    std::vector<Employee> readData();
    bool deleteEmployeeData(int employeeNumber);

private:
    std::string fileName;
};

#endif
