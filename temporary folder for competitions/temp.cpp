#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
void print(int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void ask(int r1, int c1, int r2, int c2)
{
    cout << 1 << " " << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << endl;
}
void ask_queries_and_fill_array(int **arr, int n)
{
    /* filling first row optimally */
    int r1, c1, r2, c2;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        r1=0;
        r2=0;
        c1=0;
        c2=i;
        ask(r1, c1, r2, c2);
        int x;
        cin>>x;
        arr[0][i]=x-sum;
        sum=x;
    }
    /* filling first column optimally */
    sum=arr[0][0];
    for(int i=1; i<n; i++)
    {
        c1=0;
        c2=0;
        r1=0;
        r2=i;
        ask(r1, c1, r2, c2);
        int x;
        cin>>x;
        arr[i][0]=x-sum;
        sum=x;
    }
    /* filling the remaining part of the matrix */
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            /* calculating the sum */
            sum=0;
            for(int x=0; x<=i; x++)
            {
                for(int y=0; y<=j; y++)
                {
                    if(x==i&&y==j)
                    {
                        break;
                    }
                    sum+=arr[x][y];
                }
            }
            r1=0;
            c1=0;
            r2=i;
            c2=j;
            ask(r1, c1, r2, c2);
            int x;
            cin>>x;
            arr[i][j]=x-sum;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        int** arr = new int* [n];
        /* asking queries */
        /* dont forget to add 1 while asking for queries */
        for(int i=0; i<n; i++)
        {
            arr[i]=new int [n];
        }
        ask_queries_and_fill_array(arr, n);

        /* for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                int r1 = i;
                int c1 = j;
                int r2 = i;
                int c2 = j;
                cout << 1 << " " << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << endl;
                int x;
                cin >> x;
                arr[i][j] = x;
            }
        } */

        cout << 2 << endl;
        print(arr, n);
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}