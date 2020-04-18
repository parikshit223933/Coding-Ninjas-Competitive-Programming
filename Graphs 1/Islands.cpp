/* An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1  */



#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void visited_filler(int** arr, int n, int starting_vertex, bool* visited)
{
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
	while (!q.empty())
	{
		int current_element = q.front();
		for (int i = 1; i < n; i++)
		{
			if (i == current_element)
			{
				continue;
			}
			if (visited[i])
			{
				continue;
			}
			if (arr[current_element][i] == 1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int** arr = new int*[n+1];
	for (int i = 0; i < n+1; i++)
	{
		arr[i] = new int[n+1];
		for (int j = 0; j < n+1; j++)
		{
			arr[i][j] = 0;
		}
	}
    
    for (int i = 0; i < m; i++)
	{
		arr[u[i]][v[i]] = 1;
		arr[v[i]][u[i]] = 1;
	}
    
    bool* visited = new bool[n+1];
	for (int i = 0; i < n+1; i++)
	{
		visited[i] = false;
	}
    
    int count=0;

	for (int i = 1; i < n+1; i++)
	{
		if (!visited[i])
		{
		    visited_filler(arr, n+1, i, visited);
            count+=1;
		}
	}
	return count;
}