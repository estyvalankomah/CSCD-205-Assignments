#ifndef DATABASE_H
#define DATABASE_H
//this is where all includes will be
#include <iostream>
#include <string>
#include <fstream>

//this is where all defined constants will be
#define FILE_NAME "file.txt"



/*
okay so this is the main database class alright,
what we are going to have create, read, edit and delete functions

*/

//this is your defined user struct
struct User{
  string user_number;
  string user_pin;
  string fname;
  string lname;
  string user_type;
};

class Database{
  fstream file;
  fstream temp_file;
public:

  //create methods
  void create(User& user){
    //lines to write to file
    file.open("users.txt",std::ios::app|std::ios::out);
    file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << endl;
    file.close();
    std::cout << "User created successfully " << std::endl;
  }

  //fetch(read) methods
  void fetch(std::string user_id,User& user){
    //lines to fetch the user from the file
    file.open("users.txt",std::ios::in);
    while(!file.eof()){
      file >> user.user_number >> user.user_pin >> user.fname >> user.lname >> user.user_type;
      if(user.user_number == user_id){
        break;
      }
    }
  }

  //update(edit) methods
  bool update(User update_user){
    User user;
    //lines to update the user in the file
    file.open("users.txt",std::ios::in|std::ios::out);
    temp_file.open("temp.txt",std::ios::in|std::ios::out);
    while(!file.eof()){
      file >> user.user_number >> user.user_pin >> user.fname >> user.lname >> user.user_type;
      if(user.user_number == update_user.user_number){
        user.user_number = upadte_user.user_number;
        user.user_pin = upadte_user.user_pin;
        user.fname = upadte_user.fname;
        user.lname = upadte_user.lname;
        user.user_type = upadte_user.user_type;
      }
      temp_file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << endl;
    }
    file.close();
    temp_file.close();
    remove("users.txt");
    if(rename("temp.txt","users.txt")){
      return true;
    }
    return false;
  }


  //delete(remove user) methods
  void delete_user(string user_id){
    //lines to delete the user
  }

  //user authentication method
  bool login(string user_id,string user_pin){
    //line to log user into his/her account
    return false;
  }

};





#endif
