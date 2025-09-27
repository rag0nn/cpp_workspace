#pragma once
#include <string>
#include <vector>
using namespace std;

class DataManager{

    public:
        string path;
        vector<string> load_data();
        void save_data(vector<string> data);
        DataManager(string pth);
};