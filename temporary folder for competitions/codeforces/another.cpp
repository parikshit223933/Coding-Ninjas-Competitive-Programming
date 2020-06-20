#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include<cstring>
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

int findMaxGCD(int n) 
{ 
	int high = n; 

	int count[high + 1] = {0}; 
    fill_n(count, high +1, 1);

	int counter = 0; 

	for (int i = high; i >= 1; i--) 
	{ 
		int j = i; 
	    counter = 0; 
	
		while (j <= high) 
		{ 

			if(count[j] >=2) 
			return j; 

		else if (count[j] == 1)		 
				counter++;		 

			j += i; 

			if (counter == 2)		 
				return i; 
		} 
	} 
} 

int main() 
{ 
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
	    cout << findMaxGCD(n)<<endl; 
    }

	return 0; 
} 