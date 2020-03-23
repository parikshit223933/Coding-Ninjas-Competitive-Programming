#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct queries
{
    char type;
    int element;
};

int main()
{
    int q;
    cin >> q;
    queries *query = new queries[q];
    int inserted_elements_size = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].type >> query[i].element;
        if (query[i].type == 'I')
        {
            inserted_elements_size++;
        }
    }
    int *inserted_elements = new int[inserted_elements_size];
    int inserted_elements_iterative_index = 0;
    for (int i = 0; i < q; i++)
    {
        if (query[i].type == 'I')
        {
            inserted_elements[inserted_elements_iterative_index] = query[i].element;
            inserted_elements_iterative_index++;
        }
    }
    sort(inserted_elements, inserted_elements + inserted_elements_size);
    map<int, int> compressor_map;
    int map_indexer = 1;
    for (int i = 0; i < inserted_elements_size; i++)
    {
        if (compressor_map[inserted_elements[i]] == 0)
        {
            compressor_map[inserted_elements[i]] = map_indexer;
        }
        map_indexer++;
    }
    for(int i=0; i<q; i++)
    {
        if(query[i].type=='I')
        {
            if(query_function(m[query[i].element])==query_function(m[query[i].element]-1))
            {
                update(m[query[i].element]);
            }
        }
        else if(query[i].type=='D')
        {
            if(query_function(m[query[i].element])!=query_fucntion(m[query[i].element]-1))
            {
                update(m[query[i].element]);
            }
        }
        else if(query[i].type=='K')
        {
            if(query(m[query[i].element])==k)
            {
                cout<<query[i].element<<endl;
            }
        }
        else if(query[i].type=='C')
        {
            
        }
        
    }
}