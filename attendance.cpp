#include <iomanip>
#include <sstream>
#include <ctime>
#include <iostream>
#include "attendance.hpp"

using namespace std;

Attendance::Attendance(std::string date, std::string timeIn, std::string timeOut, AttendanceStatus status)
    : date(date), timeIn(timeIn), timeOut(timeOut), status(status), markAttendanceFunction(nullptr) {}

std::string Attendance::getDate() const
{
    return date;
}

void Attendance::setDate(std::string newDate)
{
    date = newDate;
}

std::string Attendance::getTimeIn() const
{
    return timeIn;
}

void Attendance::setTimeIn(std::string newTimeIn)
{
    timeIn = newTimeIn;
}

std::string Attendance::getTimeOut() const
{
    return timeOut;
}

void Attendance::setTimeOut(std::string newTimeOut)
{
    timeOut = newTimeOut;
}
AttendanceStatus Attendance::getStatus() const
{
    return status;
}

void Attendance::setStatus(AttendanceStatus newStatus)
{
    status = newStatus;
}

void Attendance::setMarkAttendanceFunction(std::function<void(int, const std::string &)> function)
{
    markAttendanceFunction = function;
}
void Attendance::markAttendance(int employeeNumber, const std::string &entryTime)
{
    if (markAttendanceFunction != nullptr)
    {

        markAttendanceFunction(employeeNumber, entryTime);
    }
    else
    {

        std::tm entryTimeStruct;
        std::istringstream entryStream(entryTime);
        entryStream >> std::get_time(&entryTimeStruct, "%H:%M:%S");

        if (entryTimeStruct.tm_hour >= 9 && entryTimeStruct.tm_hour < 17)
        {
            status = AttendanceStatus::PRESENT;
        }
        else
        {
            status = AttendanceStatus::ABSENT;
        }

        std::cout << "Attendance marked for employee number: " << employeeNumber << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << entryTime << std::endl;
        std::cout << "Status: " << (status == AttendanceStatus::PRESENT ? "PRESENT" : "ABSENT") << std::endl;
    }
}
