#include <iostream>
#include <math.h>
using namespace std;

double a, b, c, xo, x1, diff;
int count = 0, counter = 0;
void input_secant()
{
    cout << "Enter the interval to be checked by secant method: " << endl;
    cin >> a >> b;
}
void input_NR()
{
    cout << "Enter the number to be checked by Newton's Rapshon method: " << endl;
    cin >> xo;
}
double f(double x)
{
    double temp;
    temp = x * sin(x) + cos(x);
    return temp;
}
double g(double x)
{
    double temp;
    temp = x * cos(x);
    return temp;
}
double calc_secant()
{
    do
    {
        if (fabs(f(b) - f(a)) < 0.000005)
        {
            cout << "Error!!!" << endl;
            return 0;
        }
        else
        {
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            a = b;
            b = c;
            count++;
        }
        if (count > 500)
        {
            cout << "The solution doesn't lies between the intervals!!!" << endl;
        }
    } while (fabs(f(c) > 0.000005));
    cout << "The solution is " << c << endl;
    cout << "The number of steps required is: " << count << endl;
    return 0;
}

double calc_NR()
{
    do
    {
        if (fabs(g(xo)) < 0.000005)
        {
            cout << "Error!!!" << endl;
            return 0;
        }
        else
        {
            x1 = xo - f(xo) / g(xo);
            diff = fabs(x1 - xo);
            xo = x1;
            counter++;
        }

        if (counter > 500)
        {
            cout << "The solution doesn't lies between the intervals!!!" << endl;
        }
    } while (diff > 0.000005);
    cout << "The solution is " << x1 << endl;
    cout << "The number of steps required is: " << counter << endl;
    return 0;
}

int main()
{
    int ch;
    char c;
    cout << "*****Menu*******\n 1. Secant Method\n 2. Newton Rapshon Method\n";
    do
    {
        cout << "Select the method of your choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            input_secant();
            calc_secant();
            break;
        case 2:
            input_NR();
            calc_NR();
            break;
        default:
            cout << "Please select correct input!!!" << endl;
            break;
        }
        cout << "Do you want to repeat?\nPress 'Y'or'y' to repeat\nPress any key to exit. " << endl;
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}