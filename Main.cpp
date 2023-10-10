#include "Single_Linked_List.h"
//couldn't get the code to work without this 
#include "Single_linked_list.cpp"
#include "nonprofessional.h"
#include "professional.h"
#include <iostream>

template class Single_linked_list<int>;

int main() {
  //creating the single linked list 
  Single_linked_list<int> myList;

  //pushing back the number to put in the list
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);
  myList.push_front(5);

  //Printing the size, front and back of the list 
  cout << "List size: " << myList.size() << endl;
  cout << "Front: " << myList.front() << endl;
  cout << "Back: " << myList.back() << endl;
  
  //removing the second index and adding numbers
  myList.insert(1, 4);
  myList.remove(2);

  //List size after the insert and remove fucntion have been used 
  cout << "List size after insertion and removal: " << myList.size() << endl;

  //Finding a specfic number in the list and printing if the number is in the list 
  size_t found_index = myList.find(2);
  if (found_index != myList.size()) {
    cout << "Item found at index " << found_index << endl;
  } else {
    cout << "Item not found in the list" << endl;
  }


  //2nd part
  cout << endl;
  //creating two employees and setting the values 
  ProfessionalEmployee profEmployee("Ethan", 2.90);
  NonprofessionalEmployee nonProfEmployee("Tommy", 2.90 , 401);

  //setting the values that are calulated for the Professional 
  profEmployee.setWeeklySalary(profEmployee.calWeeklySalary());
  profEmployee.setHealCC(profEmployee.calHealthCareContribution());
  profEmployee.setVacDay(profEmployee.calVacationDay());

  //setting the values that are calulated for the NON-Professional 
  nonProfEmployee.setWeeklySalary(nonProfEmployee.calWeeklySalary());
  nonProfEmployee.setHealCC(nonProfEmployee.calHealthCareContribution());
  nonProfEmployee.setVacDay(nonProfEmployee.calVacationDay());

  //printing the infomation for btih employees
  profEmployee.printInfo();
  nonProfEmployee.printInfo();
}
