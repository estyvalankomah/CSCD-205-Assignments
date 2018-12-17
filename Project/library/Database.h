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

public:

  //create methods
  void create(User& user){
    //lines to write to file
  }

  //fetch(read) methods
  User& fetch(string user_id){
    //lines to fetch the user from the file
    return user;
  }

  //update(edit) methods
  bool update(User& user){
    //lines to update the user in the file
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
