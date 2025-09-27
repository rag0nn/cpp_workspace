#include "basicModels/Book.h"
#include <iostream>
using namespace std;

string Book::info() {
    string text;
    text = "Book: " + name 
         + " - " + writer 
         + " (ISBN: " + std::to_string(isbn) + ")"
         + (is_depositable ? " [Depositable]" : " [Not Depositable]");
        return text;
}

string Book::to_string(){
    string text = name + "," + writer + "," + std::to_string(isbn) + "," + std::to_string(is_depositable);
    return text;
}