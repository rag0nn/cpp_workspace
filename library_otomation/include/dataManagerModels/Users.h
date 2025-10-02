#pragma once
#include <string>
#include <basicModels/User.h>
#include "DataManager.h"
#include <vector>
#include <functional>

using namespace std;

class DataManagerUser {
    public:
        User loggedUser = User("","","","",0,0);   
        bool isLogin = false;
        const string path = "data/user.txt";
        vector<User> data;
        void load_data();
        void save_data();
        void show();
        void addItem(User item);
        User buildUser(int flag = 0);
        bool login(User usr,bool alreadyLoginCheck = true);
        DataManagerUser();
};