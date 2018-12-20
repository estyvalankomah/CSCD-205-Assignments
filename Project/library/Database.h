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
  std::string course_code;
  std::string course_title;
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

  void fetch(std::string course_code,Course& update_course){
    update_course.file_name = "files/studentfiles/" + update_course.user_number + ".txt";
    file.open(update_course.file_name.c_str(),std::ios::in);
    while(!file.eof()){
      file >> course.course_code >> course.course_title >> course.credit >> course.grade >> course.gradept;
      if(course.course_code == course_code){
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

   bool update(Course update_course){
    update_course.file_name = "files/studentfiles/" + course.user_number + ".txt";
    //lines to update the course in the file
    file.open(update_course.file_name.c_str());
    temp_file.open("files/studentfiles/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> course.course_code >> course.course_title >> course.credit;
      // std::cout << "Fetched : " << user.user_number << " With id : " << user.user_number << std::endl;
      if(course.course_code == update_course.course_code){
        course.course_code = update_course.course_code;
        course.course_title = update_course.course_title;
        course.credit = update_course.credit;
      }
      temp_file << course.course_code << " " << course.course_title  << " " << course.credit << " " << course.grade << " " << course.gradept << std::endl;
    }
    file.close();
    temp_file.close();
    remove(update_course.file_name.c_str());
    rename("files/studentfiles/temp.txt",update_course.file_name.c_str());
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
    return true;
  }

  bool delete_course(std::string user_ID,std::string course_code){
    //lines to delete the course
    std::string id = "files/studentfiles/" + user_ID + ".txt";
    file.open(id);
    temp_file.open("files/studentfiles/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> course.course_code >> course.course_title >> course.credit >> course.grade >> course.gradept;
      // std::cout << "Fetched : " << user.user_number << " With id : " << user.user_number << std::endl;
      if(course.course_code == course_code){
        //if it passes for the test it will skip the rest if the lines in the loop
        //hence not writing the user we want to delete to the file
        continue;
      }
      temp_file << course.course_code << " " << course.course_title << " " << course.credit << " " << course.grade << " " << course.gradept << std::endl;
    }
    file.close();
    temp_file.close();
    remove(id.c_str());
    rename("files/studentfiles/temp.txt",id.c_str());
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

  void grade_student(Course& update_course){
    //this->fetch(update_course.course_code,update_course);
    update_course.file_name = "files/studentfiles/" + update_course.user_number + ".txt";
    file.open(update_course.file_name.c_str());
    temp_file.open("files/studentfiles/temp.txt",std::ios::app|std::ios::out);
    while(!file.eof()){
      file >> course.course_code >> course.raw_score >> course.grade >> course.gradept;
      if(course.course_code == update_course.course_code){
        course.raw_score = update_course.raw_score;
        if(course.raw_score >= 80 && course.raw_score <=100){
          course.grade = "A";
          course.gradept = "12";
          }
        else if(course.raw_score >=70 && course.raw_score <=79){
          course.grade = "B";
          course.gradept = "10.5";
          }
        else if(course.raw_score >=60 && course.raw_score <=69){
          course.grade = "C";
          course.gradept = "7.5";
          }
        else if(course.raw_score >=50 && course.raw_score <=59){
          course.grade = "D";
          course.gradept = "3";
         } 
        else if(course.raw_score >=40 && course.raw_score <=49){
          course.grade = "E";
          course.gradept = "2.5";
         } 
        else if(course.raw_score >=0 && course.raw_score <=39){
          course.grade = "F";
          course.gradept = "1";
        }
      }    
      temp_file << course.course_code << " " << course.course_title  << " " << course.credit << " " << course.grade << " " << course.gradept << std::endl;
    }
    file.close();
    temp_file.close();
    remove(course.file_name.c_str());
    rename("files/stuentfiles/temp.txt",course.file_name.c_str());
    std::cout << "Student has been graded successfully .." << std::endl;
  }

  void give_assignment(std::string course_code,std::string assignment){
    file.open("files/assignment.txt",std::ios::app|std::ios::out);
    file << course_code << " " << assignment << std::endl;
    file.close();
    std::cout << "Assignment uploaded!" << std::endl;
  }

  void print(std::string user_id){
    std::string filename = "files/studentfiles/" + user_id + ".txt";
    file.open(filename,std::ios::in);
    while(!file.eof()){
      getline(file,filename);
      //pardon me I am feeling lazy to create a new variable so I am killing it all here
      std::cout << filename << std::endl;
    }
  }

};



#endif
