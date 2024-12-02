#include <iostream>
#include <string>

class Account {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    Account(std::string accNum, std::string name, double bal) : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    // Function to display account details
    void displayAccountInfo() {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder Name: " << accountHolderName << "\n";
        std::cout << "Balance: " << balance << "\n";
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit Successful! New Balance: " << balance << "\n";
        } else {
            std::cout << "Invalid Deposit Amount\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal Successful! Remaining Balance: " << balance << "\n";
        } else {
            std::cout << "Invalid Withdrawal Amount\n";
        }
    }
};

int main() {
    std::string accNum, name;
    double initialBalance;

    // Get user input for account details
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cout << "Enter Account Holder Name: ";
    std::cin.ignore(); // Ignore newline left in buffer
    std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;

    // Create an account with user inputs
    Account myAccount(accNum, name, initialBalance);

    int choice;
    double amount;

    do {
        std::cout << "\n1. Display Account Info\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myAccount.displayAccountInfo();
                break;
            case 2:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                myAccount.deposit(amount);
                break;
            case 3:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
