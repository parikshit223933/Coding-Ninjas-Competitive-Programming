#include<iostream>
#include<algorithm>
#define mod 1000000007
#define inf 1000000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 200005
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define ssf(n) scanf("%lf", &n)
#define mk make_pair
#define PLL pair<ll, ll>
#define gc getchar
#define pb push_back
using namespace std;
PII M[MAX], T[MAX];
int BIT[MAX], A[MAX], n;
char C[MAX];
bool b;
int get_count(int idx)
{
    if (idx == 0)
        return 0;
    ll sum = 0;
    while (idx > 0)
    {
        //printf("BIT: %d\n", BIT[idx]);
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void updateBIT(int idx, int val)
{
    while (idx < MAX)
    {
        //printf("%d ", idx);
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
int b_search(int x)
{
    int lo = 0, hi = n - 1, mid, ans = -1;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        //printf("M: %d %d..\n", mid, M[mid].f);
        if (M[mid].f == x)
        {
            b = 1;
            return mid;
        }
        else if (M[mid].f > x)
            hi = mid - 1;
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }
    b = 0;
    return ans;
}
int main()
{
    int i, Q, x, k = 0, lo, hi, mid;
    cin>>Q;
    for (i = 0; i < Q; i++)
    {
        C[i] = gc();
        while (C[i] < 65 || C[i] >= 91)
            C[i] = gc();
        cin>>A[i];
        if (C[i] == 'I')
        {
            T[k].f = A[i];
            T[k++].s = 0;
        }
    }
    sort(T, T + k);
    M[0] = T[0];
    n = 1;
    for (i = 1; i < k; i++)
    {
        if (T[i].f != T[i - 1].f)
        {
            M[n++] = T[i];
            // printf("%d\n", T[i].f);
        }
    }
    for (i = 0; i < Q; i++)
    {
        if (C[i] == 'I')
        {
            x = b_search(A[i]); //Find position in sorted array using binary search
            //printf("I: %d %d\n",A[i], x);
            if (M[x].s == 0)
            {
                M[x].s = 1;
                updateBIT(x + 1, 1); //! 1 based indexing
                //printf("I: %d ", BIT[x+1]);
            }
        }
        else if (C[i] == 'D')
        {
            x = b_search(A[i]);
            if (x != -1 && M[x].s == 1 && b)
            {
                updateBIT(x + 1, -1); //! 1 based indexing
                M[x].s = 0;
            }
        }
        else if (C[i] == 'C')
        {
            x = b_search(A[i]);
            //printf("C: %d\n", x);
            if (b)
                printf("%d\n", get_count(x + 1 - 1));
            else if (x != -1)
                printf("%d\n", get_count(x + 1));
            else
                printf("0\n");
        }
        else if (C[i] == 'K')
        {
            k = A[i];
            x = -1;
            bool mno = 0;
            lo = 1;
            hi = MAX - 1;
            while (lo <= hi)
            {
                mid = (lo + hi) >> 1;
                if (get_count(mid) == k && get_count(mid - 1) != k)
                {
                    mno = 1;
                    x = mid;
                    break;
                }
                else if (get_count(mid) < k) //! 1 based indexing
                {
                    x = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
            //printf("K: %d\n", x);
            if (!mno)
                printf("invalid\n");
            else
                printf("%d\n", M[x - 1].f);
        }
    }
    return 0;
}