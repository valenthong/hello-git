#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    float price;
};

int main()
{
    Book b1,b2;
    b1.title = "Intro to C++";
    b1.price = 51.0;

    b2.title = "The smart detective";
    b2.price = 151.0;

    cout << endl
         << b2.title;
}