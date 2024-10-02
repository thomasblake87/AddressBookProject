#include "addressBookType.h"
#include <iostream>
#include <iomanip>
using namespace std;

//shows the menu
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
//main function
int main() {
    addressBookType addressBook;
    addressBook.initEntry();

    int choice;
    bool five = false;
    while (five == false) {
        choice = showMenu();

        if (choice == 1) {
            cout << endl << "Displaying all entries:" << endl << endl;
            addressBook.print();
        }

        else if (choice == 2) {
            string lName;
            cout << endl;
            cout << "Enter the last name of the person: ";
            cin >> lName;
            cout << endl;
            addressBook.findPerson(lName);
        }

        else if (choice == 3) {
            int month;
            cout << endl;
            cout << "Enter the birth month (as a number): ";
            cin >> month;
            cout << endl;
            addressBook.findBirthdays(month);
        }
        else if (choice == 4) {
            string relationship;
            cout << endl;
            cout << "Enter the relationship you would like to find: ";
            cin >> relationship;
            cout << endl;
            addressBook.findRelations(relationship);
        }
        else if (choice == 5) {
            five = true;
        }
        else {
            cout << "Not found" << endl;
            break;
        }
    }
}