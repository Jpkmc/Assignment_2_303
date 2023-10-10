#ifndef NONPROFESSIONAL_EMPLOYEE_H
#define NONPROFESSIONAL_EMPLOYEE_H

#include "employee.h"

class NonprofessionalEmployee : public Employee {
public:
  NonprofessionalEmployee(const char* name, double hourlyRate, int hoursWorked);

  double calWeeklySalary() override;
  double calHealthCareContribution() override;
  int calVacationDay() override;

private:
  double hourlyRate;
  int hoursWorked;
};

#endif
