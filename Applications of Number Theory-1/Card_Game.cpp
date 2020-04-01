#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> vector_givver(int n)
{
    vector<pair<int, int>> v;
    for (int i = 2; i * i < n; i++)
    {
        if (n == 1)
        {
            break;
        }
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count += 1;
            }
            v.push_back(make_pair(i, count));
        }
    }
    if(v.size()==0)
    {
        v.push_back(make_pair(n, 1));
    }
    return v;
}
int number_of_ways(int *arr, int n, int k)
{
    vector<pair<int, int>> pair_vector_k = vector_givver(k);
    vector<pair<int, int>> pair_vector_temp;
    for (int i = 0; i < pair_vector_k.size(); i++)
    {
        pair_vector_temp.push_back(make_pair(pair_vector_k[i].first, 0));
    }
    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int current_number = arr[i];
        for (int p = 0; p < pair_vector_temp.size(); p++)
        {
            if (current_number == 1)
            {
                break;
            }
            int to_be_divided_by = pair_vector_temp[p].first;
            while (current_number % to_be_divided_by == 0)
            {
                pair_vector_temp[p].second++;
                current_number /= to_be_divided_by;
            }
        }
        bool checker = true;
        for (int p = 0; p < pair_vector_temp.size(); p++)
        {
            if (pair_vector_temp[p].second < pair_vector_k[p].second)
            {
                checker = false;
                break;
            }
        }
        if (checker)
        {
            count += n - i;
            int element_whose_factors_are_to_be_removed = arr[j];
            j++;
            for (int p = 0; p < pair_vector_temp.size(); p++)
            {
                if (element_whose_factors_are_to_be_removed == 1)
                {
                    break;
                }
                int to_be_divided_by = pair_vector_temp[p].first;
                while (element_whose_factors_are_to_be_removed % to_be_divided_by == 0)
                {
                    pair_vector_temp[p].second--;
                    element_whose_factors_are_to_be_removed /= to_be_divided_by;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return count;
}
int main()
{
    int n, k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << number_of_ways(arr, n, k) << endl;
}