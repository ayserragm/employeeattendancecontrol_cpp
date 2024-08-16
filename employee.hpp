#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee
{
private:
    std::string name;
    std::string surname;
    int employeeNumber;
    std::string entryTime;
    char entranceGate;
    std::string employeeType;
    static int employeeCount;

public:
    Employee(std::string name = "", std::string surname = "", int employeeNumber = 0, std::string entryTime = "", char entranceGate = '\0', std::string employeeType = "");

    ~Employee();

    virtual void displayInfo() const;

    bool operator==(const Employee &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Employee &emp);

    std::string getName() const;
    void setName(std::string newName);

    std::string getSurname() const;
    void setSurname(std::string newSurname);

    int getEmployeeNumber() const;
    void setEmployeeNumber(int newEmployeeNumber);

    std::string getEntryTime() const;
    void setEntryTime(std::string newEntryTime);

    char getEntranceGate() const;
    void setEntranceGate(char newEntranceGate);

    std::string getEmployeeType() const;
    void setEmployeeType(std::string newEmployeeType);

    static int getEmployeeCount();
};

#endif
