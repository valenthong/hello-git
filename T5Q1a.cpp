
#include <iostream>
using namespace std;

class Fraction
{

private:
    int numerator;
    int denominator;

public:
    Fraction(){}
    Fraction(int a_nume, int a_denom)
    {
      numerator = a_nume;
      denominator = a_denom;
    }

    void display()
    {
        cout << numerator << "/" << denominator;
    }

    Fraction add(Fraction other)
    {
        int new_num = numerator * other.denominator + denominator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction multiply(Fraction other)
    {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
};

int main() 
{
    cout << "\n Hello world \n";
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result;

    cout << "f1: ";
    f1.display();
    cout << endl;
    
    cout << "f2: ";
    f2.display();
    cout << endl;   
    
    cout << "f1 + f2: ";
    result = f1.add(f2);
    result.display();
    cout << endl;
    
    cout << "f1 * f2: ";
    result = f1.multiply(f2);
    result.display();
    cout << endl;
    

    return 1;
}