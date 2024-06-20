#include <bits/stdc++.h>
using namespace std;


int main() {
    // Initialize random number generator
    mt19937 rng(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 100);
    int rollet = dist(rng); // Generate random number between 1 and 100

    cout << "\t\n########### Welcome to the Number Guessing Game! ################" << endl;
    cout << "\nA random number between 1 and 100 has been generated.\n" << endl;

    int PrizeMoney = 1000000;
    int lost_money = 100;

    while (true) {
        int user_guess;

        cout << "Enter your guess: ";
        cin >> user_guess;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (user_guess == rollet) {
            cout << "Congratulations! You guessed the correct number." << endl;
            cout << "You win Rs " << PrizeMoney << " Crore!\n\n" << endl;
            break;
        } else if (user_guess > rollet) {
            PrizeMoney -= lost_money;
            cout << "\nYour guess is higher.\n" << endl;
        } else {
            PrizeMoney -= lost_money;
            cout << "\nYour guess is lower.\n" << endl;
        }

        cout << "\nCurrent prize money: Rs" << PrizeMoney << endl;
        cout << "\nPenalty for next guess: Rs" << lost_money * 2 << endl;

        // Prompt for retry
        char choice;
        cout << "\n #### Do you want to continue? (y/n): ###";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "\n\tThanks for playing. See you next time!" << endl;
            break;
        }

        lost_money *= 2; // Double the penalty for next guess
    }

    return 0;
}
