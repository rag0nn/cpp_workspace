#include <utils/Tools.h>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <functional>
#include <limits>
#include <chrono>
#include <ctime>

string get_date_string() {
    // Şimdiki zamanı al
    auto now = std::chrono::system_clock::now();

    // time_t tipine çevir
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Yerel zamana çevir
    std::tm *local_time = std::localtime(&now_time);

    string text  = to_string(1900 + local_time->tm_year) + "," + to_string(local_time->tm_mon) + "," + to_string(local_time->tm_mday);
    return text;
}

string get_time_string() {
    // Şimdiki zamanı al
    auto now = std::chrono::system_clock::now();

    // time_t tipine çevir
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Yerel zamana çevir
    std::tm *local_time = std::localtime(&now_time);

    string text  = to_string(local_time->tm_hour) + "," + to_string(local_time->tm_min) + "," + to_string(local_time->tm_sec);
    return text;
}

vector<string> split(string text,char sign){
    vector<string> parts;

    stringstream ss(text);
    string item;

    while (getline(ss, item, sign)) {
        parts.push_back(item);
    }

    return parts;
}

void Menu::addOption(const string& label, function<void()> cb) {
    labels.push_back(label);
    callbacks.push_back(cb);
}

void Menu::run() {
    while (true) {

        if (context.dataManagerUsers.isLogin) {
            std::cout << "\n--- " << title 
                    << " --- Logged: " << context.dataManagerUsers.loggedUser.get_name()
                    << ((context.dataManagerUsers.loggedUser.get_flag() == 0) ? " as User" : " as Admin")
                    << " | [" + get_date_string() + "]"
                    << "[" + get_time_string() + "]";
        } else {
            std::cout << "\n--- " << title << " --- Not logged in";
        }
        std::cout <<endl;

        for (size_t i = 0; i < labels.size(); i++) {
            cout << i << ") " << labels[i] << "\n";
        }
        cout << labels.size() << ") Back\n";
        cout << "İnput: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Geçersiz giriş!\n";
            continue;
        }
        // >>>> burada buffer temizlenmeli
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == (int)labels.size()) {
            cout << "Turning back...\n";
            break;
        }

        if (choice < 0 || choice >= (int)labels.size()) {
            cout << "Invalid choise, try again.\n";
            continue;
        }

        callbacks[choice]();
    }
}


