#include <iostream>
using namespace std;

class BankAccount
{
protected:
    string name;

public:
    void setName(string n)
    {
        name = n;
    }
};

class Savings : public BankAccount
{
public:
    void show()
    {
        cout << "Saving Account: " << name << endl;
    }
};

class Current : public BankAccount
{
public:
    void show()
    {
        cout << "Current Account: " << name << endl;
    }
};

int main()
{
    Savings s;
    Current c;

    s.setName("Aarushi");
    c.setName("Aa'eedha");

    s.show();
    c.show();

    return 0;
}
