
# Simple Banking System

## Project Overview:
Create a console-based banking system that allows users to create accounts, deposit money, withdraw money (if sufficient funds are available), check their balance, and view transaction history.

## Key Features to Implement:

# Account Management:

Allow users to create a new account with a unique account number and initial balance.
Store account information (account number, balance, transaction history) using appropriate data structures (e.g., arrays, vectors).

# Transactions:

Implement functionalities to deposit money into an account and withdraw money (ensure sufficient balance before withdrawal).
Maintain a transaction history (e.g., date, type of transaction, amount) for each account.


# Balance Inquiry:

Enable users to check their current account balance.

# Error Handling:

Handle common errors such as insufficient funds during withdrawal and invalid account numbers.


# User Interface:

Create a user-friendly interface using console input/output to interact with the banking system.
Provide clear prompts and messages to guide the user through various actions.


### Additional Enhancements (Optional):

>> Interest Calculation: Implement a feature to calculate and display interest earned on savings accounts.
Multiple Accounts: Extend the system to manage multiple accounts per user.
Data Persistence: Implement file handling to store account information persistently between program runs.
Security Measures: Add basic security features like PIN verification for transactions.


>> Why This Project Stands Out:

Real-world Application: Demonstrates your ability to implement practical solutions relevant to financial systems.
Data Structures: Utilizes arrays or vectors for managing accounts and transactions, showcasing your understanding of fundamental data structures in C++.
Error Handling and Input Validation: Shows your attention to detail in handling potential errors and user input validation.
Scalability: Allows for future expansion with additional features, showcasing your potential to grow as a developer.
Implementing this project will not only enhance your C++ skills but also provide you with a tangible example to discuss during job interviews. It demonstrates your ability to work with data structures, handle user input, manage program flow, and implement core functionalities that are essential in many software development roles.



########################################### 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define Account class to represent individual bank accounts
class Account {
private:
    string holderName;
    long accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    Account(const string& name, long accNumber, double initialBalance)
        : holderName(name), accountNumber(accNumber), balance(initialBalance) {}

    // Function to get account holder name
    string getHolderName() const {
        return holderName;
    }

    // Function to get account number
    long getAccountNumber() const {
        return accountNumber;
    }

    // Function to get current balance
    double getBalance() const {
        return balance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount for withdrawal." << endl;
        }
    }

    // Function to display account information
    void display() const {
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Define Bank class to manage multiple accounts and bank operations
class Bank {
private:
    string bankName;
    vector<Account> accounts;
    long nextAccountNumber;

public:
    // Constructor to initialize bank name and start with no accounts
    Bank(const string& name)
        : bankName(name), nextAccountNumber(1001) {} // Start account numbers from 1001

    // Function to create a new account
    void createAccount(const string& holderName, double initialDeposit) {
        long newAccountNumber = nextAccountNumber++;
        Account newAccount(holderName, newAccountNumber, initialDeposit);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
        newAccount.display();
    }

    // Function to search for an account by account number
    Account* findAccount(long accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr; // Account not found
    }

    // Function to display all accounts in the bank
    void displayAllAccounts() const {
        cout << "Bank Name: " << bankName << endl;
        cout << "-----------------------" << endl;
        for (const auto& account : accounts) {
            account.display();
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    // Create a bank object
    Bank bank("Mishra Bank Ltd.");

    // Example usage: creating accounts and performing operations
    bank.createAccount("John Doe", 500.0);
    bank.createAccount("Jane Smith", 1000.0);

    // Display all accounts in the bank
    bank.displayAllAccounts();

    // Example operations on an account
    long searchAccountNumber = 1001; // Example account number to search for
    Account* foundAccount = bank.findAccount(searchAccountNumber);
    if (foundAccount) {
        cout << "Account found! Performing operations..." << endl;
        foundAccount->deposit(300.0);
        foundAccount->withdraw(100.0);
        foundAccount->display();
    } else {
        cout << "Account not found." << endl;
    }

    return 0;
}
####################################################################