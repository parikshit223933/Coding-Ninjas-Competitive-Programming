#include <iostream>
using namespace std;
int size_of_sieve = 750001;
void Seive(int *arr, int n)
{
    int *sieve = new int[size_of_sieve];
    for (int i = 0; i < size_of_sieve; i++)
    {
        sieve[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        sieve[arr[i]] = 1;
    }
    for (int i = 1; i < size_of_sieve; i++)
    {
        int current_element = i;
        if (sieve[current_element] !=0)
            for (int j = 2; j * current_element < size_of_sieve; j++)
            {
                if (sieve[j * current_element] != 0)
                {
                    sieve[j * current_element] += sieve[i];
                }
            }
    }
    int total_sum = 0;
    for (int i = 0; i < size_of_sieve; i++)
    {
        total_sum += sieve[i];
    }
    cout << total_sum << endl;
    delete[] sieve;
}
int main()
{
    int t;
    cin >> t;
    int *arr = new int[750001];
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Seive(arr, n);
    }
    delete[] arr;
}