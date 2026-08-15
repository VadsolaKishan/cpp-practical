/* In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors 
the real-world operations of various account types. The foundation of the system is a base class 
representing a generic bank account, encapsulating essential details such as account number and 
balance. Building on this foundation, two specialized account types were created: a savings account, 
which includes an interest rate as an additional feature, and a current account, which allows an 
overdraft limit to accommodate specific customer needs. 
To ensure proper initialization and cleanup of account objects, constructors and destructors were 
implemented. Essential banking operations such as deposits and withdrawals were made available for 
both account types, allowing users to perform and manage their transactions effectively. The system 
also accounted for the need to track and manage transaction history, enabling operations such as 
undoing the last transaction. This was achieved by simulating a mechanism to store a sequence of 
transactions for each account type, providing insight into different ways of managing and organizing 
data. */

#include <iostream>
#include <stack>
using namespace std;

class Bank_Account {
protected:
    string Account_Number;
    double Balance;

public:
    Bank_Account(string acc_num, double acc_balance) {
        Account_Number = acc_num;
        Balance = acc_balance;
    }

    void Deposit(double d) {
        Balance += d;
        cout << "Deposited: " << d << "  Balance: " << Balance << endl;
    }

    virtual void Withdraw(double w) {
        if (Balance >= w) {
            Balance -= w;
            cout << "Withdrawn: " << w << "  Balance: " << Balance << endl;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void Display_Balance() {
        cout << "Balance: " << Balance << endl;
    }
};

class Saving_Account : public Bank_Account {
public:
    Saving_Account(string acc_num, double acc_balance) : Bank_Account(acc_num, acc_balance) {}

    double cal_interest(double i_rate) {
        double interest_amount = (Balance * i_rate) / 100;
        Balance += interest_amount;
        cout << "Interest Amount: " << interest_amount << "   Balance: " << Balance << endl;
        return interest_amount;
    }
};

class Current_Account : public Bank_Account {
    double overdraft_limit;

public:
    Current_Account(string acc_num, double acc_balance, double o_limit)
        : Bank_Account(acc_num, acc_balance), overdraft_limit(o_limit) {}

    void withdraw(double w) {
        if (Balance + overdraft_limit >= w) {
            Balance -= w;
            cout << "Withdrawn: " << w << "  Balance: " << Balance << endl;
        } else {
            cout << "Overdraft Limit Exceeded" << endl;
        }
    }
};

int main() {
    stack<double> transaction_history;
    string acc_Type, acc_num;
    double acc_balance, interest_rate, overdraft_limit;
    int choice;
    double deposit, withdraw;

    cout << "Enter The Account Type (Saving / Current): ";
    cin >> acc_Type;

    if (acc_Type == "Saving") {
        cout << "Enter The Account Number: ";
        cin >> acc_num;

        cout << "Enter The Account Balance: ";
        cin >> acc_balance;

        Saving_Account account(acc_num, acc_balance);

        cout << "1.Deposit  2.Withdraw  3.Undo  4.Interest  5.Balance  6.Exit" << endl;

        while (1) {
            cout << "Enter The Choice: ";
            cin >> choice;

            if (choice == 6) {
                cout << "Exiting..." << endl;
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Enter The Amount To Deposit: ";
                    cin >> deposit;
                    account.Deposit(deposit);
                    transaction_history.push(deposit); // Record deposit
                    break;

                case 2:
                    cout << "Enter The Amount To Withdraw: ";
                    cin >> withdraw;
                    account.Withdraw(withdraw);
                    transaction_history.push(-withdraw); // Record withdrawal
                    break;

                case 3:
                    if (!transaction_history.empty()) {
                        double last_transaction = transaction_history.top();
                        transaction_history.pop();
                        if (last_transaction > 0) {
                            account.Withdraw(last_transaction); // Undo deposit
                        } else {
                            account.Deposit(-last_transaction); // Undo withdrawal
                        }
                        cout << "Last transaction undone." << endl;
                    } else {
                        cout << "No Transaction History" << endl;
                    }
                    break;

                case 4:
                    cout << "Enter The Interest Rate (%): ";
                    cin >> interest_rate;
                    account.cal_interest(interest_rate);
                    break;

                case 5:
                    account.Display_Balance();
                    break;

                default:
                    cout << "Invalid Choice! Try Again." << endl;
            }
        }
    } else if (acc_Type == "Current") {
        cout << "Enter The Account Number: ";
        cin >> acc_num;

        cout << "Enter The Account Balance: ";
        cin >> acc_balance;

        cout << "Enter The Overdraft Limit: ";
        cin >> overdraft_limit;

        Current_Account account(acc_num, acc_balance, overdraft_limit);

        cout << "1.Deposit  2.Withdraw  3.Undo  4.Balance  5.Exit" << endl;

        while (1) {
            cout << "Enter The Choice: ";
            cin >> choice;

            if (choice == 5) {
                cout << "Exiting..." << endl;
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Enter The Amount To Deposit: ";
                    cin >> deposit;
                    account.Deposit(deposit);
                    transaction_history.push(deposit); // Record deposit
                    break;

                case 2:
                    cout << "Enter The Amount To Withdraw: ";
                    cin >> withdraw;
                    account.withdraw(withdraw);
                    transaction_history.push(-withdraw); // Record withdrawal
                    break;

                case 3:
                    if (!transaction_history.empty()) {
                        double last_transaction = transaction_history.top();
                        transaction_history.pop();
                        if (last_transaction > 0) {
                            account.Deposit(last_transaction); // Undo deposit
                        } else {
                            account.withdraw(-last_transaction); // Undo withdrawal
                        }
                        cout << "Last transaction undone." << endl;
                    } else {
                        cout << "No Transaction History" << endl;
                    }
                    break;

                case 4:
                    account.Display_Balance();
                    break;

                default:
                    cout << "Invalid Choice! Try Again." << endl;
            }
        }
    } else {
        cout << "Invalid Account Type!" << endl;
    }

    return 0;
}
