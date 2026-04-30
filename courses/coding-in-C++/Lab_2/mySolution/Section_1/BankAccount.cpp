#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string owner;
    double balance;
    
public:
    BankAccount() : balance(0.0) {}
    void setOwner(std::string newOwner)
    {
        this->owner = newOwner;
    }

    std::string getOwner()
    {
        return owner;
    }

    void deposit(double amount)
    {
        if (amount < 0)
        {
            std::cout << "Invalid amount. Amount must be greater than 0" << std::endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "Invalid amount. You cannot withdraw more than " << balance << " Euro" << std::endl;
            return;
        }
        
        balance -= amount;
        std::cout << "Your new balance is: " << getBalance() << " Euro" << std::endl;
    }

double getBalance();
void getAccountInfo();
};

double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::getAccountInfo()
{
    std::cout << "Name: " << getOwner() << std::endl;
    std::cout << "Balence: " << getBalance() << std::endl;
}

int main()
{
    BankAccount myAccount;
    myAccount.setOwner("Lennart Peppinghaus");

    myAccount.getAccountInfo();

    myAccount.deposit(1234.12);

    myAccount.getAccountInfo();

    myAccount.withdraw(99999);
    myAccount.getAccountInfo();

    myAccount.withdraw(20);

    myAccount.getAccountInfo();
    return 0;
}

// in the standart code, balence dose not get initilized. this is fixed by calling a constructor to initialize the variable.