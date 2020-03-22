int clearAllBits(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int mask_initiator=(1<<(i));
    mask_initiator=mask_initiator-1;
    int mask=mask_initiator;
    return (mask&n);
}

