#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
  Employee(const char *name);

  virtual double calWeeklySalary() = 0;
  virtual double calHealthCareContribution() = 0;
  virtual int calVacationDay() = 0;

  void setWeeklySalary(double salary) { weeklySalary = salary; }
  void setHealCC(double CON) { healthCareContribution = CON; }
  void setVacDay(int days) { vacationDays = days; }

  void printInfo();

protected:
  const char *name;
  double weeklySalary;
  double healthCareContribution;
  int vacationDays;
};

#endif
