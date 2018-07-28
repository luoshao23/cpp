#include <iostream>
#include <ctime>

using namespace std;



class Shape
{
    protected:
        double length;
        double width;
    public:
        Shape(double a, double b)
        {
            width = a;
            length = b;
        }
        virtual double area() = 0;

};

class Rectangle: public Shape{
    public:
      Rectangle(double a, double b) : Shape(a, b) {}
      double area()
      {
          return width * length / 2.0;
        }
};

int main()
{
    Shape *shape;
    Rectangle rec(10, 7);
    // Shape sh(5,2);

    shape = &rec;

    cout << shape->area() << endl;
    // cout << sh->area() << endl;
}