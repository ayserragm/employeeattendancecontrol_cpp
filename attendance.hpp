#ifndef ATTENDANCE_HPP
#define ATTENDANCE_HPP

#include <string>
#include <vector>
#include <functional>

enum class AttendanceStatus
{
    PRESENT,
    ABSENT,
    UNKNOWN
};

class Attendance
{
private:
    std::string date;
    std::string timeIn;
    std::string timeOut;
    AttendanceStatus status;

    // function pointer
    std::function<void(int, const std::string &)> markAttendanceFunction;

public:
    Attendance(std::string date, std::string timeIn, std::string timeOut, AttendanceStatus status);

    std::string getDate() const;
    void setDate(std::string newDate);

    std::string getTimeIn() const;
    void setTimeIn(std::string newTimeIn);

    std::string getTimeOut() const;
    void setTimeOut(std::string newTimeOut);

    AttendanceStatus getStatus() const;
    void setStatus(AttendanceStatus newStatus);

    void setMarkAttendanceFunction(std::function<void(int, const std::string &)> function);

    void markAttendance(int employeeNumber, const std::string &entryTime);
};

#endif
