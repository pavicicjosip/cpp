#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double fastPow(double b, int e)
{
	if( e == 0 )
		return 1;

	if( e%2 == 0 )
		return pow(fastPow(b, e/2), 2);
	else
		return b * fastPow( b, e - 1 );
}

int main(void)
{
	double base;
	int exp;

	while(cin >> base >> exp)
		cout << fastPow(base, exp) << endl;

	return EXIT_SUCCESS;
}