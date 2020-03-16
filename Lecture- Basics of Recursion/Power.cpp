int power(int x, int n) 
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }
    int small_output=power(x, n-1);
    return x*small_output;
}
