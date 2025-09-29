#include <string>
#include <vector>
#include <basicModels/User.h>
#include <iostream>
using namespace std;


void User::changeName(){
    string new_;
    cout << "\n New name: "; cin >> new_;
    name = new_;
    cout << "\n Name successfully changed!";
}
void User::changeSurname(){
    string new_;
    cout << "\n New surname: "; cin >> new_;
    name = new_;
    cout << "\n Surname successfully changed!"; 
}
void User::changePassword(){
    string old, new_, new_2;
    cout << "\nCurrent Password: "; cin >> old;
    cout << "\nNew Password: "; cin >> new_;
    cout << "\nNew Password Again: "; cin >> new_2;
    if (new_ != new_2){
        cout << "\nNew Passwords not same";
        return;
    }
    if (old != psw){
        cout << "\n current password is wrong";
        return;
    }else{
        psw = new_;
        cout << "\n Password successfully changed!";
    }
}
string User::to_string(){
    string text = std::to_string(id) + ", "+
                    username + "," +
                    name + "," +
                    surname + "," +
                    psw + "," +
                    std::to_string(flag);
    return text;
}
string User::info(){
    return username + " | " + std::to_string(flag);
}
string User::get_username(){
    return username;
}
string User::get_name(){
    return name;
}
string User::get_surname(){
    return surname;
}
string User::get_password(){
    return psw;
}
int User::get_id(){
    return id;
}
int User::get_flag(){
    return flag;
}
