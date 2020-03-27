#include<iostream>
#include<climits>
using namespace std;
int get_min_vertex(bool* visited, int* weight, int n)
{
	int min_vertex = -1;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && (min_vertex==-1||(weight[i]<weight[min_vertex])))
		{
			min_vertex = i;
		}
	}
	return min_vertex;
}
void prims(int **edges, int n)
{
	bool* visited = new  bool[n];
	int* parent = new int[n];
	int* weight = new int[n];
	for (int i = 0; i < n; i++)
	{
		weight[i] = INT_MAX;
                visited[i]=false;
	}
	parent[0] = -1;
	weight[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min_vertex = get_min_vertex(visited, weight, n);
		visited[min_vertex] = true;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && edges[min_vertex][j] !=0)
			{
				if (weight[j] > edges[min_vertex][j])
				{
					weight[j] = edges[min_vertex][j];
					parent[j] = min_vertex;
				}
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (parent[i] < i)
		{
			cout << parent[i] << " " << i <<" "<< weight[i]<<endl;
		}
		else
		{
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
}
int main()
{
	int n, e;
	cin >> n >> e;
	int** edges = new int* [n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	prims(edges, n);
	for (int i = 0; i < n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
}