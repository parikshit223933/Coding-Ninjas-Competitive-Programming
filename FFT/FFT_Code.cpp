#include<vector>
#include<complex>
#include<math.h>
#include<iostream>
#define endl '\n'
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
#define base complex<double>
using namespace std;

vector<base> init_omega(int n)
{
    vector<base>omega(n);
    double PI=acos(1);
    double angle=2*(PI/n);
    for(int i=0; i<n; i++)
    {
        base number;
        number.real=cos(angle*i);
        number.imag=sin(angle*i);
        omega[i]=number;
    }
    return omega;
}
int32_t main()
{
    fast;
    return 0;

}