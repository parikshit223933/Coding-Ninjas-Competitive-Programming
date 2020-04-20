/* You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.
Input
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.
Output
For each test case, output a single line containing the corresponding answer.
Constraints
1 ≤ T ≤ 3

1 ≤ n ≤ 7.5 * 10^5

1 ≤ ai ≤ 7.5 * 10^5

All the elements of array a are distinct.
Example
Input
2
2
1 2
3
6 2 3
Output:
3
5
Explanation
Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}. */




#include <iostream>
#define m 1000000007
#define ll long long int
using namespace std;
ll size_of_sieve = 750001;
void Seive(ll *arr, ll n)
{
    ll *sieve = new ll[size_of_sieve];
    for (ll i = 0; i < size_of_sieve; i++)
    {
        sieve[i] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        sieve[arr[i]] = 1;
    }
    for (ll i = 1; i < size_of_sieve; i++)
    {
        ll current_element = i;
        if (sieve[current_element] != 0)
            for (ll j = 2; j * current_element < size_of_sieve; j++)
            {
                if (sieve[j * current_element] != 0)
                {
                    sieve[j * current_element] = (sieve[j * current_element] % m + sieve[i] % m) % m;
                }
            }
    }
    ll total_sum = 0;
    for (ll i = 0; i < size_of_sieve; i++)
    {
        total_sum = (total_sum % m + sieve[i] % m) % m;
    }
    cout << total_sum << endl;
    delete[] sieve;
}
int main()
{
    ll t;
    cin >> t;
    ll *arr = new ll[750001];
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Seive(arr, n);
    }
    delete[] arr;
}