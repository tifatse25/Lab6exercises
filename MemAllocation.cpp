#include <iostream>
#include <new>
using namespace std;

int main() {
    int numberOfElements = 0;
    int* dynamicArray = nullptr;

    cout << "How many numbers would you like to type? ";
    if (!(cin >> numberOfElements) || numberOfElements <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    dynamicArray = new (nothrow) int[numberOfElements];

    if (dynamicArray == nullptr) {
        cout << "Error: memory could not be allocated."
             << endl;
        return 1;
    }

    for (int i = 0; i < numberOfElements; i++) {
        cout << "Enter number: ";
        cin >> dynamicArray[i];
    }

    cout << "You have entered: ";

    for (int j = 0; j < numberOfElements; j++) {
        cout << dynamicArray[j] << ", ";
    }

    cout << endl;

    delete[] dynamicArray;
    dynamicArray = nullptr;

    return 0;
}