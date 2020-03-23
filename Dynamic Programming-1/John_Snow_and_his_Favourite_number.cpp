#include <iostream>
using namespace std;
#define size 1024
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr[element] += 1;
    }
    int *temp = new int[size];

    while (k--)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            temp[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            int even, odd;
            if (sum % 2 == 0)
            {
                odd = (arr[i] + 1) / 2;
                even = arr[i] - odd;
            }
            else
            {
                odd = arr[i] / 2;
                even = arr[i] - odd;
            }
            temp[i] += even;
            temp[x ^ i] += odd;
            sum += arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (temp[i] > 0)
        {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (temp[i] > 0)
        {
            cout << i;
            break;
        }
    }
    delete[] temp;
    delete[] arr;
}