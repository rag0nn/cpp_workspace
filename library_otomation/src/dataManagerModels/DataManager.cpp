#include <iostream>
#include <string>
#include <dataManagerModels/DataManager.h>
#include <fstream>
#include <sstream>
using namespace std;

DataManager::DataManager(string pth){
    path = pth;
};

vector<string> DataManager::load_data(){
    ifstream file(path);
    vector<string> data;

    try{
        
        if (!file.is_open()) {
            string cerr = "Error: Cannot open file: [" + path + "] \n";
            throw cerr;
        }

        string row;
        while (getline(file, row)) {   // satır satır oku
            data.push_back(row);
        }
        file.close();
        // cout << "Data Loaded" << endl;

    }
    catch(string err){
        cout << err;
    }


    if (!data.empty()) {
        // cout << data[0];
        // if (data.size() > 1) cout << " " << data[1];
    }else{
        // cout << "data null "<< endl;
    }
    return data;
};

void DataManager::save_data(vector<string> data){
    ofstream file(path);

    try{
        if (!file.is_open()) {
            string cerr = "Error: Cannot open file: [" + path + "] \n";
            throw cerr;
        }

        for (string i: data){
            file << i << "\n";
        }
        file.close();
        cout << "Data Saved" << endl;
    }
    catch(string err){
        cout << err;
    }


};

