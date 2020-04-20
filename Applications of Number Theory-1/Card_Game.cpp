/* Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
Input
The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.
Output
Print the number of ways to choose x and y so the resulting deck is valid.
Sample Input 1
3 4
6 2 8
Sample Output 1
4
Sample Input 2
3 6
9 1 14
Sample Output 2
1 */




#include<iostream>
#include<utility>
#include<vector>
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
int main()
{
    int n, i, j;
    ll k, temp_for_k, ans = 0;
    cin >> n >> k;
    temp_for_k = k;
    vector<ll> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<PII> vp; //store prime factors of k with respective powers
    for (i = 2; i * i <= temp_for_k; i++)
    {
        if (temp_for_k % i == 0)
        {
            int count = 0;
            while (temp_for_k % i == 0)
            {
                temp_for_k /= i;
                count++;
            }
            vp.push_back(make_pair(i, count));
        }
    }
    if (temp_for_k != 1)
    {
        vp.push_back(make_pair(temp_for_k, 1));
    }
    //vq contains all prime factors of k with their respective powers 0
    vector<PII> vq = vp;
    for (i = 0; i < vq.size(); i++)
    {
        vq[i].s = 0;
    }
    //j is back pointer and i is front pointer
    //We are checking if j..i is divisible by k by adding prime factors of a[i] to vq
    //If it is divisible, then j...z for all z > i is also divisible by k
    //So we add n-i to answer
    //Then we remove j's contribution by subtracting it's prime factors from vq
    j = 0;
    for (i = 0; i < n; i++)
    {
        //add factors of a[i]
        for (int z = 0; z < vp.size(); z++)
        {
            if (a[i] % vp[z].f == 0)
            {
                temp_for_k = a[i];
                int cn = 0;
                while (temp_for_k % vp[z].f == 0)
                {
                    temp_for_k /= vp[z].f;
                    cn++;
                }
                vq[z].s += cn;
            }
        }
        while (j <= i)
        {
            int z;
            //check if divisible by k from j to i
            for (z = 0; z < vp.size(); z++)
            {
                if (vp[z].s > vq[z].s)
                    break;
            }
            if (z != vp.size())
                break;
            //if divisible update ans
            ans += n - i;
            //remove factors of a[j] from vq
            for (int z = 0; z < vp.size(); z++)
            {
                if (a[j] % vp[z].f == 0)
                {
                    temp_for_k = a[j];
                    int cn = 0;
                    while (temp_for_k % vp[z].f == 0)
                    {
                        temp_for_k /= vp[z].f;
                        cn++;
                    }
                    vq[z].s -= cn;
                }
            }
            j++;
        }
    }
    cout << ans;
}