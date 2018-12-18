#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

struct user{
string user_number;
string user_pin;
string fname;
string lname;
string user_type;
};

int auth(string a,string b){
bool found = false, found1 = false;
string id = "10665054", pin = "29677";
string userID[120],userPin[120];

if(a == id && b == pin)
    cout << "Login successful!\n";

else if((a == id && b != pin) || (a != id && b == pin)){
    cout << "Invalid user id or pin\n";
    return -1;
}

else{
    for(int i=0;i<120;i++){
        if(a == userID[i])
            found = true;
    }

    for(int j=0;j<120;j++){
        if(b == userPin[j])
            found1 = true;
    }

    if(found && found1){
        cout << "Login successful!\n";
        return 1;
    }

    else if((found == true && found1 == false) || (found == false && found1 == true)){
        cout << "Invalid user number or pin\n\n";
        return -2;
    }
    else{
        cout << "Invalid user number and pin. Please enter a valid user number and pin\n";
        return -3;
    }
}
}

class database{
struct user;

public:
    void add();
    void edit();
    void Delete();
};
