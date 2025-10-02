#include "basicModels/Transaction.h"
#include <basicModels/DateTime.h>
#include <iostream>
using namespace std;

string Transaction::to_string(){
    string text = usr.to_string() + "," 
                + bk.to_string() + "," 
                + datetime.to_string();
    return text;
}
Transaction Transaction::fromString(const string& text) {
    vector<string> parts = split(text, ',');

    User _user(
        parts.at(2),   
        parts.at(3),  
        parts.at(1),   
        parts.at(4), 
        stoi(parts.at(0)),
        stoi(parts.at(5))  
    );

    Book _book(
        parts.at(6),           
        parts.at(7),         
        stoi(parts.at(8)),     
        (parts.at(9) == "1")    
    );

    DateTime _dtm(
        stoi(parts.at(10)), 
        stoi(parts.at(11)), 
        stoi(parts.at(12)),  
        stoi(parts.at(13)),  
        stoi(parts.at(14)),  
        stoi(parts.at(15))   
    );

    return Transaction(_user, _book, _dtm);
}

string Transaction::show(){
    string _text = usr.info() +" " + bk.info() + " " +datetime.to_string();
    cout << _text << endl;
    return _text;
}