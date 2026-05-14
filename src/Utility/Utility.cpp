#include <iostream>
#include <limits>
#include "../../include/Utility/Utility.hpp"
using namespace std;

void Utility::WaitForEnter() {
    cout << "Press Enter to continue...";
    cin.get();
}

void Utility::ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Utility::ClearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}