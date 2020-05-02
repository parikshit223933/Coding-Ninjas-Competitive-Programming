#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <limits.h>
#include <algorithm>
#define endl '\n'
#define int long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
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

    int *lps = new int[M];
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
int32_t main()
{
    cout<<KMPSearch("pai", "paisisisisisisisisisisisisis");
}