#include <iostream>
#include <math.h>
#define e 0.000005
using namespace std;
double f(double x)
{
    double result;
    result = pow(x, 3) + 3 * pow(x, 2) - 5;
    return result;
}
int main()
{
    double a, b, c, i = 0;
    cout << "Enter the interval to be checked using bisection method: " << endl;
    cin >> a >> b;
    if (f(a) * f(b) > 0)
        cout << "The interval doesn't contain roots!!!" << endl;
    else if (f(a) * f(b) == 0)
    {
        if (f(a) == 0)
            cout << a;
        if (f(b) == 0)
            cout << b;
    }
    else
    {
        do
        {
            c = (a + b) / 2;
            if (f(c) * f(a) < 0)
            {
                b = c;
            }

            else
            {
                a = c;
            }

            if (i++ > 50)
            {
                cout << "The function is discontinuous " << endl;
                return (0);
            }

        } while (fabs(b - a) > e || fabs(f(c)) > e);
    }
    cout << "The value of root is " << c << endl;
    cout << "The number of steps required is " << i << endl;
    return 0;
}
