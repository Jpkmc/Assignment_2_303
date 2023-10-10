#include "nonprofessional.h"

//creating and setting values for nonprofessional 
NonprofessionalEmployee::NonprofessionalEmployee(const char* name,
                                                 double hourlyRate,
                                                 int hoursWorked)
    : Employee(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}


//calulated the weekly salary for the nonprofessional 
double NonprofessionalEmployee::calWeeklySalary() {
  return (hourlyRate * hoursWorked) / 4;
}
//calulated how much health care the nonprofessional gets 
double NonprofessionalEmployee::calHealthCareContribution() {
  return (10 * hoursWorked);
}
//calulated how many vaction days for the nonprofessional 
int NonprofessionalEmployee::calVacationDay() {
  vacationDays = hoursWorked/40;
  return vacationDays;
}
