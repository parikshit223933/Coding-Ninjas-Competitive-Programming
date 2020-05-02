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

void GetAllSubstrings(string s, int n)  
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
            cout<<temp<<endl;
        }
        delete[]temp;
    } 
} 
int32_t main()
{
    GetAllSubstrings("ab", 2);
}