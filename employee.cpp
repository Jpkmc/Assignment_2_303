#include "employee.h"

// creating the class and setting the standard values to 0
Employee::Employee(const char *name)
    : name(name), weeklySalary(0), healthCareContribution(0), vacationDays(0) {}

// allowing the user to print the infomation of the professional and non
// professional
void Employee::printInfo() {
  cout << "Name: " << name << endl;
  cout << "Weekly Salary: $" << weeklySalary << endl;
  cout << "Health Care Contributions: $" << healthCareContribution << endl;
  cout << "Vacation Days Earned: " << vacationDays;
  cout << endl << endl;
}
