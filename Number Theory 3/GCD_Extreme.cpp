/* Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input
The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.
Output
For each line of input produce one line of output. This line contains the value of G for the corresponding N. The value of G will fit in a 64-bit signed integer.
Sample Input:
10
100
200000
0
Sample Output:
67
13015
143295493160 */



#include <iostream>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
#define int long long int
#define MAX 1000001
using namespace std;
int phi[MAX];
unsigned int S[MAX], G[MAX];
int32_t main()
{
    fast unsigned int i, j, n;
    phi[1] = 1;
    for (i = 2; i < MAX; i += 2)
    {
        phi[i] = i / 2;
    }
    for (i = 3; i < MAX; i += 2)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            for (j = i << 1; j < MAX; j += i)
            {
                if (!phi[j])
                {
                    phi[j] = j;
                }

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for (i = 0; i < MAX; i++)
        S[i] = phi[i];
    for (i = 2; i < MAX; i++)
    {
        for (j = 2; j * i < MAX; j++)
        {
            S[i * j] += j * phi[i];
        }
    }
    G[1] = 0;
    for (i = 2; i < MAX; i++)
        G[i] = G[i - 1] + S[i];
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << G[n] << endl;
    }
}