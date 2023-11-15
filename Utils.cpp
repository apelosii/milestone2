#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::getCurrYear(int* year) const{
        time_t t = std::time(NULL);
        tm lt = *localtime(&t);
        if (year) *year = lt.tm_year + 1900;
    }

    void Utils::alocpy(char*& destination, const char* source) {
        // Check if the source is not null
        if (source) {
            // Allocate memory for the destination
            size_t len = strlen(source) + 1;
            char* newDestination = new char[len];
            // Copy the source into the new memory
            strcpy(newDestination, source);
            // Deallocate the old memory (if any)
            delete[] destination;
            // Update the destination pointer to point to the new memory
            destination = newDestination;
        }
        else {
            // If source is null, set destination to null as well
            delete[] destination;
            destination = nullptr;
        }
    }

}