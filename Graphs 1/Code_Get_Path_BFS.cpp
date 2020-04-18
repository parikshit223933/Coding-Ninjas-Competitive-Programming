/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 : */



#include<iostream>
#include<queue>
#include<map>
using namespace std;
void printbfs(int** arr, int v, int current_element, int v2, bool*visited)
{
	queue<int>q;
	visited[current_element] = true;
	q.push(current_element);
	map<int, int>m;
	while (!q.empty())
	{
		int current = q.front();
		if (current == v2)
		{
			break;
		}
		for (int i = 0; i < v; i++)
		{
			if (!visited[i] && arr[current][i] == 1 && i !=current)
			{
				q.push(i);
				visited[i] = true;
				m[i] = current;
			}
		}
		q.pop();
		if (q.empty())
		{
			return;
		}
	}
	int i = v2;
	cout << v2<<" ";
	while (i!=current_element)
	{
		cout << m[i]<<" ";
		i = m[i];
	}
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
		visited[i] = false;
	}
	printbfs(arr, v, v1, v2, visited);
}