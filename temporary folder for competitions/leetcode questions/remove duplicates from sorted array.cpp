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
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size()==0)
        {
            return 0;
        }
        int new_length=1;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]==arr[i-1])
            {
                continue;
            }
            else
            {
                arr[new_length]=arr[i];
                new_length++;
            }
            
        }
        return new_length;
    }
};