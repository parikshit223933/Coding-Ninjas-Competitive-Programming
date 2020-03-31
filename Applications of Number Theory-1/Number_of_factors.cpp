#include <iostream>
using namespace std;
#include <iostream>
#include <math.h>
using namespace std;
void makeSieve(int *isprime, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        isprime[i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i] == 0)
            for (int j = 1; j * i <= n; j++)
            {
                isprime[j * i] += 1;
            }
    }
}
int main()
{
    int t;
    cin >> t;
    int *arr = new int[1000001];
    int **table=new int* [11];
    for(int i=0; i<11; i++)
    {
        table[i]=new int[10000001];
    }
    makeSieve(arr, 1000001);
    for(int i=0; i<11; i++)
    {
        table[i][0]=0;
        table[i][1]=0;
        for(int j=2; j<1000001; j++)
        {
            if(i==arr[j])
            {
                table[i][j]=table[i][j-1]+1;
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    }
    for (int test_case = 1; test_case <= t; test_case++)
    {
        int a, b, n;
        cin>>a>>b>>n;
        cout<<table[n][b]-table[n][a-1]<<endl;
    }
}