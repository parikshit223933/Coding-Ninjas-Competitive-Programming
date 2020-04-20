/* Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2 */


#include<iostream>
#include<math.h>
using namespace std;
bool check_prime(int n)
{
    int count_factors = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                count_factors += 1;
            }
            else
                count_factors += 2;
        }
    }
    return count_factors == 2;

}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    bool* isprime = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        isprime[i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isprime[i])
        {
            if (check_prime(i))
            {
                count += 1;
                int temp = i;
                while (temp * i <= n)
                {
                    isprime[temp * i] = false;
                    temp++;
                }
            }
        }

    }
    delete[]isprime;
    cout << count << endl;
    return 0;
}