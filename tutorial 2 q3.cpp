#include <iostream>
using namespace std;

void drawBox(int w);
void drawFullLine(int w);
void drawEmptyLine(int w);

int main() {
    int width;
    cout << "\n Enter the side of the square box (1-16): ";
    if (!(cin >> width) || width < 1 || width > 20) {
        cout << "Ending program. Only integer values between 1 and 20 accepted" << endl;
        return 0;
    }
    drawBox(width);
    return 0;
}

void drawBox(int w) {
    if (w <= 0) return;
    drawFullLine(w);
    for (int i = 0; i < w - 2; i++) {
        drawEmptyLine(w);
    }
    if (w > 1) {
        drawFullLine(w);
    }
}

void drawFullLine(int w) {
    for (int i = 0; i < w; i++) {
        cout << "*";
    }
    cout << endl;
}

void drawEmptyLine(int w) {
    cout << "*";
    for (int i = 0; i < w - 2; i++) {
        cout << " ";
    }
    if (w > 1) {
        cout << "*";
    }
    cout << endl;
}