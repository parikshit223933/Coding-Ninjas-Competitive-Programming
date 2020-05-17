#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include <limits.h>
#include <vector>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
}
int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int* lps = new int[M];
    int j = 0;
    computeLPSArray(pat, M, lps);

    int i = 0;
    int res = 0;
    int next_i = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
            if (lps[j] != 0)
                i = ++next_i;
            j = 0;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}


int countdowns(int *arr, int n, int k)
{
    string pat="";
    for(int i=k; i>=1; i--)
    {
        pat+=to_string(i)+"|";
    }
    pat=pat.substr(0, pat.length()-1);
    string txt="";
    for(int i=0; i<n; i++)
    {
        txt+=to_string(arr[i])+"|";
    }
    txt=txt.substr(0, txt.length()-1);
    return KMPSearch(pat, txt);
}
int main()
{
    fast;
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Case #" << p << ": " << countdowns(arr, n, k) << endl;
    }
}