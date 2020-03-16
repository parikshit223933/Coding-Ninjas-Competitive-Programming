bool checkNumber(int input[], int size, int x)
{
    if(size==0)
    {
        return false;
    }
    bool small_check=checkNumber(input+1, size-1, x);
    if(input[0]==x)
    {
        return true;
    }
    else
    {
        return small_check;
    }
}
