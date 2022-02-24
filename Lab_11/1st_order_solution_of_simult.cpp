#include <iostream>
#include <math.h>
using namespace std;
float f1(float x, float y, float z)
{
    float Y;
    Y = 3 * x + y - z;
    return Y;
}
float f2(float x, float y, float z)
{
    float Z;
    Z = 2 * x - y + z;
    return Z;
}
int main()
{
    float x0, y0, z0, xn, h;
    float n;
    float k1, k2, k3, k4, l1, l2, l3, l4, k, l;
    cout << "Enter the intial conditions for x , y and z" << endl;
    cin >> x0 >> y0 >> z0;
    cout << "Enter the final value of x" << endl;
    cin >> xn;
    cout << "Enter the no of sub intervals:" << endl;
    cin >> n;
    h = (xn - x0) / n;
    float a = x0;
    float b = y0;
    float c = z0;
    for (int i = 0; i < n; i++)
    {
        k1 = h * f1(a, b, c);
        l1 = h * f2(a, b, c);
        cout << "k1=" << k1 << "\t"
             << "l1=" << l1 << endl;
        k2 = h * f1(a + h / 2, b + k1 / 2, c + l1 / 2);
        l2 = h * f2(a + h / 2, b + k1 / 2, c + l1 / 2);
        cout << "k2=" << k2 << "\t"
             << "l2=" << l2 << endl;
        k3 = h * f1(a + h / 2, b + k2 / 2, c + l2 / 2);
        l3 = h * f2(a + h / 2, b + k2 / 2, c + l2 / 2);
        cout << "k3=" << k3 << "\t"
             << "l3=" << l3 << endl;
        k4 = h * f1(a + h, b + k3, c + l3);
        l4 = h * f2(a + h, b + k3, c + l3);
        cout << "k4=" << k4 << "\t"
             << "l4=" << l4 << endl;
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        b = b + k;
        a = a + h;
        c = c + l;
        cout << "x" << (i + 1) << "=" << a << endl
             << "y" << (i + 1) << "=" << b << endl
             << "z" << (i + 1) << "=" << c << endl;
    }

    return 0;
}