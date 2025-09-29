#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
    public:
        string name;
        string writer;
        float isbn;
        bool is_depositable;
        string to_string();
        string info();
        Book(
            string name, 
            string writer, 
            int isbn, 
            bool is_depositable): 
                name(name),
                writer(writer),
                isbn(isbn), 
                is_depositable(is_depositable) {
                    // std::cout << "Book initialized.\n";
                }
};
