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

/* public
static void main(String args[])
{
    String txt = "geeksforgeeks";
    String pat = "eeks";
    int ans = new KMP_String_Matching().KMPSearch(pat, txt);
    System.out.println(ans);
} */

struct string_pleasure
{
    string s;
    int b;
};
void GetAllSubstrings(string s, int n, vector<string>&substrings)  
{ 
    /* 
     * Fix start index in outer loop. 
     * Reveal new character in inner loop till end of string. 
     * Print till-now-formed string. 
     */
    for (int i = 0; i < n; i++) 
    { 
        char *temp=new char [n - i + 1]; 
        int tempindex = 0; 
        for (int j = i; j < n; j++) 
        { 
            temp[tempindex++] = s[j]; 
            temp[tempindex] = '\0'; 
            substrings.push_back(temp);
        }
        delete[]temp;
    }
    substrings.push_back("");
} 
int maximum_pleasure(string_pleasure *arr, int n, string a, string b)
{
    vector<string>a_substrings;
    vector<string>b_substrings;
    GetAllSubstrings(a, a.length(), a_substrings);
    GetAllSubstrings(b, b.length(), b_substrings);
    int max_pleasure=INT_MIN;
    for(auto i:a_substrings)
    {
        for(auto j:b_substrings)
        {
            string c=i+j;
            int pleasure=0;
            for(int k=0; k<n; k++)
            {
                int cnti=KMPSearch(arr[k].s, c);
                pleasure+=cnti*arr[k].b;
            }
            max_pleasure=max(max_pleasure, pleasure);
        }
    }
    return max_pleasure;
}
int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int n;
        cin >> n;
        string_pleasure *arr = new string_pleasure[n];
        for (int i = 0; i < n; i++)
        {
            string_pleasure sp;
            cin >> sp.s;
            cin >> sp.b;
            arr[i] = sp;
        }
        cout << maximum_pleasure(arr, n, a, b) << endl;
    }
}