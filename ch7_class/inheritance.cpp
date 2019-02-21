#include <iostream>

using namespace std;

class Shape
{
public:
	Shape() = default;
	Shape(int w, int h): width(w), height(h) {}
	void setWidth(int w) {width = w;}
	void setHeight(int h) {height = h;}
protected:
	int width;
	int height;
};

class Rectangle: public Shape
{
public:
	Rectangle() = default;
	Rectangle(int w, int h): Shape(w, h) {}
	int getArea() { return width * height; }
};

int main()
{
	Rectangle r(5, 3);
	cout << r.getArea() << endl;
	return 0;
}
