/* Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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
#include<vector>
using namespace std;
vector<int> get_path(int** arr, int v, bool* visited, int current_vertex, int v2)
{
	if (current_vertex == v2)
	{
		vector<int>ans;
		ans.push_back(current_vertex);
		return ans;
	}
	for (int i = 0; i < v; i++)
	{
		if (!visited[i] && i != current_vertex && arr[current_vertex][i] == 1)
		{
			vector<int>ans;
			visited[i] = true;
			ans = get_path(arr, v, visited, i, v2);
			if (ans.size() != 0)
			{
				ans.push_back(current_vertex);
				return ans;
			}
		}
	}
	vector<int>ans;
	return ans;
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
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
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
	
	visited[v1] = true;
	vector<int>ans=get_path(arr, v, visited, v1, v2);
	if (ans.size() != 0)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
	}
	else
	{
		return 0;
	}
}