#include <iostream>
using namespace std;

// Base Exception
class BankException
{
public:
    string message;

    BankException(string msg)
    {
        message = msg;
    }
};

// Insufficient Balance Exception
class InsufficientBalance : public BankException
{
public:
    InsufficientBalance() : BankException("Insufficient Balance!")
    {
    }
};

// Invalid Amount Exception
class InvalidAmount : public BankException
{
public:
    InvalidAmount() : BankException("Invalid Amount!")
    {
    }
};

// Bank Account
class BankAccount
{
    double balance;

public:
    BankAccount(double b)
    {
        balance = b;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;

        cout << "Withdrawal Successful!" << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(5000);
    double amount;

    cout << "Enter amount: ";
    cin >> amount;

    try
    {
        account.withdraw(amount);
    }
    catch (BankException e)
    {
        cout << "Error: " << e.message << endl;
    }

    return 0;
}
