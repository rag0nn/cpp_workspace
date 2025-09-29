#include <iostream>
#include <string>
#include <basicModels/Book.h>
#include <dataManagerModels/DataManager.h>
#include <dataManagerModels/Books.h>
#include <utils/Tools.h>
#include <fstream>
#include <sstream>
using namespace std;

DataManagerBook::DataManagerBook(){
    load_data();
}
void DataManagerBook::load_data(){
    DataManager dataManager =  DataManager(path);
    vector<string> stringData =  dataManager.load_data();
    // cout << "size: "<<stringData.size() <<endl;
    for (string item : stringData) {

        // cout << "\nit: " << item;
        vector<string> parts = split(item,',');
        // cout << "\nlen: " << parts.size();
        // cout << "\nparts: " << parts.at(0)<< " " << parts.at(1)<< " " << std::stoi(parts.at(2))<< " " << (stoi(parts.at(3)) == 1) <<endl;
        
        Book book = Book(parts.at(0),parts.at(1),stod(parts.at(2)),stoi(parts.at(3)) == 1);
        // cout << "t1\n";
        data.push_back(book);
        // cout << "t2\n";
    };
};

void DataManagerBook::save_data(){
    DataManager dataManager =  DataManager(path);
    vector<string> text;
    for (Book book: data){
        text.push_back(book.to_string());
    }
    dataManager.save_data(text);
};

void DataManagerBook::show(){
    cout << "\n[[Current Book List]] "<<endl;
    for (Book i: data){
        string info = i.info();
        cout << info << endl;
    }
}

void DataManagerBook::addItem(Book item){
    data.push_back(item);
    cout << "Added item" << endl;
    save_data();
}

Book DataManagerBook::buildBook(){
    string name, writer, isbnStr;
    int isbn;

    cout << "\n Name: ";getline(cin, name);

    cout << "\n Writer: ";getline(cin, writer);

    while (true) {
        cout << "\nISBN: ";
        getline(cin, isbnStr);

        try {
            isbn = stoi(isbnStr);
            break; // geçerli sayı
        } catch (std::invalid_argument &e) {
            cout << "Lütfen geçerli bir sayı girin!\n";
        } catch (std::out_of_range &e) {
            cout << "Girilen sayı çok büyük! Tekrar deneyin.\n";
        }
    }

    Book newBook = Book(name,writer,isbn,true);
    return newBook;
}

void DataManagerBook::changeDepositable(){
    int idx = 0;
    for (Book bk: data){
        cout << "[" +std::to_string(idx) + "]" + bk.info() + "\n";
        idx+=1;
    };
    cout << "Input: "; cin >> idx;

    if(idx < 0 || idx > data.size()-1){
        cout << "\n Wrong Index Input!"<<endl;
        return;
    }

    data[idx].is_depositable = !data[idx].is_depositable;
    cout << "\n Book Deposit Changed Successfully!";
    save_data();
}

Book DataManagerBook::selectBook(){
    int idx = 0;
    for (Book bk: data){
        cout << "[" +std::to_string(idx) + "]" + bk.info() + "\n";
        idx+=1;
    };

    while (true){
        cout << "Input: "; cin >> idx;

        if(idx < 0 || idx > data.size()-1){
            cout << "\n Wrong Index Input!"<<endl;
            continue;;
        }
        else {
            data[idx].is_depositable = !data[idx].is_depositable;
            save_data();            
            return data[idx];
        }
    }

}

