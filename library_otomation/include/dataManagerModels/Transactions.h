#pragma once
#include <string>

#include "DataManager.h"
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
        Transaction buildTransaction(DataManagerBook& dmb, DataManagerUser& dmu);
        DataManagerTransaction();
};



