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
class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int number)
    {
        vector<int> ans;
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]].first++;
            map[arr[i]].second = i;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (map[number - arr[i]].first)
            {
                if(map[number-arr[i]].second==i)
                {
                    continue;
                }
                ans.push_back(i);
                ans.push_back(map[number - arr[i]].second);
                break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};