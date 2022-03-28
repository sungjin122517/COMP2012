#include <iostream>
#include "school-namespaces.h"

// Note: You are supposed to insert new lines in this file, but not modify/delete existing lines!
// TODO 1: Specify namespaces to be used in this file.
namespace sc = science;
namespace engg = engineering;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void QueryEvents() {
    cout << "Select the school: 1. School of Engineering; 2. School of Science:";
    char choice;
    while(cin >> choice) {
        if (choice == '1' || choice == '2')
            break;
        else
            cout << "Select from 1 or 2." << endl;
    }

    if(choice == '1') {
        cout << "Select the department: 1. Department of CSE; 2. Department of ECE; 3. All Departments:";
        // TODO 2: Call the corresponding print_events function according to input.
        char eChoice;
        while (cin >> eChoice) {
            if (eChoice == '1') {
                engg::cse::show_events();
                break;
            }
            else if (eChoice == '2') {
                engg::ece::show_events();
                break;
            }
            else if (eChoice == '3') {
                engg::show_events();
                break;
            }
            else
                cout << "Invalid input." << endl;
        }

    }
    else {
        cout << "Select the department: 1. Department of Mathematics; 2. Department of Physics; 3. All Departments:";
        char sChoice;
        while (cin >> sChoice) {
            if (sChoice == '1') {
                sc::math::show_events();
                break;
            }
            else if (sChoice == '2') {
                sc::physics::show_events();
                break;
            }
            else if (sChoice == '3') {
                sc::show_events();
                break;
            } 
            else
                cout << "Invalid input." << endl;
        }
    }
}