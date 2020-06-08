#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

int minimum_operations(int p, int q, int r, int a, int b, int c)
{
    int *src = new int[3];
    int *des = new int[3];
    int equal = 0;
    src[0] = p;
    src[1] = q;
    src[2] = r;
    des[0] = a;
    des[1] = b;
    des[2] = c;

    for (int i = 0; i < 3; i++)
    {
        if (src[i] == des[i])
        {
            equal++;
        }
    }

    if(equal==3)
    {
        return 0;
    }
    else if(equal==2)
    {
        return 1;
    }
    else if(equal==1)
    {
        if(p==a)
        {
            if(q-b==r-c)
            {
                return 1;
            }
            else if((q!=0&&r!=0)&&(b/q==c/r)&&(b%q==0&&c%r==0))
            {
                return 1;
            }
        }
        else if(q==b)
        {
            if(p-a==r-c)
            {
                return 1;
            }
            else if((p!=0&&r!=0)&&(a/p==c/r)&&(a%p==0&&c%r==0))
            {
                return 1;
            }
        }
        else if(r==c)
        {
            if(p-a==q-b)
            {
                return 1;
            }
            else if((q!=0&&p!=0)&&(b/q==a/p)&&(b%q==0&&a%p==0))
            {
                return 1;
            }
        }
        return 2;
    }
    else if(equal==0)
    {
        int diff1=a-p;
        int diff2=b-q;
        int diff3=c-r;
        int mod1=a%p;
        int mod2=b%q;
        int mod3=c%r;
        float quo1=(a*1.0)/(p*1.0);
        float quo2=(b*1.0)/(q*1.0);
        float quo3=(c*1.0)/(r*1.0);
        /* All cases when 1 operation is needed */
        if(diff1==diff2&&diff2==diff3)
        {
            return 1;
        }
        if(diff1!=diff2&&diff2==diff3)
        {
            return 2;
        }
        if(diff1==diff2&&diff2!=diff3)
        {
            return 2;
        }
        /* their differences are different */
        if(p!=0&&q!=0&&r!=0)
        {
            if(mod1==0&&mod2==0&&mod3==0)
            {
                if(quo1==quo2&&quo2==quo3)
                {
                    return 1;
                }
                if(quo1==quo2&&quo2!=quo3)
                {
                    return 2;
                }
                if(quo1!=quo2&&quo2==quo3)
                {
                    return 2;
                }
                return 3;
            }
            if(mod1!=0&&mod2==0&&mod3==0)
            {
                if(quo2==quo3)
                {
                    return 2;
                }
                return 3;
            }
            if(mod1==0&&mod2!=0&&mod3==0)
            {
                if(quo1==quo3)
                {
                    return 2;
                }
                return 3;
            }
            if(mod1==0&&mod2==0&&mod3!=0)
            {
                if(quo2==quo1)
                {
                    return 2;
                }
                return 3;
            }
            /////////////////////////////////////
            if(mod1!=0&&mod2!=0&&mod3==0)
            {
                if(mod1==mod2)
                {
                    if((a-mod1)/p==(b-mod2)/q&&(b-mod2)/q==quo3)
                    {
                        return 2;
                    }
                    return 3;
                }
                return 3;
            }
            if(mod1==0&&mod2!=0&&mod3!=0)
            {
                if(mod2==mod3)
                {
                    if((c-mod3)/r==(b-mod2)/q&&(b-mod2)/q==quo1)
                    {
                        return 2;
                    }
                    return 3;
                }
                return 3;
            }
            if(mod1!=0&&mod2==0&&mod3!=0)
            {
                if(mod1==mod3)
                {
                    if((a-mod1)/p==(c-mod3)/r&&(b-mod2)/q==quo2)
                    {
                        return 2;
                    }
                    return 3;
                }
                return 3;
            }
            return 3;
        }
        return 3;
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;
        int a, b, c;
        cin >> a >> b >> c;

        cout << minimum_operations(p, q, r, a, b, c) << endl;
    }
}