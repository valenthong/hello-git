#include <iostream>
using namespace std;

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap_v2(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int x = 2, y = 4;
    swap(x, y);
    
    int a = 10, b = 20;
    swap_v2(&a, &b);

    return 0;
}