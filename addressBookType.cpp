#include "addressBookType.h"
#include <iostream>
#include <iomanip>
using namespace std;

int showMenu() {
    int choice;

    cout << "On-line Address Book" <<endl;
    cout << "Select an option:" << endl;;
    cout << "1 – Display all entries in the address Book." << endl;
    cout << "2 – Display an entry by a person’s name." << endl;
    cout << "3 – Display all entries with a given birth month." << endl;
    cout << "4 – Display all entries with a given relationship tag (Business, Friend, Family)." << endl;
    cout << "5 – Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main() {
    addressBookType addressBook;
    addressBook.initEntry();

    int choice;
    choice = showMenu();

    if (choice == 1) {
        cout << "Displaying all entries:" << endl;
        addressBook.print();
    }
}