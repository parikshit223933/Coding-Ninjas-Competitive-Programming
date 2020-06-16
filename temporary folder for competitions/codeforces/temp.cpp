#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string b;
        cin >> b;
        string a = "";
        for (int i = 0; i < b.length(); i += 2)
        {
            a += b[i];
        }
        cout << a+b[b.length()-1] << endl;
    }
}