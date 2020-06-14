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
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        unordered_map<vector<int>, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        vector<int> temp;
                        temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        if (m[temp] > 0)
                        {
                            continue;
                        }
                        else
                        {
                            ans.push_back(temp);
                            m[temp]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};