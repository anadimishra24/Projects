#include <bits/stdc++.h>
using namespace std;

class Account{
    private:
        string holderName;
        long accountNumber;
        double balance;

    public:

        // counstructor to store the entry of new costumer
        Account(string& name, double accNumber, double money)
            : holderName(name), accountNumber(accNumber), balance(money) {}
        
    // Function to display account information
    void display() const {
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs " << balance << endl;
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
            cout << "Deposit successful. New balance: Rs " << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Rs" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount for withdrawal." << endl;
        }
    }

};


class Bank{

    private:
        string bankName;
        long nextAccountNumber;

    public:
        // Constructor to initialize bank name and start with no accounts
        Bank(const string& name)
        : bankName(name), nextAccountNumber(1001) {} // Start account numbers from 1001

        string accHolderName;
        double amount;
        vector<Account> newAccount;
        
        void createAccount(){
            cout << "Enter Account Holder Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            getline(cin, accHolderName);

            cout << "Enter your amount: ";
            cin >> amount; 

            long newAccountNumber = nextAccountNumber++;

            Account newAcc(accHolderName, newAccountNumber, amount);
            newAccount.push_back(newAcc);
            cout << "Account created successfully!" << endl;
            newAcc.display();    
        }

        // Function to search for an account by account number
        Account* findAccount(long accountNumber) {
            for (auto& account : newAccount) {
                if (account.getAccountNumber() == accountNumber) {
                    return &account;
                }
            }
            return nullptr; // Account not found
        }

        void operateAccount(){
            long accountNumber;
            int choice;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accountNumber;

            Account* foundAccount = findAccount(accountNumber);
            if (foundAccount) {
                cout << "Account found! Select an operation:" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter deposit amount: Rs ";
                        cin >> amount;
                        foundAccount->deposit(amount);
                        break;
                    case 2:
                        cout << "Enter withdrawal amount: Rs ";
                        cin >> amount;
                        foundAccount->withdraw(amount);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
            } else {
                cout << "Account not found." << endl;
            }
        }
    
        // Function to display all accounts in the bank
        void displayAllAccounts() const {
            cout << "Bank Name: " << bankName << endl;
            cout << "-----------------------" << endl;
            for (const auto& account : newAccount) {
                account.display();
                cout << "-----------------------" << endl;
            }
        }

    void MBL(){
        cout << "\n\t--------------------";
        cout << "\n\t| Mishra Bank Ltd. |\n";
        cout << "\t--------------------";
    }
};


int main(){

    Bank bank("Mishra Bank LTD.");
    bank.MBL();

     int choice = -1; 

    while (choice != 0) {
        cout <<
            "\n\t################## MENU ####################\n"
            "\t# 1. Select 1 for Create new Account         #\n"
            "\t# 2. Select 2 for Operate Account            #\n"
            "\t# 3. Select 3 for Display all Account        #\n"
            "\t# 4. Select 0 to Close the banking session   #\n"
            "\t##############################################\n"

            "\nEnter your choice: ";
        
        cin >> choice; // User Input
        
        switch (choice) {
            case 1:
                cout << "Create new Account" << endl;
                bank.createAccount();
                break;
            case 2:
                cout << "Operate Account" << endl;
                bank.operateAccount();
                break;
            case 3:
                cout << "Display all Accounts" << endl;
                bank.displayAllAccounts();
                break;
            case 0:
                cout << "Closing the banking session. GOOD BYE !!!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }


    return 0;

}