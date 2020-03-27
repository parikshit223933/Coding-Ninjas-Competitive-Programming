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