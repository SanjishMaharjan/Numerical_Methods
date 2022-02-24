#include <iostream>
#include <math.h>
using namespace std;
#define Size 50
int main()
{
    int n;
    double A[Size][Size], B[Size][Size], a[Size][Size], temp;
    cout << "Enter number of unknowns: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data of row " << i + 1 << ": " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                A[i][j + n] = 1;
            else
                A[i][j + n] = 0;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (A[j][j] == 0.0000005)
        {
            cout << "Math Error!!!" << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)

        {
            if (i != j)
            {
                temp = A[i][j];
                for (int k = 1; k <= n + 1; k++)
                {
                    A[i][k] = A[i][k] - (temp / A[j][j]) * A[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            a[i][j] = A[i][j] / A[i][i];
        }
    }
    cout << "/n The solution is:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
