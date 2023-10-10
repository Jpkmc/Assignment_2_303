#ifndef PROFESSIONAL_EMPLOYEE_H
#define PROFESSIONAL_EMPLOYEE_H

#include "employee.h"

class ProfessionalEmployee : public Employee {
public:
  ProfessionalEmployee(const char* name, double monthlySalary);

  double calWeeklySalary() override;
  double calHealthCareContribution() override;
  int calVacationDay() override;

private:
  double monthlySalary;
};

#endif 
