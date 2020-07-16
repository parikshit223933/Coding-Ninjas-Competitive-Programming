#include <iostream>
#include<limits.h>
#include<map>
using namespace std;
void solve(int one[], int two[], int k)
{
    // Hint: keys are one's indices, values are two's indices
    map<int, int>idxMap;

    for (int i = 0; i < k; i++)
    {
        int min = 1000000;
        int oneIdx = -1;
        int twoIdx = -1;

        for (int j = 0; j < 3; j++)
        {
            if (idxMap[j] == 3)
            {
                continue;
            }
            if (one[j] + two[idxMap[j]] < min)
            {
                min = one[j] + two[idxMap[j]];
                oneIdx = j;
                twoIdx = idxMap[j];
            }
        }

        idxMap[oneIdx]++;
        cout << (one[oneIdx] + " " + two[twoIdx]);
        cout << (", ");
    }
}

int main()
{
    int one[] = {1, 7, 11};
    int two[] = {2, 4, 6};
    int k = 3;
    solve(one, two, k);
}