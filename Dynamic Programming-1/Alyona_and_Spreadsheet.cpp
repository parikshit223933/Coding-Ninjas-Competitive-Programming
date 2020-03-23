#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minimum_element(int *arr, int n)
{
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minimum = min(minimum, arr[i]);
    }
    return minimum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *first_row = new int[m];
    int *second_row = new int[m];

    int *first_dp = new int[m];
    int *second_dp = new int[m];

    int *minimum_row_entry = new int[n];

    for (int i = 0; i < m; i++)
    {
        cin >> first_row[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> second_row[i];
    }

    for (int i = 0; i < m; i++)
    {
        first_dp[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (second_row[i] >= first_row[i])
        {
            second_dp[i] = 0;
        }
        else
        {
            second_dp[i] = 1;
        }
    }
    minimum_row_entry[0] = minimum_element(first_dp, m);
    minimum_row_entry[1] = minimum_element(second_dp, m);

    for (int i = 2; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            first_dp[i] = second_dp[i];
        }

        for (int j = 0; j < m; j++)
        {
            first_row[j] = second_row[j];
        }

        for (int j = 0; j < m; j++)
        {
            cin >> second_row[j];
        }
        //Now I have my first and second rows ready.
        for (int j = 0; j < m; j++)
        {
            if (first_row[j] <= second_row[j])
            {
                second_dp[j] = first_dp[j];
            }
            else
            {
                second_dp[j] = i;
            }
        }
        minimum_row_entry[i] = minimum_element(second_dp, m);
    }

    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        if (minimum_row_entry[r - 1] < l)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}