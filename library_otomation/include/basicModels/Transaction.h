#pragma once
#include <string>
#include <basicModels/Book.h>
#include <basicModels/User.h>
#include <basicModels/DateTime.h>
#include <vector>
#include <utils/Tools.h> 
#include <dataManagerModels/Users.h>
#include <dataManagerModels/Books.h>

using namespace std;

class Transaction{

    public:
        Book bk;
        User usr;
        DateTime datetime;
        string to_string();
        void show();
        Transaction(User user,Book book,  DateTime datetime): bk(book), usr(user), datetime(datetime){}
        static Transaction fromString(const string& text); 

    };
