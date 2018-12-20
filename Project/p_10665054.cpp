#include <iostream>
#include "library/Database.h"
#include <windows.h>
#include <string>
using namespace std;



int main(int argc, char const *argv[]) {

int choice,admin_opt,staff_opt,stud_opt;
string admin_no,admin_pin,staff_no,staff_pin,stud_no,stud_pin;
User one,user;
Course course;
bool check;
Database dbase;

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
        check = dbase.login(admin_no,admin_pin);

      if(check){
        system("cls");
        adminPage:
          cout << "--------------------ADMIN----------------------\n\n";
          cout <<"1.Add user\n2.Edit user\n3.Delete user\n4.Log out\n";
          cin >> admin_opt;
        switch(admin_opt){
            case 1:
                cout << "Enter user number : ";
                cin >> one.user_number;
                stud_no = one.user_number;
                cout << "Enter user pin : ";
                cin >> one.user_pin;
                cout << "Enter user first name : ";
                cin >> one.fname;
                cout << "Enter user last name : ";
                cin >> one.lname;
                stud_pin = one.fname + " " + one.lname ;
                cout << "Enter user type (admin/staff/student) : ";
                cin >> one.user_type;
              dbase.create(one);
              /*if(one.user_type == "student"){
                course.user_number = stud_no;
                course.user_name = stud_pin;
                cout << "Enter the academic year : ";
                cin >> course.aca_year;
                cout << "Enter the semester (first/second): ";
                cin >> course.semester;
                dbase.create(course);
              }*/
              system("cls");
              goto adminPage;
            break;
            case 2:
              cout << "Enter user number of person to edit: ";
              cin >> stud_no;
              dbase.fetch(stud_no,one);
              cout << "Enter new user number : ";
              cin >> user.user_number;
              cout << "Enter new user pin : ";
              cin >> user.user_pin;
              cout << "Enter new user first name : ";
              cin >> user.fname;
              cout << "Enter new user last name : ";
              cin >> user.lname;
              cout << "Enter new user type (admin/staff/student) : ";
              cin >> user.user_type;
              if(dbase.update(user)){
                cout << "User edited successfully .. " << endl;
              }
              system("cls");
              goto adminPage;
            break;
            case 3:
              cout << "Enter user number of person to delete: ";
              cin >> stud_no;
              if(dbase.delete_user(stud_no)){
                cout << "User deleted successfully" << endl;
              }
              system("cls");
              goto adminPage;
            break;
            case 4:
              system("cls");
              goto start;
            break;
            default:
              cout << "Invalid input\n";
              goto adminPage;
      }
      }else{
        cout << "Invalid admin number or pin\n";
        system("cls");
        goto start1;
      }

    break;
    case 2:
      start2:
        cout << "Enter staff number : ";
        cin >> staff_no;
        cout << "Enter your pin : ";
        cin >> staff_pin;
        check = dbase.login(staff_no,staff_pin);
      if(check){
        system("cls");
        staffPage:
          cout << "------------------------STAFF---------------------\n\n";
          cout << "1.Grade student\n2.Give assignment\n3.Log out\n";
          cin >> staff_opt;

        switch(staff_opt){
          case 1:
            system("cls");
            cout << "Enter the ID number of the student to be graded : ";
            cin >> stud_no;
            cout << "Enter the course code : ";
            cin >> stud_pin;
            cout << "Enter the raw score : ";
            cin >> stud_opt;

            dbase.grade_student(stud_opt,stud_pin,stud_no);
            system("cls");
            goto staffPage;

          break;
          case 2:
            cout << "Enter course code : ";
            cin >> admin_no;
            cout << "Enter assignment : ";
            getline(cin,admin_pin);
            dbase.give_assignment(admin_no,admin_pin);
            system("cls");
            goto staffPage;

          break;
          case 3:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input\n";
            goto staffPage;
        }
        }else{
          cout << "Invalid staff number or pin\n";
          goto start2;
      }
    break;
    case 3:
      start3:
        cout << "Enter student number : ";
        cin >> stud_no;
        cout << "Enter your pin : ";
        cin >> stud_pin;
        check = dbase.login(stud_no,stud_pin);

      if(check){
        system("cls");
        studPage:
          cout << "------------------------STUDENT---------------------\n\n";
          cout << "1.Add courses\n2.View courses\n3.Edit courses\n4.Delete courses\n5.Academic Record\n6.Log out\n";
          cin >> stud_opt;
        switch(stud_opt){
          case 1:
            course.user_number = stud_no;
            cout << "Enter course code : ";
            cin >> course.course_code;
            cout << "Enter course title : ";
            cin >> course.course_title;
            cout << "Enter course credit hours : ";
            cin >> course.credit;

            //saving course to file
            dbase.add(course);
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 2:
            if(dbase.view(stud_no) == 1){
              cout << "you have not registered for any courses yet" << endl;
            }
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 3:
            cout << "Courses edited!\n";
            system("cls");
            goto studPage;
          break;
          case 4:
            cout << "Courses deleted!\n";
            system("cls");
            goto studPage;
          break;
          case 5:
            cout << "Academic record\n";
            system("cls");
            goto studPage;
          break;
          case 6:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input\n";
            goto studPage;
        }
        }else{
          cout << "Invalid student number or pin\n";
          goto start3;

      }
    break;
    default:
      cout << "Invalid input";
      goto start;
  }

  return 0;
}
