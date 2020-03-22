int turnOffIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n&(1<<i))
    {
        return (n&~(1<<i));
    }
    else
    {
        return n;
    }
}

