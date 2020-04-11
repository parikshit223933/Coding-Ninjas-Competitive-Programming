#include<iostream>
#define endl '\n'
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int solve(int t, int m)
{
    auto initial_energy=1;
    if(t<=m)
    {
        return 1;
    }

    if(t/m==1)
    {
        int run_the_loop_till=t%m;
        int current_multiplier=run_the_loop_till;
        while(current_multiplier!=0)
        {
            initial_energy=((initial_energy%m)*(current_multiplier%m));
            current_multiplier--;
        }
        return (initial_energy*(m-1))%m;
    }
    else
    {
        int run_the_loop_till=t%m;
        int current_multiplier=run_the_loop_till;
        while(current_multiplier!=0)
        {
            initial_energy=initial_energy*current_multiplier;
            current_multiplier--;
        }
        return initial_energy;
    }
}
int32_t main()
{
    fast
    int n;
    cin>>n;
    while(n--)
    {
        int t, m;
        cin>>t>>m;
        cout<<solve(t, m)<<endl;
    }
}