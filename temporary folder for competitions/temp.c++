#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
void printer(int *arr, int n, int element)
{
    int temp = 0;
    while (arr[temp] != element && temp < n)
    {
        temp++;
    }
    int i = temp;
    int maximum_length = 0;
    while (i < n)
    {
        int j = i;
        while (arr[j] == element && j < n)
        {
            j++;
        }
        maximum_length = max(maximum_length, j - i);
        i = j;
        while (arr[i] != element && i < n)
        {
            i++;
        }
    }
    cout << maximum_length;
}
int main()
{
    fast int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "Heads")
        {
            arr[i] = 1;
        }
        else //tails
        {
            arr[i] = 0;
        }
        /* 0==tails, 1==heads */
    }
    printer(arr, n, 1);
    cout << " ";
    printer(arr, n, 0);
    cout << endl;
    return 0;
}