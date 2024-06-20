#include <bits/stdc++.h>
using namespace std;


/*                  HANGMAN GAME

    Hangman is a classic word guessing game where one player thinks of a word, phrase, 
    or sentence and the other player tries to guess it by suggesting letters within a certain number of guesses.
    The game is typically played with two or more players, but it can also be played solo.
*/

// Function to check if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert a string to uppercase
string toUpper(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = toupper(c);
        }
    }
    return str;
}

// Function to play Hangman game
void playHangman() {
    vector<string> words = {"PROGRAMMING", "COMPUTER", "ENGINEERING", "ALGORITHM", "DATA", "STRUCTURE"};
    
    srand(static_cast<unsigned int>(time(nullptr)));
    string secretWord = words[rand() % words.size()]; // Randomly select a word from the vector
    string guessedLetters(secretWord.length(), '_'); // Initialize guessed letters with underscores
    
    // cout << "secret word = " << secretWord <<endl;
    
    int maxAttempts = 6;
    int attemptsLeft = maxAttempts;
    vector<char> incorrectGuesses;

    cout << "\t\t\n #### Hangman! ####\n" << endl;
    cout << "Guess the word: ";
    
    while (attemptsLeft > 0) {
        cout << guessedLetters << endl;
        cout << "Attempts left: " << attemptsLeft << endl;
        
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        
        // Convert guess to uppercase if it's a letter
        if (isLetter(guess)) {
            guess = toupper(guess);
        } else {
            cout << "Invalid input. Please enter a letter." << endl;
            continue;
        }
        
        bool found = false;
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedLetters[i] = guess;
                found = true;
            }
        }
        
        if (found) {
            cout << "Correct guess!" << endl;
        } else {
            cout << "Incorrect guess." << endl;
            incorrectGuesses.push_back(guess);
            --attemptsLeft;
        }
        
        // Check if all letters have been guessed correctly
        if (guessedLetters == secretWord) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            return;
        }
    }
    
    // Out of attempts
    cout << "Sorry, you're out of attempts. The word was: " << secretWord << endl;
}

int main() {
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        playHangman();
        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    
    cout << "Thanks for playing Hangman!" << endl;
    
    return 0;
}
