#include <basicModels/DateTime.h>
#include <sstream>
#include <iostream>
#include <functional>
#include <limits>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>


DateTime DateTime::now() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *local_time = std::localtime(&now_time);

    return DateTime(
        1900 + local_time->tm_year,
        1 + local_time->tm_mon,
        local_time->tm_mday,
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec
    );
}
string DateTime::to_string() {
    return std::to_string(year) + "," + std::to_string(month) + "," + std::to_string(day) + ","
        + std::to_string(hour) + "," + std::to_string(min) + "," + std::to_string(sec);
}
DateTime DateTime::from_string(const std::string& s) {
    std::stringstream ss(s);
    std::string item;
    std::vector<int> parts;

    while (std::getline(ss, item, ',')) {
        parts.push_back(std::stoi(item));
    }

    if (parts.size() == 6) {
        return DateTime(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
    }
    return DateTime();
}
void DateTime::print() {
    std::cout << year << "-" << month << "-" << day
            << " " << hour << ":" << min << ":" << sec << std::endl;
}

