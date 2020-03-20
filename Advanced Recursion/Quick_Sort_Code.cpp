#include<iostream>
using namespace std;
int partition(int *arr, int start, int end)
{
	int pivot=arr[start];
	int count=0;
	for(int i=start+1; i<=end; i++)
	{
		if(arr[i]<=pivot)
		{
			count+=1;
		}
	}
	int pivotindex=start+count;
	int temp=arr[start];
	arr[start]=arr[pivotindex];
	arr[pivotindex]=temp;
	
	int i=start, j=end;
	while(i<=pivotindex&&j>=pivotindex)
	{
		while(arr[i]<=pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<pivotindex && j>pivotindex)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}
	return pivotindex;
}
void quickSort(int *arr, int start, int end)
{
	if(start>=end)
	{
		return;
	}
	int c=partition(arr, start, end);
	quickSort(arr, start, c-1);
	quickSort(arr, c+1, end);
}
void quickSort(int *arr, int n)
{
	quickSort(arr, 0, n-1);
}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


