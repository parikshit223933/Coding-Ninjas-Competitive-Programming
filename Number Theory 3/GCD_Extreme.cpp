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