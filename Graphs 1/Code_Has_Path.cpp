/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false */



#include<iostream>
using namespace std;
bool haspath(int** arr, int v, bool* visited, int current_vertex, int v2)
{
	if (current_vertex == v2)
	{
		return true;
	}
	for (int i = 0; i < v; i++)
	{
		if (!visited[i] && i != current_vertex && arr[current_vertex][i]==1)
		{
			visited[i] = true;
			if (haspath(arr, v, visited, i, v2))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int v1, v2;
	cin >> v1 >> v2;
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = 0;
	}
	visited[v1] = true;
	if (haspath(arr, v, visited, v1, v2))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
}