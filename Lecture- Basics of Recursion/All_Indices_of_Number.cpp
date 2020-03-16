
int allIndexes(int input[], int size, int x, int output[])
{
    if(size==0)
    {
        return 0;
    }
    int size_of_output=allIndexes(input+1, size-1, x, output);
    for(int i=0; i<size_of_output; i++)
    {
        output[i]+=1;
    }
    if(input[0]==x&&size_of_output!=0)
    {
        for(int i=size_of_output-1; i>=0; i--)
        {
            output[i+1]=output[i];//shifting
        }
        output[0]=0;
        return size_of_output+1;
    }
    else if(input[0]==x&&size_of_output==0)
    {
        output[0]=0;
        return 1;
    }
    else if(input[0]!=x&&size_of_output==0)
    {
        return 0;
    }
    else if(input[0]!=x&&size_of_output!=0)
    {
        return size_of_output;
    }
    
}
