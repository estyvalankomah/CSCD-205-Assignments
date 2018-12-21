#include <iostream>
#include "library/Database.h"
#include <windows.h>
#include <string>
using namespace std;



int main(int argc, char const *argv[]) {

int choice,admin_opt,staff_opt,stud_opt;
string admin_no,admin_pin,staff_no,staff_pin,stud_no,stud_pin,assignment;
User one,user;
Course course,edit_course;
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
          cout <<"1.Add user\n2.View user\n3.Edit user\n4.Delete user\n5.Log out\n";
          cin >> admin_opt;
        switch(admin_opt){
            case 1:
                system("cls");
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
              system("pause");
              system("cls");
              goto adminPage;
            break;
            case 2:
              system("cls");
              dbase.view_users();
              system("pause");
              system("cls");
              goto adminPage;
            break;
            case 3:
              system("cls");
              cout << "Enter user number of person to edit: ";
              cin >> stud_no;
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
              if(dbase.update(stud_no,user)){
                cout << "User edited successfully .. " << endl;
              }
              system("pause");
              system("cls");
              goto adminPage;
            break;
            case 4:
              system("cls");
              cout << "Enter user number of person to delete: ";
              cin >> stud_no;
              if(dbase.delete_user(stud_no)){
                cout << "User deleted successfully" << endl;
              }
              system("pause");
              system("cls");
              goto adminPage;
            break;
            case 5:
              system("cls");
              goto start;
            break;
            default:
              cout << "Invalid input\n";
              system("pause");
              system("cls");
              goto adminPage;
      }
      }else{
        cout << "Invalid admin number or pin\n";
        system("pause");
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
          cout << "1.Grade student\n2.View student list\n3.Log out\n";
          cin >> staff_opt;

        switch(staff_opt){
          case 1:
            system("cls");  
            cout << "Enter the ID number of the student to be graded : ";
            cin >> edit_course.user_number;
            cout << "Enter the course code : ";
            cin >> edit_course.course_code;
            cout << "Enter course title : ";
            cin >> edit_course.course_title;
            cout << "Enter course credit hours : ";
            cin >> edit_course.credit;
            cout << "Enter the raw score : ";
            cin >> edit_course.raw_score;

            dbase.grade_student(edit_course);
            system("pause");
            system("cls");
            goto staffPage;

          break;
          case 2:
            system("cls");
            cout << "Enter the course code to view list of students assigned to that course : ";
            cin >> admin_no;
            if(dbase.view_student(admin_no) == 1){
              cout << "No student has registered for this course yet" << endl;
            }
            system("pause");
            system("cls");
            goto staffPage;
          break;
          case 3:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input\n";
            system("cls");
            goto staffPage;
        }
        }else{
          cout << "Invalid staff number or pin\n";
          system("pause");
          system("cls");
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
          cout << "1.Add course\n2.View course(s)\n3.Edit course(s)\n4.Delete course(s)\n5.Academic Record\n6.Log out\n";
          cin >> stud_opt;
        switch(stud_opt){
          case 1:
            system("cls");
            course.user_number = stud_no;
            cout << "Enter course code : ";
            cin >> course.course_code;
            cout << "Enter course title : ";
            cin >> course.course_title;
            cout << "Enter course credit hours : ";
            cin >> course.credit;

            //saving course to file
            dbase.create(course);
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 2:
            system("cls");
            if(dbase.view_course(stud_no) == 1){
              cout << "you have not registered for any courses yet" << endl;
            }
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 3:
            system("cls");
            cout << "Enter course code of course to edit: ";
            cin >> admin_no;
            edit_course.user_number = stud_no;
            cout << "Enter new course code : ";
            cin >> edit_course.course_code;
            cout << "Enter new course title : ";
            cin >> edit_course.course_title;
            cout << "Enter new course credit hours : ";
            cin >> edit_course.credit;
            if(dbase.update(admin_no,edit_course)){
              cout << "Course edited successfully .. " << endl;
            }
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 4:
            system("cls");
            cout << "Enter course code of course to delete: ";
            cin >> admin_no;
            if(dbase.delete_course(stud_no,admin_no)){
              cout << "Course deleted successfully" << endl;
            }
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 5:
            system("cls");
            dbase.print(stud_no);
            system("pause");
            system("cls");
            goto studPage;
          break;
          case 6:
            system("cls");
            goto start;
          break;
          default:
            cout << "Invalid input";
            system("pause");
            system("cls");
            goto studPage;
        }
        }else{
          cout << "Invalid student number or pin";
          system("pause");
          system("cls");
          goto start3;

      }
    break;
    default:
      cout << "Invalid input";
      system("pause");
      system("cls");
      goto start;
  }

  return 0;
}
