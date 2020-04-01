#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

map<int,int> returnPrimeFactors(long k)
{
    map<int,int> primeFactors;
    while(k % 2 == 0)
    {
        primeFactors[2]++;
        k /=2 ;
    }

    for(int i = 3; i <= sqrt(k) ; i++)
    {
        while(k % i == 0)
        {
            primeFactors[i]++;
            k /= i;
        } 
    }

    if(k > 2)
        primeFactors[k]++;
    
    return primeFactors;
}
long long countWaysK(vector<long> arr,long n,long k)
{
    map<int,int> primeFactorsK = returnPrimeFactors(k);
    map<int,int> primeFactorsA;
    vector<bool> visited(n);

    long i=0,j=0,s=0;
    long ans = 0;
    while(i<n && j<n)
    {
        // cout<<"\nj "<<j<<" i "<<i;
        int flag = 0;
        for(auto it:primeFactorsK)
        {
            int p = it.first;
            int count = 0;
            long val = arr[j];
            while(val % p == 0)
            {
                count++;
                val /= p;
            }
            if(!visited[j])
                primeFactorsA[p] += count;
            // cout<<"\nFact: "<<primeFactorsA[p]<<" "<<it.second;
            if(primeFactorsA[p] < it.second)
            {
                // cout<<"\nFlagged"<<arr[j];
                flag = 1;
            }
        }

        if(!flag)
        {
            // cout<<"\nNot Flag: "<<arr[j];
            ans += (n-j);
            s = i;
            visited[j] = true;
            // cout<<"\nAns: "<<ans;
            i++;
            int m = i-1;
            while(m >= s)
            {
                int flag = 0;
                for(auto it:primeFactorsK)
                {
                    int p = it.first;
                    int count = 0;
                    long val = arr[m];
                    while(val % p == 0)
                    {
                        count++;
                        val /= p;
                    }
                    primeFactorsA[p] -= count;
                    // cout<<"\nRem "<<arr[m]<<" "<<primeFactorsA[p]<<" "<<it.second;
                    if(primeFactorsA[p] < it.second)
                    {
                        flag = 1;
                    }
                }
                if(flag)
                    break;
                m--;
            }
        }
        else
            j++;
    }
    return ans;
}

int main()
{
    long n,k,i,j;
    cin >> n >> k;

    vector<long> arr(n);
    for(i = 0; i < n ; i++)
        cin >> arr[i];

    cout<<countWaysK(arr,n,k)<<endl;

}