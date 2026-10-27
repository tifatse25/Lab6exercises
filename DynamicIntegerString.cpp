#include <iostream>
#include <string>
#include <limits>
#include <new>
using namespace std;

int main() {
    int* dynamicInteger = new (nothrow) int;
    string* dynamicString = new (nothrow) string;

    if (dynamicInteger == nullptr ||
        dynamicString == nullptr) {
        cout << "Memory allocation failed." << endl;
        delete dynamicInteger;
        delete dynamicString;
        return 1;
    }

    cout << "Enter an integer: ";
    if (!(cin >> *dynamicInteger)) {
        cout << "Invalid integer input." << endl;
        delete dynamicInteger;
        delete dynamicString;
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a string: ";
    getline(cin, *dynamicString);

    cout << "\n--- Results ---" << endl;
    cout << "Integer: " << *dynamicInteger << endl;
    cout << "String: " << *dynamicString << endl;

    delete dynamicInteger;
    delete dynamicString;

    return 0;
}