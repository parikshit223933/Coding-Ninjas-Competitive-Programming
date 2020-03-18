// arr - input array
// size - size of array
// d - array to be rotated by d elements
void rotator(int *arr, int n)
{
    for(int i=0, j=n-1; i<=j; i++, j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
void Rotate(int arr[], int d, int n)
{
    rotator(arr, n);
    rotator(arr+n-d, d);
    rotator(arr, n-d);
}	
