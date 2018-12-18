#include <iostream>
#include <windows.h>
#include <string>
#include "library/database.cpp"

using namespace std;

int login_opt,admin_opt,staff_opt,stud_opt,auth_resp;
string adminNo,adminPin,staffNo,staffPin,studNo,studPin;
string err_msg = "Invalid input.Please enter the number assigned to your option";

int main(){
cout << "------------SCHOOL MANAGEMENT SYSTEM-------------\n\n";
start:
    cout << "Login as:\n1.Admin\n2.Staff\n3.Student\n";
    cin >> login_opt;
switch(login_opt){
case 1:
    start1:
        cout << "Enter admin number : ";
        cin >> adminNo;
        cout << "Enter pin : ";
        cin >> adminPin;
    auth_resp = auth(adminNo,adminPin);
    if(auth_resp == 1)
        system("cls");
    else
        goto start1;

    cout << "--------------------ADMINISTRATOR--------------\n\n";
    cout << "1.Add user\n2.Edit user\n3.Delete user\n4.Add courses\n5.Edit courses\n6.Log out\n";
    cin >> admin_opt;
    switch(admin_opt){
    case 1:
        cout << "User added!\n";
    break;
    case 2:
        cout << "User edited!\n";
    break;
    case 3:
        cout << "User deleted!\n";
    break;
    case 4:
        cout << "Course added!\n";
    break;
    case 5:
        cout << "Course edited!\n";
    break;
    case 6:
        system("cls");
        goto start;
    break;
    default:
        cout << err_msg << endl;
        //Implement error handling if input is not an integer
    }
break;

case 2:
    start2:
        cout << "Enter staff number : ";
        cin >> staffNo;
        cout << "Enter pin : ";
        cin >> staffPin;
    auth_resp = auth(staffNo,staffPin);
    if(auth_resp == 1)
        system("cls");
    else
        goto start2;

    cout << "------------------------STAFF---------------------\n\n";
    cout << "1.Grade student\n2.Give assignment\n3.Log out";
    cin >> staff_opt;
    switch(staff_opt){
    case 1:
        cout << "Student graded!\n";
    break;
    case 2:
        cout << "Assignment uploaded!\n";
    break;
    case 3:
        system("cls");
        goto start;
    break;
    default:
        cout << err_msg << endl;
        //Implement error handling if input is not an integer
    }

break;

case 3:
    start3:
        cout << "Enter student number : ";
        cin >> studNo;
        cout << "Enter pin : ";
        cin >> studPin;
    auth_resp = auth(studNo,studPin);
    if(auth_resp == 1)
        system("cls");
    else
        goto start3;

    cout << "-----------------------STUDENT-----------------------\n\n";
    cout << "1.Add courses\n2.Delete course\n3.View courses\n4.Academic record\n5.Log out";
    cin >> stud_opt;
    switch(stud_opt){
    case 1:
        cout << "Course added!\n";
    break;
    case 2:
        cout << "Course deleted!\n";
    break;
    case 3:
        cout << "Courses viewed!\n";
    break;
    case 4:
        cout << "Academic record\n";
    break;
    case 5:
        system("cls");
        goto start;
    break;
    default:
        cout << err_msg << endl;
        //Implement error handling if input is not an integer
    }
break;

default:
    cout << err_msg << endl;
    //Implement error handling if input is not an integer
    goto start;
    }
return 0;
}
