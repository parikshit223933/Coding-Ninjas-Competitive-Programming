/* Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1 */




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxSize 2000001
int main()
{
    int *sieve = new int[MaxSize];
    for (int i = 0; i <= MaxSize; i++)
    {
        sieve[i] = i;
    }
    for (int i = 2; i * i <= MaxSize; i++)
    {
        for (int j = i * i; j <= MaxSize; j += i)
        {
            if (sieve[j] > i)
            {
                sieve[j] = i;
            }
        }
    }
    int n, k = 0;
    cin >> n;
    int *finalans = new int[n];
    bool *marked = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        marked[i] = false;
    }
    for (int i = n; i >= 1; i--)
    {
        if (!marked[i])
        {
            int lpd = sieve[i];
            int x = i;
            vector<int> v;
            marked[i] = true;
            v.push_back(i);
            while (x != 1)
            {
                for (int j = i - lpd; j >= 1; j = j - lpd)
                {
                    if (!marked[j])
                    {
                        marked[j] = true;
                        v.push_back(j);
                    }
                }
                while (x % lpd == 0)
                {
                    x = x / lpd;
                }
                lpd = sieve[x];
            }
            sort(v.begin(), v.end(), greater<int>());
            for (int i = 0; i < v.size(); i++)
            {
                finalans[k] = v[i];
                k++;
            }
        }
    }
    finalans[n - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        cout << finalans[i] << " ";
    }
    cout << endl;
}