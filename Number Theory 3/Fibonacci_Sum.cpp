/* The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857 */



#include <iostream>
#define mod 1000000007
#define ll unsigned long long
using namespace std;
inline void multiply(ll mat1[2][2], ll mat2[2][2])
{
    ll new_mat[2][2] = {
        {(((mat1[0][0])%mod * (mat2[0][0])%mod)%mod + ((mat1[0][1])%mod * (mat2[1][0])%mod)%mod)%mod,
         (((mat1[0][0])%mod * (mat2[0][1])%mod)%mod + ((mat1[0][1])%mod * (mat2[1][1])%mod)%mod)%mod},
        {(((mat1[1][0])%mod * (mat2[0][0])%mod)%mod + ((mat1[1][1])%mod * (mat2[1][0])%mod)%mod)%mod,
         (((mat1[1][0])%mod * (mat2[0][1])%mod)%mod + ((mat1[1][1])%mod * (mat2[1][1])%mod)%mod)%mod}};
    mat1[0][0] = new_mat[0][0]%mod;
    mat1[0][1] = new_mat[0][1]%mod;
    mat1[1][0] = new_mat[1][0]%mod;
    mat1[1][1] = new_mat[1][1]%mod;
}
inline void power(ll mat[2][2], ll n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    power(mat, n / 2);
    multiply(mat, mat);
    if (n % 2 != 0)
    {
        ll temp[2][2] = {{1, 1}, {1, 0}};
        multiply(mat, temp);
    }
}
inline ll fib(ll n)
{
    ll mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }
    power(mat, n - 1);
    return mat[0][0]%mod;
}
inline unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    return (fib(n + 2)%mod - fib(m + 1)%mod+mod)%mod;
}

