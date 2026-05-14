#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    int x,y;
    Point(int a_x, int a_y)
    {
        x = a_x;
        y = a_y;
    }
};

class Line
{
    private:
    Point point1;
    Point point2;

    public:
    Line(Point p1, Point p2) : point1(p1), point2(p2){}

    double Length()
    {
        double dx = point2.x - point1.x;
        double dy = point2.y - point1.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);
    
    Line line1(p1, p2);

    cout << "Length of line: " << line1.Length() << endl;

    return 0; 
}
              
