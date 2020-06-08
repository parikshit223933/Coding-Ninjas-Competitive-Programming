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

int current_array_sum(int **arr, int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}

void ask_queries_and_fill_array(int **arr, int n)
{
    ask(0, 0, n-1, n-1);
    int sum_of_whole_array;
    cin>>sum_of_whole_array;
    if(sum_of_whole_array==0)
    {
        return;
    }
    else if(sum_of_whole_array==n*n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                arr[i][j]=1;
            }
        }
        return;
    }


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
    if(current_array_sum(arr, n)==sum_of_whole_array)
    {
        return;
    }

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
    if(current_array_sum(arr, n)==sum_of_whole_array)
    {
        return;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {

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

            if(current_array_sum(arr, n)==sum_of_whole_array)
            {
                return;
            }
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
        for(int i=0; i<n; i++)
        {
            arr[i]=new int [n];
            for(int j=0; j<n; j++)
            {
                arr[i][j]=0;
            }
        }
        ask_queries_and_fill_array(arr, n);

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