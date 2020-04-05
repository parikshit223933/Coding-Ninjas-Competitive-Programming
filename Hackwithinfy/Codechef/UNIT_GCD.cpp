#include <iostream>
#include <vector>
#include<math.h>
#include<algorithm>
using namespace std;
bool find(vector<int> v, int element)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element)
        {
            return true;
        }
    }
    return false;
}
bool have_any_element_in_common(vector<int> v1, vector<int> v2)
{
    bool ans = false;
    ;
    for (auto i : v1)
    {
        if (find(v2, i))
        {
            ans = true;
            break;
        }
    }
    return ans;
}
void makeSieve(int n)
{
    bool *isprime = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isprime[i])
            for (int j = i; j * i <= n; j++)
            {
                isprime[j * i] = false;
            }
    }
    vector<int> *prime_factors = new vector<int>[n + 1];
    bool *marked = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        marked[i] = false;
    }
    vector<vector<int>> ans;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = 1; j * i <= n; j++)
            {
                prime_factors[j * i].push_back(i);
            }
        }
    }
    delete[] isprime;
    for (int i = 2; i <= n; i++)
    {
        if (marked[i])
        {
            continue;
        }
        vector<int> temp;
        temp.push_back(i);
        if(i==2)//to adjust 1
        {
            temp.push_back(1);
        }
        marked[i] = true;
        for (int j = i+1; j <= n; j++)
        {
            if(marked[j])
            {
                continue;
            }
            if (!have_any_element_in_common(prime_factors[i], prime_factors[j]))
            {
                temp.push_back(j);
                marked[j] = true;
            }
        }
        ans.push_back(temp);
    }
    int a=ans.size();
    cout<<a<<endl;
    for (auto i : ans)
    {
        cout<<i.size()<<" ";
        sort(i.begin(), i.end());
        for (auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        makeSieve(n);
    }
}