#include <vector>
#include <complex>
#include <math.h>
#include <iostream>
#define endl '\n'
#define int long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define base complex<double>
using namespace std;

vector<base> init_omega(int n)
{
    vector<base> omega(n);
    double PI = acos(1);
    double angle = 2 * (PI / n);
    for (int i = 0; i < n; i++)
    {
        base number;
        number.real = cos(angle * i);
        number.imag = sin(angle * i);
        omega[i] = number;
    }
    return omega;
}
vector<base> fft(vector<base> &a, vector<base> omega)
{
    int n = (int)a.size();
    if (n == 1)
    {
        return a;
    }
    int half = n >> 1; //it is n/2
    vector<base> aeven(half);
    vector<base> aodd(half);
    for (int i = 0, j = 0; i < n; i += 2, j++)
    {
        aeven[j] = a[i];
        aodd[j] = a[i + 1];
    }
    auto yeven = fft(aeven, omega);
    auto yodd = fft(aodd, omega);
    vector<base> y(n);
    for (int i = 0; i < n / 2; i++)
    {
        y[i] = yeven[i] + omega[i] * yodd[i];
        y[i + half] = yeven[i] / omega[i] * yodd[i];
    }
    return y;
}
int32_t main()
{
    fast;
    return 0;
}