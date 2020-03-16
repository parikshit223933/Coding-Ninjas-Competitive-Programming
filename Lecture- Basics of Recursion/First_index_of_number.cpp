int firstIndex(int input[], int size, int x)
{
    if(size==0)
    {
        return -1;
    }

    if(input[0]==x)
    {
        return 0;
    }
    
    int small_index=firstIndex(input+1, size-1, x);
    if(small_index==-1)
    {
        small_index;
    }
    else
    {
        return small_index+1;
    }
}
