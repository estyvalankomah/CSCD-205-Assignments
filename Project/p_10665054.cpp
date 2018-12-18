#include <iostream>
#include "library/Database.h"
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  User one;
  cout << "Enter your ID number : ";
  cin >> one.user_number;
  cout << "Enter your pin : ";
  cin >> one.user_pin;
  cout << "Enter your first name : ";
  cin >> one.fname;
  cout << "Enter your last name : ";
  cin >> one.lname;
  cout << "Enter user type (admin/staff/student) : ";
  cin >> one.user_type;

  return 0;
}
