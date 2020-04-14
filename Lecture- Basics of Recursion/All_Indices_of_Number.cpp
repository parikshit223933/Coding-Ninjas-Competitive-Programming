/* Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4 */
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
