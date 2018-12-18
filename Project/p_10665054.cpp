#include <iostream>
#include "library\Database.h"
#include <string>
using namespace std;

User one;
//Can you here the voice? no
//okay so lets do some fetching from the database with a particular id okay
//are you  I'm here yes yeah yes start all over
//okay so it worked as planned yeah whtever lol
int main(int argc, char const *argv[]) {
  Database database;
  string id = "1111";
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
  // database.create(one);//Esther fill the form
  if(database.update(one)){
      cout << " User was updated successfully" << endl;
  }
  return 0;
}
