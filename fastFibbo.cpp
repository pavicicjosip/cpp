#include <iostream>
using namespace std;

class Matrix
{
    public:
    int a, b, c, d;
    Matrix(int x, int y, int z, int w) : a(x), b(y), c(z), d(w) { }

    Matrix operator*(const Matrix& M) const
    {
        Matrix RJ(0,0,0,0);
        RJ.a = a * M.a + b * M.c;
        RJ.b = a * M.b + b * M.d;
        RJ.c = c * M.a + d * M.c;
        RJ.d = c * M.b + d * M.d;
        return RJ;
    }

};

ostream& operator<<(ostream& os, Matrix M)
{
    os << M.a << " " << M.b << "\n" << M.c << " " << M.d << endl;
}

Matrix pow(Matrix A)
{
    return A * A;
}

Matrix fastPow(Matrix M, int e)
{
    Matrix A(1,0,0,1);
    if( e == 0 )
        return A;

    if( e%2 == 0 )
        return pow(fastPow(M, e/2));
    else
        return M * fastPow( M, e - 1 );
}

int fibonacci(int n)
{
    Matrix M(1,1,1,0);
    return fastPow(M, n).b;
}

int main()
{
    int n;
    while(cin >> n)
        cout << fibonacci(n) << endl;

    return 0;
}

