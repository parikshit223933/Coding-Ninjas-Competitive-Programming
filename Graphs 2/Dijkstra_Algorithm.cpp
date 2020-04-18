/* Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5 */



#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
void algo(int** arr, int v, int e, bool* visited, int* dist, int current_vertex)
{
	for (int i = 0; i < v - 1; i++)
	{
		int vertex_with_minimum_distance=-1;
		int min_distance = INT_MAX;
		for (int j = 0; j < v; j++)
		{
			if (!visited[j] && min_distance > dist[j])
			{
				min_distance = dist[j];
				vertex_with_minimum_distance = j;
			}
		}

		visited[vertex_with_minimum_distance] = true;
		for (int j = 0; j < v; j++)
		{
			if (!visited[j] && dist[j] > dist[vertex_with_minimum_distance] + arr[vertex_with_minimum_distance][j] && arr[vertex_with_minimum_distance][j] > 0)
			{
				dist[j] = dist[vertex_with_minimum_distance] + arr[vertex_with_minimum_distance][j];
			}
		}
	}
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int*[v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		arr[v1][v2] = w;
		arr[v2][v1] = w;
	}
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	int* dist = new int[v];
	for (int i = 0; i < v; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[0] = 0;
	algo(arr, v, e, visited, dist, 0);
	for (int i = 0; i < v; i++)
	{
		cout << i << " " << dist[i] << endl;
	}
}