#include<iostream>
#include<climits>
using namespace std;
class trienode
{
public:
    trienode **children;
    int weight;
    trienode()
    {
        children = new trienode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        weight = 0;
    }
};
void insert(string s, int weight, trienode *root)
{
    if (s.length() == 0)
    {
        return;
    }
    trienode *current;
    //proceeding with recursion
    //taking the first bit(character) in consideration
    int index = s[0] - 'a';
    if (root->children[index] != NULL)
    {
        current = root->children[index];
    }
    else//if root->children[index] is null
    {
        current = new trienode();
        root->children[index] = current;
    }
    if (root->weight < weight)
    {
        root->weight = weight;
    }
    insert(s.substr(1), weight, current);
}
int search_best(string s, trienode *root)
{
    int best_weight=INT_MIN;
    int n=s.length();
    trienode*current=root;
    for(int i=0; i<n; i++)
    {
        int index=s[i]-'a';
        trienode*child=current->children[index];
        //if the child is not null we have to update the best weight with
        // current child's weight and move the current pointer to child.
        if(child!=NULL)
        {
            current=child;
            best_weight=child->weight;
        }
        else//if child is null
        {
            return -1;
        }
        
    }
    return best_weight;
}
int main()
{
    int n, q;
    cin>>n>>q;
    trienode*root=new trienode();
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(s, weight, root);
    }
    while(q--)
    {
        string s;
        cin>>s;
        cout<<search_best(s, root)<<endl;
    }
    return 0;
}