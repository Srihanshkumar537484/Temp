#include <iostream>
#include <string>
#include <limits>

using namespace std;

class BankAccount {
private:
    string name;
    string address;
    char accountType;
    float balance;

public:
    BankAccount() : balance(0.0) {} // Constructor initializes balance to 0

    void openAccount() {
        cout << "Enter your full name: ";
        getline(cin, name);
        cout << "Enter your address: ";
        getline(cin, address);
        cout << "What type of account do you want to open (saving 's' or current 'c'): ";
        cin >> accountType;
        cout << "Enter initial deposit amount: ";
        cin >> balance;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        cout << "Your account is created.\n";
    }

    void depositMoney() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited. New balance: " << balance << endl;
    }

    void withdrawMoney() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn. New balance: " << balance << endl;
        }
    }

    void displayAccount() const {
        cout << "Account details:\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Account Type: " << (accountType == 's' ? "Saving" : "Current") << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\nBank Management System\n";
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account\n";
        cout << "5) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case 1:
                account.openAccount();
                break;
            case 2:
                account.depositMoney();
                break;
            case 3:
                account.withdrawMoney();
                break;
            case 4:
                account.displayAccount();
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}