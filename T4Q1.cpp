#include<iostream>
#include<string>
using namespace std;

class Purchase
{
private:
    string itemName;
    int qty;
    float price,total;

public:
    Purchase(){}
    Purchase(string name, int quantity, float p)
    {
        itemName = name;
        qty = quantity;
        price = p;
    }
    void set_data(string name, int quantity, float p)
    {
        itemName = name;
        qty = quantity;
        price = p;
    }
    void print()
    {
        cout << "\n Item Name: " << itemName;
        cout << "\n Quantity: " << qty;
        cout << "\n Price: " << price;
    }
    void calculate()
    {
        cout << "\n Payment: " << (qty * price);
    }
};

int main()
{
    cout << "\n Hello ";
    Purchase p1("Apple",20,0.50);
    p1.print();
    cout<<endl;

    p1.set_data("Banana", 30, 0.25);
    p1.print();
    
    return 0;
}