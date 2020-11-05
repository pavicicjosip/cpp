#include <iostream>
#include <cstdlib>

using namespace std;

class Complex
{
	protected:
		float re, im;
	public:
		Complex(float re = 0, float im = 0): im(im), re(re) {}

		float real() const { return re; }
		float imag() const { return im; }

		void real(float r) { re = r; }
		void imag(float i) { im = i; }

		Complex& operator=( const Complex& );
		Complex& operator+=( const Complex& );
		Complex& operator-=( const Complex& );

		Complex operator+( const Complex& ) const;
		Complex operator-( const Complex& ) const;

		bool operator==( const Complex& ) const;
		bool operator!=( const Complex& ) const;
};

ostream& operator<<( ostream& os, const Complex& c)
{
	os << c.real() << " " << c.imag() << endl;
	return os;
}

bool Complex::operator!=( const Complex& c) const
{
	return re != c.real() || im != c.imag() ;
}

bool Complex::operator==( const Complex& c) const
{
	return re == c.real() && im == c.imag();
}

Complex& Complex::operator-=( const Complex& c)
{
	re -= c.real();
	im -= c.imag();
	return *this;
}


Complex& Complex::operator+=( const Complex& c)
{
	re += c.real();
	im += c.imag();
	return *this;
}


Complex Complex::operator-( const Complex& c) const
{
	Complex w;
	w.real(re - c.real());
	w.imag(im - c.imag());
	return w;
}

Complex Complex::operator+( const Complex& c ) const
{
	Complex w;
	w.re = re + c.real();
	w.im = im + c.imag();
	return w;
}

Complex& Complex::operator=( const Complex& c )
{
	re = c.real();
	im = c.imag();
	return *this;
}



int main(void)
{
	Complex a(2,3);
	Complex c(2,3);
	Complex b;
	bool d = a == c;
	cout << a+c << endl;

	return EXIT_SUCCESS;
}