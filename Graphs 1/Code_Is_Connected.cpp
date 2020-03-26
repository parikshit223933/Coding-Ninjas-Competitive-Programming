#include<iostream>
#include<queue>
#include<map>
using namespace std;
void visited_filler(int** arr, int v, int current_element, bool* visited)
{
	queue<int>q;
	visited[current_element] = true;
	q.push(current_element);
	while (!q.empty())
	{
		int current = q.front();
		for (int i = 0; i < v; i++)
		{
			if (!visited[i] && arr[current][i] == 1 && i != current)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
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
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	visited_filler(arr, v, 0, visited);
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}