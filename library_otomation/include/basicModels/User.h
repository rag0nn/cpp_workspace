#pragma once
#include <string>
#include <vector>
using namespace std;

class User{
    private:
        int password;
        int id;
        int flag;
        string name;
        string surname;
        string username;

    public:
        void changeName();
        void changeSurname();
        void changePassword();
        string to_string();
        string info();
        string get_username();
        string get_name();
        string get_surname();
        int get_password();
        int get_id();
        int get_flag();

    User(
        string name,
        string surname,
        string username,
        int password,
        int id,
        int flag

    ) : name(name),
     surname(surname),
     username(username),
     password(password),
     id(id),
     flag(flag)
     {}


};