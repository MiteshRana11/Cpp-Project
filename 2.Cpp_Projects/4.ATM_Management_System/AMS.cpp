#include <iostream>
#include <fstream>

using namespace std;

class ATM {

private:
    double balance;
    string pin;

public:

    ATM() {
        balance = 1000;
        pin = "1234";
    }

    bool authenticate() {

        string inputPin;

        cout << "Enter PIN: ";
        cin >> inputPin;

        return inputPin == pin;
    }

    void checkBalance() {
        cout << "Balance: " << balance << endl;
    }

    void deposit() {

        double amount;

        cout << "Deposit amount: ";
        cin >> amount;

        balance += amount;

        cout << "Deposit successful\n";
    }

    void withdraw() {

        double amount;

        cout << "Withdraw amount: ";
        cin >> amount;

        if(amount > balance)
            cout << "Insufficient funds\n";
        else{
            balance -= amount;
            cout << "Withdrawal successful\n";
        }
    }
};

int main() {

    ATM atm;

    if(!atm.authenticate()){
        cout << "Invalid PIN\n";
        return 0;
    }

    int choice;

    while(true){

        cout << "\n1.Check Balance\n2.Deposit\n3.Withdraw\n4.Exit\n";
        cin >> choice;

        switch(choice){

            case 1: atm.checkBalance(); break;
            case 2: atm.deposit(); break;
            case 3: atm.withdraw(); break;
            case 4: return 0;
        }
    }
}