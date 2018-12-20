#ifndef DATABASE_H
#define DATABASE_H
//this is where all includes will be
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
/*
okay so this is the main database class alright,
what we are going to have create, read, edit and delete functions

*/

//this is your defined user struct
struct User{
  std::string user_number;
  std::string user_pin;
  std::string fname;
  std::string lname;
  std::string user_type;
};

struct Course{
  std::string user_number;
  std::string user_name;
  std::string course_code;
  std::string course_title;
  std::string aca_year;
  std::string semester;
  std::string file_name;
  int raw_score = 0;
  int credit;
  std::string grade = "N/A";
  std::string gradept = "N/A";
};

class Database{
  std::fstream file;
  std::fstream temp_file;
  User user;
  Course course;
public:

  //create methods (works as planned)
  void create(User& user){
    //lines to write to file
    file.open("files/users.txt",std::ios::app|std::ios::out);
    file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << std::endl;
    file.close();
    std::cout << "User created successfully " << std::endl;
  }

  void add(Course& course){
    //lines to save the course
    course.file_name = "files/studentfiles/" + course.user_number + ".txt";
    file.open(course.file_name.c_str(),std::ios::app|std::ios::out);
    //std::cout << course.user_number << " " << course.user_name << " " << course.aca_year << " " << course.semester << std::endl;
    file << course.user_number << " " << course.user_name << " " << course.aca_year << " " << course.semester << std::endl;
    file.close();
  }


  //nice implementation here //good work done 
  void create(Course& course){
    course.file_name = "files/studentfiles/" + course.user_number + ".txt";
    file.open(course.file_name.c_str(),std::ios::app|std::ios::out);
    //std::cout << course.course_code << " " << course.course_title  << " " << course.credit << " " << course.grade << " " << course.gradept << std::endl;
    file << course.course_code << " " << course.course_title  << " " << course.credit << " " << course.grade << " " << course.gradept << std::endl;
    file.close();
    std::cout << "Course created successfully .." << std::endl;
  }

  //okay so view courses works fine
  int view(std::string user_id){
    std::string filename = "files/studentfiles/" + user_id + ".txt";
    file.open(filename,std::ios::in);
    if(!file.is_open()){
      return 1;
    }
    while(!file.eof()){
      getline(file,filename);
      //pardon me I am feeling lazy to create a new variable so I am killing it all here
      std::cout << filename << std::endl;
    }
  }

  //fetch(read) methods (works as planned)
  void fetch(std::string user_id,User& user){
    //lines to fetch the user from the file
    file.open("files/users.txt",std::ios::in);
    while(!file.eof()){
      file >> user.user_number >> user.user_pin >> user.fname >> user.lname >> user.user_type;
      if(user.user_number == user_id){
        break;
      }
    }
    file.close();
  }

  void fetch(std::string user_id,std::string course_code,Course& course){
    file.open("files/courses.txt",std::ios::in);
    while(!file.eof()){
      file >> course.user_number >> course.course_code >> course.course_title >> course.raw_score >> course.grade;
      if(course.user_number == user_id && course.course_code == course_code){
        break;
      }
    }
    file.close();
  }

  //update(edit) methods (not working at the moment) why are you cursing lol am I ? you said wtf that's cursing lol
  bool update(User update_user){
    //lines to update the user in the file
    file.open("files/users.txt");
    temp_file.open("files/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> user.user_number >> user.user_pin >> user.fname >> user.lname >> user.user_type;
      // std::cout << "Fetched : " << user.user_number << " With id : " << user.user_number << std::endl;
      if(user.user_number == update_user.user_number){
        user.user_number = update_user.user_number;
        user.user_pin = update_user.user_pin;
        user.fname = update_user.fname;
        user.lname = update_user.lname;
        user.user_type = update_user.user_type;
      }
      temp_file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << std::endl;
    }
    file.close();
    temp_file.close();
    remove("files/users.txt");
    rename("files/temp.txt","files/users.txt");
    //std::cout << check << std::endl;
    /*if(check){
      return true;
    }*/
    return true;
  }

  //delete(remove user) methods
  bool delete_user(std::string user_id){
    //lines to delete the user
    file.open("files/users.txt");
    temp_file.open("files/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> user.user_number >> user.user_pin >> user.fname >> user.lname >> user.user_type;
      // std::cout << "Fetched : " << user.user_number << " With id : " << user.user_number << std::endl;
      if(user.user_number == user_id){
        //if it passes for the test it will skip the rest if the lines in the loop
        //hence not writing the user we want to delete to the file
        continue;
      }
      temp_file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << std::endl;
    }
    file.close();
    temp_file.close();
    remove("files/users.txt");
    rename("files/temp.txt","files/users.txt");
    //std::cout << check << std::endl;
    /*if(check){
      return true;
    }*/
    return true;
  }

  //user authentication method
  bool login(std::string user_id,std::string user_pin){
    //line to log user into his/her account
    User user;
    this->fetch(user_id,user);
    if(user.user_pin == user_pin){
      return true;
    }
    return false;
  }

  void grade_student(int score, std::string course_code, std::string user_id){
    Course course;
    this->fetch(user_id,course_code,course);
    file.open("files/courses.txt");
    temp_file.open("files/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> course.user_number >> course.course_code >> course.raw_score >> course.grade;
      if(course.user_number == user_id && course.course_code == course_code){
        course.raw_score = score;
      }
      temp_file << course.user_number << " " << course.course_code << " " << course.raw_score << " " << course.grade << std::endl;
    }
    remove("files/courses.txt");
    rename("files/temp.txt","courses.txt");
    std::cout << "Student has been graded successfully .." << std::endl;
  }

  void give_assignment(std::string course_code,std::string assignment){
    file.open("files/assignment.txt",std::ios::app|std::ios::out);
    file << course_code << " " << assignment << std::endl;
    file.close();
    std::cout << "Assignment uploaded!" << std::endl;
  }

};



#endif
