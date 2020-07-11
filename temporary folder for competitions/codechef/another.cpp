#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;
int32_t main()
{
    fast;
    int n, q;
    cin >> n >> q;
    int* height = new int[n];
    int* tastiness = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tastiness[i];
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, value;
            cin >> index >> value;
            tastiness[index - 1] = value;
        }
        else
        {
            int start, end;
            cin >> start >> end;
            start--;
            end--;
            if (start == end)
            {
                cout << tastiness[start] << endl;
                continue;
            }
            if (start < end)
            {
                bool check = false;
                int current_tastiness = tastiness[end];
                int current_height = height[end];
                int total_tastiness = tastiness[end];

                for (int i = end; i >= start; i--)
                {
                    if (current_height < height[i])
                    {
                        if (i == start)
                        {
                            check = true;
                        }
                        current_height = height[i];
                        current_tastiness = tastiness[i];
                        total_tastiness += tastiness[i];
                    }
                }
                if (!check)
                {
                    cout << -1 << endl;
                    continue;
                }
                cout << total_tastiness << endl;
                continue;
            }
            else
            {
                int temp = start;
                start = end;
                end = temp;

                bool check = false;
                int current_tastiness = tastiness[start];
                int current_height = height[start];
                int total_tastiness = tastiness[start];

                for (int i = start; i <= end; i++)
                {
                    if (current_height < height[i])
                    {
                        if (i == end)
                        {
                            check = true;
                        }
                        current_height = height[i];
                        current_tastiness = tastiness[i];
                        total_tastiness += tastiness[i];
                    }
                }
                if (!check)
                {
                    cout << -1 << endl;
                    continue;
                }
                cout << total_tastiness << endl;
                continue;
            }
        }
    }
}