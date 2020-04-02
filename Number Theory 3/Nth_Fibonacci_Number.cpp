#include <iostream>
using namespace std;
inline void multiply(int mat1[2][2], int mat2[2][2])
{
    int new_mat[2][2] = {
        {(mat1[0][0] * mat2[0][0]) + (mat1[0][1] * mat2[1][0]),
         (mat1[0][0] * mat2[0][1]) + (mat1[0][1] * mat2[1][1])},
          {(mat1[1][0] * mat2[0][0]) + (mat1[1][1] * mat2[1][0]),
           (mat1[1][0] * mat2[0][1]) + (mat1[1][1] * mat2[1][1])}};
    mat1[0][0]=new_mat[0][0];
    mat1[0][1]=new_mat[0][1];
    mat1[1][0]=new_mat[1][0];
    mat1[1][1]=new_mat[1][1];
}
inline void power(int mat[2][2], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    power(mat, n / 2);
    multiply(mat, mat);
    if (n % 2 != 0)
    {
        int temp[2][2] = {{1, 1}, {1, 0}};
        multiply(mat, temp);
    }
}
int fib(int n)
{
    int mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }
    power(mat, n - 1);
    return mat[0][0];
}
int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n==0)
        {
            return 0;
        }
        cout << fib(n) << endl;
    }
    
    return 0;
}