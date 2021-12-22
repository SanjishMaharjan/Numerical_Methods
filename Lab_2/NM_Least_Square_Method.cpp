#include <iostream>
#include <math.h>
using namespace std;
class LSM
{
public:
    int n, i;
    float x[20], y[20], Y[20], D1, D2, D, Ex = 0, Ey = 0, Exy = 0, Exx = 0, a, b;

public:
    void input()
    {
        cout << "Enter the number of data: " << endl;
        cin >> n;
        cout << "Enter the value of x: " << endl;
        for (i = 0; i < n; i++)
        {

            cin >> x[i];
        }
        cout << "Enter the value of y: " << endl;
        for (i = 0; i < n; i++)
        {

            cin >> y[i];
        }
    }
    void summation()
    {
        for (i = 0; i < n; i++)
        {
            Ex = Ex + x[i];
            Ey = Ey + y[i];
            Exy = Exy + (x[i] * y[i]);
            Exx = Exx + (x[i] * x[i]);
        }
    }
    void calc()
    {
        D1 = Ey * Exx - Exy * Ex;
        D2 = n * Exy - Ex * Ey;
        D = n * Exx - Ex * Ex;
        a = D1 / D;
        b = D2 / D;
    }
    void calc_exp()
    {
        for (i = 0; i < n; i++)
        {
            Y[i] = log(y[i]);
        }
        for (i = 0; i < n; i++)
        {
            Ex = Ex + x[i];
            Ey = Ey + Y[i];
            Exy = Exy + (x[i] * Y[i]);
            Exx = Exx + (x[i] * x[i]);
        }
        /* D1 = Ey * Exx - Exy * Ex;
        D2 = n * Exy - Ex * Ey;
        D = n * Exx - Ex * Ex;
        a = D1 / D;
        b = D2 / D;*/
        /* for (i = 0; i < n; i++)
        {
            cout << Y[i];
        }*/
    }

    void display()
    {
        cout << "Ex=" << Ex << endl
             << "Ey=" << Ey << endl
             << "Exy=" << Exy << endl
             << "Exx=" << Exx << endl;
        if (b > 0)
        {

            cout << "The equation is : y=" << a << "+" << b << "x" << endl;
        }
        else
        {
            cout << "The equation is : y=" << a << b << "x" << endl;
        }
    }
    void exp_display()
    {

        {

            cout << "The equation is : y=" << exp(a) << "e^(" << b << "x)" << endl;
        }
    }
};
int main()
{
    LSM data;
    int ch;
    char c;
    do
    {

        data.input();
        cout << "Select the form of equation: \n1. Linear \n2. Exponetial" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            data.summation();
            data.calc();
            data.display();
            break;
        case 2:
            data.calc_exp();
            data.calc();
            data.exp_display();
            break;
        default:
            cout << "Please select the correct input!!!" << endl;
            break;
        }
        cout << "Do you want to repeat? \n Press 'Y or y' for repeat \n Press any other key to exit" << endl;
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}