#pragma once
#include <string>
#include <vector>
#include <utils/Encryption.h>
using namespace std;

class User{
    private:
        string psw;
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
        string get_password();
        int get_id();
        int get_flag();

    User(
        string name,
        string surname,
        string username,
        string password,
        int id,
        int flag

    ) : name(name),
     surname(surname),
     username(username),
     id(id),
     flag(flag)
     {
        EncryptionHelper eh = EncryptionHelper();
        psw = eh.sha256(password);

     }


};