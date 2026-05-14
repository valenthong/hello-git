#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initial_balance){
     balance = initial_balance;
    }
    void Deposit(double amount)
    {
        balance += amount;
    }
    void Withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            balance -= amount;
        }
    }
    double GetBalance()
    {
        return balance;
    }
};

int main()
{

    BankAccount account(1000.0);
    
    cout << "Current balance: " << account.GetBalance() << endl;

    account.Withdraw(500.0);
    cout << "Current balance: " << account.GetBalance() << endl;

    account.Withdraw(600.0);
    cout << "Current balance: " << account.GetBalance() << endl;

    return 1;
}

