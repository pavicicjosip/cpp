#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Point
{
	protected:
		double x, y;
	public:
		Point() {}
		Point(double x, double y): x(x), y(y) {}

		void setx(double x) { this->x = x; }
		void sety(double y) { this->y = y; }

		double getx() const { return x; }
		double gety() const { return y; }

		void printPoint() const { cout << "(" << x << ", " << y << ")" << endl; }

		double euclideanDistance() const { return sqrt(pow(x, 2) + pow(y, 2)); }

		~Point() {}
};

int main(void)
{
	Point *T = new Point[5];
	T[0].setx(5);
	T[0].sety(4);

	T[1].setx(3);
	T[1].sety(13);

	cout << T[0].euclideanDistance() - T[1].euclideanDistance() << endl;

	delete [] T;

	return EXIT_SUCCESS;
}