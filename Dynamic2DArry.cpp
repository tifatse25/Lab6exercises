#include <iostream>
#include <limits>
#include <new>
using namespace std;

int main() {
    int rows = 0;
    int columns = 0;

    // Accept dimensions from 1 to 3
    while (true) {
        cout << "Enter rows and columns (1 to 3 each): ";

        if (cin >> rows >> columns &&
            rows >= 1 && rows <= 3 &&
            columns >= 1 && columns <= 3) {
            break;
        }

        cout << "Invalid dimensions. Enter two integers "
             << "between 1 and 3." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Dynamically allocate an array of row pointers
    double** numbers = new (nothrow) double*[rows];

    if (numbers == nullptr) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }

    // Dynamically allocate each row
    int allocatedRows = 0;

    for (; allocatedRows < rows; allocatedRows++) {
        numbers[allocatedRows] =
            new (nothrow) double[columns];

        if (numbers[allocatedRows] == nullptr) {
            cout << "Memory allocation failed." << endl;

            for (int i = 0; i < allocatedRows; i++) {
                delete[] numbers[i];
            }

            delete[] numbers;
            return 1;
        }
    }

    // Enter values using nested loops
    cout << "\nEnter the array values:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Element [" << i << "][" << j << "]: ";

            if (!(cin >> numbers[i][j])) {
                cout << "Invalid numeric input." << endl;

                for (int k = 0; k < rows; k++) {
                    delete[] numbers[k];
                }

                delete[] numbers;
                return 1;
            }
        }
    }

    // Display the 2D array using nested loops
    cout << "\nYour 2D array is:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << numbers[i][j] << "\t";
        }

        cout << endl;
    }

    // Release all dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] numbers[i];
    }

    delete[] numbers;

    return 0;
}