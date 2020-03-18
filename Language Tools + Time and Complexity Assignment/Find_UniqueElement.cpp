
#include<map>
using namespace std;
int FindUnique(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    map<int, int> m;
    for(int i=0; i<n; i++)
    {
        m[arr[i]]+=1;
    }
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        if(it->second==1)
        {
            return it->first;
        }
    }
}