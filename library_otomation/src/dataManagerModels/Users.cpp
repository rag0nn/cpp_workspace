#include <iostream>
#include <string>
#include <basicModels/User.h>
#include <dataManagerModels/DataManager.h>
#include <dataManagerModels/Users.h>
#include <utils/Tools.h>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;


DataManagerUser::DataManagerUser(){
    load_data();
}
void DataManagerUser::load_data(){
    DataManager dataManager =  DataManager(path);
        vector<string> stringData =  dataManager.load_data();

        for (string item : stringData) {
            vector<string> parts = split(item,',');
            User book = User(parts.at(2),parts.at(3),parts.at(1),parts.at(4),stoi(parts.at(0)),stoi(parts.at(5)));
            data.push_back(book);

        };

    
}
void DataManagerUser::save_data(){
    DataManager dataManager =  DataManager(path);
    vector<string> text;
    for (User user: data){
        text.push_back(user.to_string());
    }
    dataManager.save_data(text);
}
void DataManagerUser::addItem(User item){
    data.push_back(item);
    cout << "Added item" << endl;
    save_data();
}
User DataManagerUser::buildUser(int flag){
    string name, surname, username, pswString;
    int password, id ,_flag;
    cout << "\n Name: "; getline(cin, name);
    cout << "\n Surname: "; getline(cin, surname);
    cout << "\n Username: ";getline(cin, username);
    cout << "\n Password: "; getline(cin, pswString);
    id = 1;
    _flag = flag;
    User newUser = User(name,surname,username,pswString,id,_flag);
    return newUser;
}
bool DataManagerUser::login(User usr,bool alreadyLoginCheck){
    auto _login = [&]() {
        for (User i: data){
            if (i.get_username() == usr.get_username() && i. get_password() == usr.get_password() && i.get_flag() == usr.get_flag()){
                cout << "\n User successfully logged in";
 
                loggedUser = i;
                isLogin = true;
                return true;
            }
        }

        cout << "\n Account not found!";
        return false;
    };

    if (!isLogin){
        bool success = _login();
        return success;
    }
    else {
        bool dec;
        if(alreadyLoginCheck){
            cout << "One user account as active, do you want to exit? /1 or 0: "; cin >> dec;
            if(dec){
                bool success = _login();
                return success;
            }
            else{
                return false;
            }
        }else{
            bool success = _login();
            return success;
        }

    }   
}
