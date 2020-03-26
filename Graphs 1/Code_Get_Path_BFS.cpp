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