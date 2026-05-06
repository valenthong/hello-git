#include <iostream>
using namespace std;

class Temperature {
private:
    double tempCel;
    double tempFar;

public:
    Temperature() {
        tempCel = 0;
        tempFar = 32;
    }
\
    Temperature(char unit, double val) {
        if (unit == 'C' || unit == 'c') {
            tempCel = val;
            tempFar = (val * 9.0 / 5.0) + 32.0; // 摄氏度转华氏度 [cite: 24]
        } 
        else if (unit == 'F' || unit == 'f') {
            tempFar = val;
            tempCel = (val - 32.0) * 5.0 / 9.0; 
        } 
        else {
            tempCel = 0;
            tempFar = 32;
        }
    }

    double getCels() {
        return tempCel;
    }

   
    double getFar() {
        return tempFar;
    }

   
    void equal(Temperature t) {
        this->tempCel = t.tempCel;
        this->tempFar = t.tempFar;
    }
};


int main() {
    Temperature t1('C', 100), t2('F', 100);
    
    cout << "t1 = " << t1.getCels() << " C\n";
    cout << "t1 = " << t1.getFar() << " F\n";
    cout << "t2 = " << t2.getCels() << " C\n";
    cout << "t2 = " << t2.getFar() << " F\n";
    
    t1.equal(t2); 
    
    cout << "After assigning t2 to t1" << endl;
    cout << "t1 = " << t1.getCels() << " C\n";
    cout << "t1 = " << t1.getFar() << " F\n";
    
    return 0;
}