/* A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7 */





long staircase(int n, long *arr=new long[71]()){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    if(arr[n]>0)
    {
        return arr[n];
    }
    long steps_3=staircase(n-3, arr);
    long steps_2=staircase(n-2, arr);
    long step_1=staircase(n-1, arr);
    long ans=step_1+steps_2+steps_3;
    arr[n-1]=step_1;
    arr[n-2]=steps_2;
    arr[n-3]=steps_3;
    arr[n]=ans;
    return ans;
}
