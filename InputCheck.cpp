#include "InputCheck.h"

int getIntValue(int lowLimit, int upLimit)
{
    while (true) {
        int a;
        std::cin >> a;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oopsie, that input is invalid.  Please try again.\n";
        }
        else if (a < lowLimit || a > upLimit) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Entered number is not from the list. Please try again." << endl;
        }
        else {
            std::cin.ignore(32767, '\n'); // deleting excess symbols
            return a;
        }
    }
}

string getStringValue()
{
    string line;
    while (true) {
        getline(cin, line);
        if (std::cin.fail()) {              //if the previous extraction failed,
            std::cin.clear();               //then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767, '\n');   //and remove the values of the previous input from the input buffer
            std::cout << "Oopsie, that input is invalid.  Please try again.\n";
        }
        else if (isInvalidInput(line))      //Non-latin symbol or not a number entered
            cout << "Enter latin letters or numbers only. Please try again.\n";
        else {
            return line;
        }
    }
}

bool isInvalidInput(string line) {
    for (const auto& ch : line)
        if (((int)ch < 0) || ((int)ch < 97 && (int)ch > 122) || ((int)ch < 65 && (int)ch > 90) || ((int)ch < 48 && (int)ch > 57)) {
            return true;
        }
    return false;
}

double getDoubleValue(double lowLimit, double upLimit) {
    while (true) {
        double a;
        std::cin >> a;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oopsie, that input is invalid.  Please try again.\n";
        }
        else if (a < lowLimit || a > upLimit) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Entered number is not from the list. Please try again." << endl;
        }
        else {
            std::cin.ignore(32767, '\n'); // deleting excess symbols
            return a;
        }
    }
}