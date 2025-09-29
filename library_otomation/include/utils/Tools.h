#pragma once
#include <string>
#include <vector>
#include <functional>
#include <dataManagerModels/Books.h>
#include <dataManagerModels/Users.h>
#include <dataManagerModels/Transactions.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

vector<string> split(string text,char sign);

class Context{
    public:
        DataManagerBook& dataManagerBooks;
        DataManagerUser& dataManagerUsers;
        DataManagerTransaction& dataManagerTransaction;
    
    Context(DataManagerBook& dataManagerBook, 
        DataManagerUser& dataManagerUser, 
        DataManagerTransaction& dataManagerTransaction): 
        dataManagerBooks(dataManagerBook), dataManagerUsers(dataManagerUser), dataManagerTransaction(dataManagerTransaction)
        {}
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



