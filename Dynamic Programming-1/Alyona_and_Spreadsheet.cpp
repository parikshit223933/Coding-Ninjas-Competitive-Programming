/* During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No */




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