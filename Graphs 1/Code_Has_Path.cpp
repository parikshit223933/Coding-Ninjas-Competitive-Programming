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