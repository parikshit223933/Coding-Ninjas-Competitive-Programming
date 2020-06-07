#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
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

void ask(int y)
{
    cout << y << endl;
}

void ask_questions(int start, int end)
{
    int mid = (start + end) / 2;
    int count_L = 0;
    int count_G = 0;

    while (count_L == count_G)
    {
        for (int i = 0; i < 2; i++)
        {
            ask(mid);
            char x;
            cin >> x;
            if (x == 'G')
                count_G++;
            else if (x == 'L')
                count_L++;
            else
                return;
        }
    }

    if (count_L > count_G)
        ask_questions(1, mid);
    else if (count_L < count_G)
    {
        if (end - mid == 1)
        {
            mid = end;
        }
        ask_questions(mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    ask_questions(1, n);
    return 0;
}