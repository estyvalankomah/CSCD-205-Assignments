#include <iostream>
#include "library/Database.h"
#nclude <windows.h>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int choice,admin_opt,staff_opt,stud_opt;
  string admin_no,admin_pin,staff_no,staff_pin,stud_no,stud_pin;
  User one;
  Database dbase;
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

  cout << "--------------SCHOOL MANAGEMENT SYSTEM------------\n\n";
  start:
    cout << "Login as:\n1.Admin\n2.Staff\n3.Student\n";
    cin >> choice;

  switch(choice){
    case 1:
      start1:
        cout << "Enter admin number : ";
        cin >> admin_no;
        cout << "Enter your pin : ";
        cin >> admin_pin;
      bool  check = dbase.login(admin_no,admin_pin);

      if(check){
        //here is where the rest of the code goes
        system("cls");
        cout << "--------------------ADMIN----------------------\n\n";
        adminPage:
          cout <<"1.Add user\n2.Edit user\n3.Delete user\n4.Upload courses\n5.Edit course\n6.Log out\n";
          cin >> admin_opt;
        switch(admin_opt){
            case 1:
              create(one);
            break;
            case 2:
              update(one);
            break;
            case 3:
              delete_user(one.user_number);
            break;
            case 4:
              cout << "Course uploade!\n";
            break;
            case 5:
              cout << "Course edited!\n";
            break;
            case 6:
              system("cls");
              goto start;
            break;
            default:
              cout << "Invalid input\n";
              goto adminPage;
      }else{
        cout << "Invalid admin number or pin\n";
        system("cls");
        goto start1;
      }

      }

    break;
    case 2:
      start2:
        cout << "Enter staff number : ";
        cin >> staff_no;
        cout << "Enter your pin : ";
        cin >> staff_pin;
      bool  check = dbase.login(staff_no,staff_pin);

      if(check){
        system("cls")

        cout << "------------------------STAFF---------------------\n\n";
        staffPage:
          cout << "1.Grade student\n2.Give assignment\n3.Log out\n";
          cin >> staff_opt;

        switch(staff_opt){
          case 1:
            cout << "Student graded!\n";
          break;
          case 2:
            cout << "Assignment given!\n";
          break;
          case 3:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input\n";
            goto staffPage;
        }else{
          cout << "Invalid staff number or pin\n";
          goto start2;
        }
      }
    break;
    case 3:
      start3:
        cout << "Enter student number : ";
        cin >> stud_no;
        cout << "Enter your pin : ";
        cin >> stud_pin;
      bool  check = dbase.login(stud_no,stud_pin);

      if(check){
        system("cls");

        cout << "------------------------STUDENT---------------------";
        studPage:
          cout << "1.Add courses\n2.View courses\n3.Edit courses\n4.Delete courses\n5.Academic Record\n6.Log out";
          cin >> stud_opt;
        switch(stud_opt){
          case 1:
            cout << "Course added!\n";
          break;
          case 2:
            cout << "Courses viewed!\n";
          break;
          case 3:
            cout << "Courses edited!\n";
          break;
          case 4:
            cout << "Courses deleted!\n";
          break;
          case 5:
            cout << "Academic record\n";
          break;
          case 6:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input\n";
            goto studPage;
        }else{
          cout << "Invalid student number or pin\n";
          goto start3;
        }

      }
    break;
    default:
      cout << "Invalid input";
      goto start;
  }

  return 0;
}
