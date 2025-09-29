#pragma once
#include <string>
using namespace std;

class DateTime {
    public:
        int year, month, day;
        int hour, min, sec;

        // Default constructor
        DateTime() : year(0), month(0), day(0), hour(0), min(0), sec(0) {}

        // Parametreli constructor
        DateTime(int y, int m, int d, int h, int mi, int s)
            : year(y), month(m), day(d), hour(h), min(mi), sec(s) {}

        // Şu anki zamanı al
        static DateTime now();
        std::string to_string();
        static DateTime from_string(const std::string& s);

        void print();
};
