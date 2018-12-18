#ifndef DATABASE_H
#define DATABASE_H
//this is where all includes will be
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

//this is where all defined constants will be
#define FILE_NAME "file.txt"



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

class Database{
  std::fstream file;
  std::fstream temp_file;
  User user;
public:

  //create methods (works as planned)
  void create(User& user){
    //lines to write to file
    file.open("users.txt",std::ios::app|std::ios::out);
    file << user.user_number << " " << user.user_pin << " " << user.fname << " " << user.lname << " " << user.user_type << std::endl;
    file.close();
    std::cout << "User created successfully " << std::endl;
  }

  //fetch(read) methods (works as planned)
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

  //update(edit) methods (not working at the moment) why are you cursing lol am I ? you said wtf that's cursing lol
  bool update(User update_user){
    //lines to update the user in the file
    file.open("users.txt");
    temp_file.open("temp.txt",std::ios::app|std::ios::out);
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
    remove("users.txt");
    int check = rename("temp.txt","users.txt");
    std::cout << check << std::endl;
    if(check){
      return true;
    }
    return false;
  }

  //delete(remove user) methods
  void delete_user(std::string user_id){
    //lines to delete the user
    file.open("users.txt");
    temp_file.open("temp.txt",std::ios::app|std::ios::out);
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
    remove("users.txt");
    int check = rename("temp.txt","users.txt");
    std::cout << check << std::endl;
    if(check){
      return true;
    }
    return false;
  }

  //user authentication method
  bool login(std::string user_id,std::string user_pin){
    //line to log user into his/her account
    User user;
    this->fetch(user_id,user);
    if(user.pin == user_pin){
      return true;
    }
    return false;
  }

};





#endif
