/* Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5 */



#include<iostream>
#include<algorithm>
using namespace std;
struct structure
{
	int first_vertex;
	int second_vertex;
	int weight;
};

int get_parent(int current_vertex, int *parent)
{
	if (current_vertex == parent[current_vertex])
	{
		return current_vertex;
	}
	return get_parent(parent[current_vertex], parent);
}
structure* get_MST(structure* arr, int e, int v)
{
	structure* output = new structure[v - 1];
	int* parent = new int[v];
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	int count = 0, i = 0;
	while (count < v - 1 && i<e)
	{
		structure current_edge = arr[i];
		int first_vertex_parent = get_parent(current_edge.first_vertex, parent);
		int second_vertex_parent = get_parent(current_edge.second_vertex, parent);
		if (first_vertex_parent != second_vertex_parent)
		{
			output[count] = current_edge;
			count++;
			parent[first_vertex_parent] = second_vertex_parent;
		}
		i++;
	}
	return output;
}
bool sorter(structure a, structure b)
{
	if (a.weight < b.weight)
	{
		return true;
	}
	return false;
}
int main()
{
	int v, e;
	cin >> v >> e;
	structure* arr = new structure[e];
	for (int i = 0; i < e; i++)
	{
		cin >> arr[i].first_vertex >> arr[i].second_vertex >> arr[i].weight;
	}
	sort(arr, arr + e, sorter);
	structure* output = get_MST(arr, e, v);
	for (int i = 0; i < v - 1; i++)
	{
		if (output[i].first_vertex < output[i].second_vertex)
			cout << output[i].first_vertex << " " << output[i].second_vertex << " " << output[i].weight << endl;
		else
			cout << output[i].second_vertex << " " << output[i].first_vertex << " " << output[i].weight << endl;
	}
}