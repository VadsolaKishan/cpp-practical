/*
Imagine you are tasked with developing a simple banking system for a local financial institution. The
bank has observed an increase in customer complaints regarding unclear transaction records and
unhandled errors during operations. They want a robust software module to manage bank accounts
efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more
than the account's current balance.
4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without
relying on advanced libraries or containers. Design and implement a banking system that fulfills the
above requirements.
*/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string transactions[MAX_TRANSACTIONS];
    int transactionCount;

    void logTransaction(const string& message) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = message;
        } else {
            cout << "Transaction log full. Unable to record more transactions.\n";
        }
    }

    void logError(const string& functionName, const string& errorMessage) {
        cout << "[ERROR] in function '" << functionName << "': " << errorMessage << endl;
        logTransaction("ERROR in " + functionName + ": " + errorMessage);
    }

public:
    BankAccount(const string& name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactionCount = 0;
        logTransaction("Account created for " + accountHolder + " with initial balance: " + to_string(balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logError("deposit", "Attempt to deposit non-positive amount.");
            return;
        }
        balance += amount;
        logTransaction("Deposited: $" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("withdraw", "Attempt to withdraw non-positive amount.");
            return;
        }
        if (amount > balance) {
            logError("withdraw", "Attempt to withdraw $" + to_string(amount) + " with only $" + to_string(balance) + " available.");
            return;
        }
        balance -= amount;
        logTransaction("Withdrawn: $" + to_string(amount));
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void showTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; ++i) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
        if (transactionCount == 0) {
            cout << "No transactions available.\n";
        }
    }
};

int main() {
    BankAccount user("Kishan", 10000.0);

    user.deposit(2500);
    user.withdraw(500);
    user.withdraw(20000); // Should log error
    user.deposit(-50);    // Should log error
    user.withdraw(1000);

    user.displayBalance();
    user.showTransactionHistory();

    
    return 0;
}

