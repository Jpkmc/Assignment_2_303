#include "professional.h"

//setting the varaibles and the class
ProfessionalEmployee::ProfessionalEmployee(const char *name,
                                           double monthlySalary)
    : Employee(name), monthlySalary(monthlySalary) {}

//calulated the weekly salary for the professional 
double ProfessionalEmployee::calWeeklySalary() { return monthlySalary / 4; }
//calulated how much the health care they get 
double ProfessionalEmployee::calHealthCareContribution() {
  return monthlySalary - 100;
}
//calulated the vaction days 
int ProfessionalEmployee::calVacationDay() { return 10; }
