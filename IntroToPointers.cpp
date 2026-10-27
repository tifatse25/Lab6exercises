#include <iostream>
using namespace std;

int main() {
    int* pPointer = nullptr;
    int integerVar = 5;

    // Assign the address of integerVar to the pointer
    pPointer = &integerVar;

    cout << "integerVar: " << integerVar << endl;
    cout << "Address of integerVar: " << &integerVar << endl;
    cout << "pPointer: " << pPointer << endl;
    cout << "Address of pPointer: " << &pPointer << endl;

    return 0;
}