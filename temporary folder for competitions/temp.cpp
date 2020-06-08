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

/* void ask_questions(int start, int end)
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
} */

bool accept_odd_questions(int &start, int &end)
{
    int mid=(start+end)/2;
    ask(mid);
    char x;
    cin>>x;

    if(start>end)
    {
        return false;
    }

    if(x=='L')
    {
        end=mid-1;
        return false;
    }
    else if(x=='G')
    {
        start=mid+1;
        return false;
    }
    else if(x=='E')
    {
        return true;
    }
}

bool accept_even_questions(int &start, int &end)
{
    int mid=(start+end)/2;
    ask(mid);
    char x;
    cin>>x;
    if(x=='L')
    {
        end=mid-1;
        return false;
    }
    else if(x=='G')
    {
        start=mid+1;
        return false;
    }
    else if(x=='E')
    {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    int end_even=n;
    int end_odd=n;
    int start_even=1;
    int start_odd=1;
    for(int i=0; i<150; i++)
    {
        if(accept_odd_questions(start_odd, end_odd))
        {
            return 0;
        }
        if(accept_even_questions(start_even, end_even))
        {
            return 0;
        }
    }

    /* ask_questions(1, n); */
    return 0;
}