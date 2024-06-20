#include <bits/stdc++.h>
using namespace std;

/* Game Introduction 

    Rock Paper Scissor is a game that is played between two people, Each player in this game forms one 
    of three shapes. The winner will be decided as per the given rules:

    Rock vs Scissor -> Rock wins
    Rock vs Paper -> Paper wins
    Paper vs Scissor -> Scissor wins
    
    In this game, the user is asked to make choices, based on both computer and user choices and 
    the results are displayed showing both computer and user choices.
    
*/

int main() {
    int choice = -1; 
    mt19937 rng(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count())); // Seed once outside the loop

    while (choice != 0) {
        cout <<
            "\t################# MENU ###############\n"
            "\t# 1. Select 1 for Rock               #\n"
            "\t# 2. Select 2 for Paper              #\n"
            "\t# 3. Select 3 for Scissor            #\n"
            "\t# 4. Select 0 to Quit                #\n"
            "\t######################################\n"

            "Enter your choice: ";
        
        cin >> choice; // User Input
        
        uniform_int_distribution<int> dist(1, 3); // Distribution for integers between 1 and 3 (inclusive)
        int comp_choice = dist(rng); // Generate computer's choice
        
        switch (choice) {
            case 1:
                if (comp_choice == 2) {
                    cout << "Computer choice is: Paper\nYou LOSE !!!" << endl;
                } else if (comp_choice == 3) {
                    cout << "Computer choice is: Scissor\nYou WIN!!!" << endl;
                } else {
                    cout << "Computer choice is: Rock\nDRAW" << endl;
                }
                break;
            case 2:
                if (comp_choice == 1) {
                    cout << "Computer choice is: Rock\nYou WIN!!!" << endl;
                } else if (comp_choice == 3) {
                    cout << "Computer choice is: Scissor\nYou LOSE!!!" << endl;
                } else {
                    cout << "Computer choice is: Paper\nDRAW" << endl;
                }
                break;
            case 3:
                if (comp_choice == 1) {
                    cout << "Computer choice is: Rock\nYou LOSE!!!" << endl;
                } else if (comp_choice == 2) {
                    cout << "Computer choice is: Paper\nYou WIN!!!" << endl;
                } else {
                    cout << "Computer choice is: Scissor\nDRAW" << endl;
                }
                break;
            case 0:
                cout << "Exiting game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

