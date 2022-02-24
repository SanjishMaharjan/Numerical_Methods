#include <iostream>
#include <math.h>
using namespace std;
float f(float x, float y)
{
    float Y;
    Y = pow(x, 2) - y;
    return Y;
}
int main()
{
    float x0, y0, xn, h, n, k;
    // taking inputs...
    cout << "Enter the intial conditions" << endl;
    cin >> x0 >> y0;
    cout << "Enter the final value of x" << endl;
    cin >> xn;
    cout << "Enter the no of sub intervals:" << endl;
    cin >> n;

    h = (xn - x0) / n; // calculating interval

    float a = x0; // intialing values of a and b for further looping intial values
    float b = y0;
    for (int i = 0; i < n; i++)
    {
        k = h * f(a, b);
        b = b + k;
        a = a + h;
        cout << "x" << (i + 1) << "=" << a << endl
             << "y" << (i + 1) << "=" << b << endl;
    }

    return 0;
}