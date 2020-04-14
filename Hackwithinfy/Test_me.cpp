#include <iostream>
#include<unordered_map>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define int long long int
#define endl '\n'
using namespace std;
string make_string(int n, int a, int b)
{
    unordered_map<char, int>map;
    string s="";
    int temp_a=a;

    int temp_b=b;
    while(n--)
    {
        for(int i='a'; i<='z'; i++)
        {
            if(temp_b==0)
            {
                
            }
            if(map[i]==0)
            {
                s+=(char)i;
                break;
            }
        }
    }
}
int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        cout << make_string(n, a, b) << endl;
    }
}