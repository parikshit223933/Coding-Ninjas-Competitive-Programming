#include <iostream>
#include <string>
using namespace std;
void buildZ(int *z, string str, int n)
{
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            //i does not lie between l and r.
            //z for this does not exist
            l = i;
            r = i;
            while (r < n && str[r - l] == str[r])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] <= r - i)
            {
                //it lies between l and r
                //z will exits previously for this
                z[i] = z[k];
            }
            else
            {
                //some part of z is already included
                //you have to start matching further
                l = i;
                while (r < n && str[r - l] == str[r])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}
void searchString(string text, string pattern)
{
    string str = pattern + "$" + text;
    int n = str.length();
    int *z = new int[n];
    for (int i = 0; i < n; i++)
    {
        z[i] = 0;
    }
    buildZ(z, str, n);
    for (int i = 0; i < n; i++)
    {
        if (z[i] == pattern.length())
        {
            cout << i - pattern.length() - 1 << endl;
        }
    }
}
int main()
{
    string text = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    searchString(text, pattern);
    return 0;
}