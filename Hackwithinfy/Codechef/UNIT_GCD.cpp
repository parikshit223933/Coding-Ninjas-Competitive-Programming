#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

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
    for (int i = 1; i <= n; i++)
    {
        if (marked[i])
        {
            continue;
        }
        unordered_set<int> prime_set;
        vector<int> temp;
        temp.push_back(i);
        for (auto prime : prime_factors[i])
        {
            prime_set.insert(prime);
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (marked[j])
            {
                continue;
            }
            bool checker = true;
            for (auto prime : prime_factors[j])
            {
                if (prime_set.count(prime) != 0)
                {
                    checker = false;
                }
            }
            if (checker)
            {
                temp.push_back(j);
                marked[j] = true;
                for (auto prime : prime_factors[j])
                {
                    prime_set.insert(prime);
                }
            }
        }
        ans.push_back(temp);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.size() << " ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
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