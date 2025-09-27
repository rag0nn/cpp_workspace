#pragma once
#include <string>
#include <vector>
#include <functional>
#include <dataManagerModels/Books.h>
#include <dataManagerModels/Users.h>
using namespace std;

vector<string> split(string text,char sign);

class Context{
    public:
        DataManagerBook& dataManagerBooks;
        DataManagerUser& dataManagerUsers;
    
    Context(DataManagerBook& dataManagerBook, DataManagerUser& dataManagerUser): dataManagerBooks(dataManagerBook), dataManagerUsers(dataManagerUser) {}
};

class Menu{
    public:
        vector<string> labels;
        vector<function<void()>> callbacks;
        Context &context;
        string title;

        void addOption(const string& label, function<void()> cb);
        void run();
        Menu(Context &cntxt,string title): context(cntxt), title(title){};
};

string get_date_string();
string get_time_string();