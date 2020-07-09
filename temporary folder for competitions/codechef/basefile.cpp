#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
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

struct point{
	int x;
	int y;
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int new_n=4*n-1;
		point *arr=new point[new_n];
		for(int i=0; i<new_n; i++)
		{
			cin>>arr[i].x>>arr[i].y;
		} 
	}
}