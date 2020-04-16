/* Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way. */





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