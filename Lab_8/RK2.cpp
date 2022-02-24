#include <iostream>
#include <math.h>
using namespace std;
float f(float x, float y)
{
    float Y;
    Y = pow(x, 2) + y;
    return Y;
}
int main()
{
    float x0, y0, xn, h;
    float n;
    float k1, k2, k;
    cout << "Enter the intial conditions" << endl;
    cin >> x0 >> y0;
    cout << "Enter the final value of x" << endl;
    cin >> xn;
    cout << "Enter the no of sub intervals:" << endl;
    cin >> n;
    h = (xn - x0) / n;
    float a = x0;
    float b = y0;
    for (int i = 0; i < n; i++)
    {
        k1 = h * f(a, b);
        k2 = h * f(a + h, b + k1);
        k = (k1 + k2) / 2;
        b = b + k;
        a = a + h;
        cout << "x" << (i + 1) << "=" << a << endl
             << "y" << (i + 1) << "=" << b << endl;
    }

    return 0;
}