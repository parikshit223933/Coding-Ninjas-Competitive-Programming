/* You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8 */



int turnOffFirstSetBit(int n)
{
    if(n==0)
    {
        return 0;
    }
    int i;
    while((n&(1<<i))==0)
    {
        i++;
    }
    return n^(1<<i);
}

