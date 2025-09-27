#pragma once
#include <string>
#include <basicModels/Book.h>
#include "DataManager.h"
#include <vector>
#include <functional>

using namespace std;

class DataManagerBook {
    public:
        const string path = "data/book.txt";
        vector<Book> data;
        void load_data();
        void save_data();
        void show();
        void addItem(Book item);
        void changeDepositable();
        Book buildBook();
        DataManagerBook();
};



