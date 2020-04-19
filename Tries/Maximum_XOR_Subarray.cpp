/* Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7 */



#include <iostream>
#include <algorithm>
using namespace std;
struct trie
{
    int cnt;
    trie *children[2];
    //left denotes 0
    //right denotes 1
    trie() //contructor
    {
        cnt = 0;
        children[0] = NULL;
        children[1] = NULL;
    }
};
void insert_trie(int val, trie *root)
{
    trie *node = root, *newNode, temp;
    int i = 0;
    for (i = 31; i >= 0; i--)
    {
        bool k = (1 << i) & val; //k is set if ith position is set in val
        // cout<<k;
        if (node->children[k] == NULL)
        {
            newNode = new trie;
            newNode->cnt = 1;
            node->children[k] = newNode;
        }
        else
            (node->children[k]->cnt)++;
        node = node->children[k];
    }
    //cout<<"\n";
}
int query(int val, trie *root)
{
    int ans = 0;
    trie *node = root;
    if (root == NULL)
        return 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit=(val>>i)&1;
        
        if (node->children[1 - bit] != NULL)
        {
            node = node->children[1 - bit];
            ans = ans * 2 + 1;
        }
        else
        {
            node = node->children[bit];
            ans *= 2;
        }
    }
    return ans;
}
int main()
{
    int n, xor_till_i;
    int ans = 0;
    cin >> n;
    int *arr = new int[n];
    trie *root = new trie;
    xor_till_i = 0;
    insert_trie(xor_till_i, root);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        xor_till_i ^= arr[i];
        ans = max(ans, query(xor_till_i, root));
        insert_trie(xor_till_i, root);
    }
    cout << ans << endl;
}