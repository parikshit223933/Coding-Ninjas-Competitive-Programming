/* Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.
Input Format:
First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)
Output Format:
Print a single integer denoting the window number that Aahad will get ticket from.
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3. */



#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int*t=new int [n];
	for(int i=0; i<n; i++)
	{
		if((arr[i]-i)%n==0)
		{
			t[i]=(arr[i]-i)/n;
		}
        else if(arr[i]-i<0)
        {
            t[i]=0;
        }
		else
		{
			t[i]=((arr[i]-i)/n)+1;
		}
	}
	int *ans=new int [n];
	int minimum=9999999999;
	int minimum_index=-1;
	for(int i=0; i<n; i++)
	{
		ans[i]=i+t[i]*n;
		if(ans[i]<minimum)
		{
			minimum=ans[i];
			minimum_index=i;
		}
	}
	cout<<minimum_index+1;
	
}