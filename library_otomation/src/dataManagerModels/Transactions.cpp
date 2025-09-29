#include <iostream>
#include <string>
#include <basicModels/Transaction.h>
#include <basicModels/Book.h>
#include <basicModels/User.h>
#include <basicModels/DateTime.h>
#include <dataManagerModels/DataManager.h>
#include <dataManagerModels/Transactions.h>

#include <utils/Tools.h>
#include <fstream>
#include <sstream>
using namespace std;

DataManagerTransaction::DataManagerTransaction(){
    load_data();
}
void DataManagerTransaction::load_data(){
    DataManager dataManager =  DataManager(path);
    vector<string> stringData =  dataManager.load_data();
    for (string item : stringData) {
        Transaction trs = Transaction::fromString(item);
        data.push_back(trs);
    };
};

void DataManagerTransaction::save_data(){
    DataManager dataManager =  DataManager(path);
    vector<string> text;
    for (Transaction trs: data){
        text.push_back(trs.to_string());
    }
    dataManager.save_data(text);
};

void DataManagerTransaction::show(){
    cout << "\n[[Current Transaction List]] "<<endl;
    for (Transaction i: data){
        i.show();
    }
}

void DataManagerTransaction::addItem(Transaction trs){
    data.push_back(trs);
    cout << "Added item" << endl;
    save_data();
}

Transaction DataManagerTransaction::buildTransaction(DataManagerBook& dmb, DataManagerUser& dmu){
    Book selectedBook = dmb.selectBook();
    User selectedUser = dmu.loggedUser;
    DateTime datetime = DateTime::now();
    Transaction trs = Transaction(selectedUser, selectedBook, datetime);
    return trs; 
}


