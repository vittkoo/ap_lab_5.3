#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

double k(const double x);

int main()
{
    double zp, zk, h;
    int n;

    cout << "zp = "; cin >> zp;
    cout << "zk = "; cin >> zk;
    cout << "n  = "; cin >> n;

    cout << fixed;
    cout << "-----------------------------------------------" << endl;
    cout << "|" << setw(5) << "z" << "     |"
        << setw(20) << "result" << "              |"
        << endl;
    cout << "-----------------------------------------------" << endl;

    double dz = (zk - zp) / n;
    double z = zp;

    while (z <= zk)
    {
        h = k(z * z + 1) - k(z * z - 1) + 2 * k(z);
        cout << "|" << setw(7) << setprecision(2) << z << "   |"
            << setw(20) << setprecision(5) << h << "              |"
            << endl;
        z += dz;
    }
    cout << "-----------------------------------------------" << endl;
    return 0;
}

double k(const double x)
{
    if (abs(x) >= 1)
        return (exp(x) + sin(x)) / (pow(cos(x), 2) + 1);
    else
    {
        double S = 0;
        int i = 0;
        double a = 1;
        S = a;
        do
        {
            i++;
            double R = x / i;
            a *= R;
            S += a;
        } while (i < 5);
        return (1 / exp(x)) * S;
    }
}