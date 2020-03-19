#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
class trienode
{
public:
    trienode *left;
    trienode *right;
};
void insert(int n, trienode *head)
{
    trienode *current = head;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 0)
        {
            if (!current->left) //if the left of current node is not null
            {
                current->left = new trienode();
            }
            current = current->left;
        }
        else //if the bit is non-zero
        {
            if (!current->right)
            {
                current->right = new trienode();
            }
            current = current->right;
        }
    }
}
int find_max_xor_pair(trienode *head, int *arr, int n)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        trienode *current = head;
        int current_xor = 0;

        for (int j = 31; j >= 0; j--)
        {
            int bit = (arr[i] >> j) & 1;
            if (bit == 0)
            {
                if (!current->right) //right node does not exist
                {
                    current = current->left;
                }
                else //right node exists
                {
                    current_xor += pow(2, j);
                    current = current->right;
                }
            }
            else
            {
                if (!current->left) //left node does not exits
                {
                    current = current->right;
                }
                else //left node exists
                {
                    current_xor += pow(2, j);
                    current = current->left;
                }
            }
        }
        //now i have my current answer stored in current_xor.
        //i have to compare it with max_xor.
        if (max_xor < current_xor)
        {
            max_xor = current_xor;
        }
    }
    return max_xor;
}
int main()
{
    int arr[] = {8, 1, 2, 15, 10, 5};
    trienode *head = new trienode();
    for (int i = 0; i < 6; i++)
    {
        insert(arr[i], head);
    }
    cout << find_max_xor_pair(head, arr, 6) << endl;
    return 0;
}