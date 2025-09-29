#pragma once
#include <string>

#include "DataManager.h"
#include <basicModels/Book.h>
#include <basicModels/User.h>
#include <basicModels/DateTime.h>
#include <vector>
#include <functional>


using namespace std;


class Transaction;  // <-- forward declaration

class DataManagerTransaction {
    public:
        const string path = "data/transaction.txt";
        vector<Transaction> data;
        void load_data();
        void save_data();
        void show();
        void addItem(Transaction item);
        Transaction buildTransaction( Book book,User user, DateTime datetime);
        DataManagerTransaction();
};



