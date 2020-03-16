int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size==0)
    {
        return -1;
    }
    int index_from_remaining_array=lastIndex(input+1, size-1, x);
    if(input[0]==x&&index_from_remaining_array!=-1)
    {
        return index_from_remaining_array+1;
    }
    else if(input[0]==x&&index_from_remaining_array==-1)
    {
        return 0;
    }
    else if(input[0]!=x)
    {
        if(index_from_remaining_array==-1)
        {
            return -1;
        }
        else
        {
            return index_from_remaining_array+1;
        }
    }

}
