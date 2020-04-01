#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> prime_divisors(int n)
{
    vector<int> v;
    int x = n;
    for (int i = 2; x != 1; i++)
    {
        if (x % i == 0)
        {
            v.push_back(i);
            while (x % i == 0)
            {
                x = x / i;
            }
        }
    }
    if (v.empty())
    {
        v.push_back(n);
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    bool *marked = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = i;
        marked[i] = false;
    }

    for (int i = n; i >= 1; i--)
    {
        if (marked[i])
        {
            continue;
        }
        vector<int> partial_answer;
        int current_maximum_number = arr[i];
        vector<int> prime_divisors_of_maximum_number = prime_divisors(current_maximum_number);
        for (int indexer = 0; indexer < prime_divisors_of_maximum_number.size(); indexer++)
        {
            int current_prime_divisor = prime_divisors_of_maximum_number[indexer];
            for (int j = current_maximum_number; j >= 1; j -= current_prime_divisor)
            {
                if (!marked[j])
                    partial_answer.push_back(j);
                marked[j] = true;
            }
        }

        sort(partial_answer.begin(), partial_answer.end(), greater<int>());
        for (int itr = 0; itr < partial_answer.size(); itr++)
        {
            cout << partial_answer[itr] << " ";
        }
    }
}