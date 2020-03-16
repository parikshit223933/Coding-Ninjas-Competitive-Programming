int sum(int input[], int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return input[0];
    }
    int small_sum=sum(input+1, n-1);
    return input[0]+small_sum;
}
