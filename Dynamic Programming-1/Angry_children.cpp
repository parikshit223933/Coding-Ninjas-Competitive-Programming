#include <iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll n, k;
    cin >> n >> k;

    ll *arr = new ll[n];
    for(ll i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

    sort(arr, arr+n);


    ll *sum = new ll[n];
    sum[0] = arr[0];
    for(int i = 1; i < n; i++)
	{
		sum[i] = sum[i-1]+arr[i];
	}
// i have to make this cumulative sum array because k can range from 0 to 10^5, so using two loops will give TLE.
    ll minUnfairness = 0;
    int start = 0;
    int end = k-1;
    for(int a = 1; a <= end; a++){
        minUnfairness += a*arr[a]-sum[a-1];
    }

    ll currUnfairness = minUnfairness;
    start++; end++;
    while(end < n){
        currUnfairness += (end-start)*arr[end]-sum[end-1]+sum[start-1];
        currUnfairness -= sum[end-1]-sum[start-1]-(end-start)*arr[start-1];
        minUnfairness=min(minUnfairness, currUnfairness);
        start++;
        end++;
    }

    cout << minUnfairness << endl;
}