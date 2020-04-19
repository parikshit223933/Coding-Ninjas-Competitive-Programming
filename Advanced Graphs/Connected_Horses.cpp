/* You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2 */

#include<iostream>
#include<vector>

using namespace std;
#define pii pair<ll,ll>
#define MOD 1000000007
#define ll long long int

ll dfs(ll i, ll j, vector<pii>** graph, ll** visited){
	visited[i][j] = 1;
	ll answer = 1;

	for(ll k = 0; k < graph[i][j].size(); k++){
        ll x = graph[i][j][k].first;
        ll y = graph[i][j][k].second;
        if(!visited[x][y]){
            answer = (answer+dfs(x, y, graph, visited))%MOD;
        }
    }

    return answer;
}

void fill_vector(vector<pii>** graph, ll** board, ll m, ll n){
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			if (board[i][j] == 1)
			{
				graph[i][j].push_back(make_pair(i, j));

				if (i+2<n && j+1<m && board[i+2][j+1] == 1)
				{
					graph[i][j].push_back(make_pair(i+2, j+1));
				}


				if (i+2<n && j-1>=0 && board[i+2][j-1] == 1)
				{
					graph[i][j].push_back(make_pair(i+2, j-1));
				}

				if (i-2>=0 && j+1<m && board[i-2][j+1] == 1)
				{
					graph[i][j].push_back(make_pair(i-2, j+1));
				}

				if (i-2>=0 && j-1>=0 && board[i-2][j-1] == 1)
				{
					graph[i][j].push_back(make_pair(i-2, j-1));
				}

				if (i+1<n && j+2<m && board[i+1][j+2] == 1)
				{
					graph[i][j].push_back(make_pair(i+1, j+2));
				}

				if (i+1<n && j-2>=0 && board[i+1][j-2] == 1)
				{
					graph[i][j].push_back(make_pair(i+1, j-2));
				}

				if (i-1>=0 && j+2<m && board[i-1][j+2] == 1)
				{
					graph[i][j].push_back(make_pair(i-1, j+2));
				}

				if (i-1>=0 && j-2>=0 && board[i-1][j-2] == 1)
				{
					graph[i][j].push_back(make_pair(i-1, j-2));
				}
			}
		}
	}

	return;
}


int main()
{
	//To get the factorial
	ll *factorial = new ll[1000000];
    factorial[1] = 1;
    for(ll i = 2; i < 1000000; i++){
    	factorial[i] = (factorial[i-1]*i)%MOD;
    }

    //Main part of the input
	ll t;
	cin>>t;
	while(t--){
		ll n, m;
		ll q;
		cin>>n>>m>>q;

		//Create a 2d array for board
		ll** board = new ll*[n];
		for (ll i = 0; i < n; ++i)
		{
			board[i] = new ll[m];
			for (ll j = 0; j < m; ++j)
			{
				board[i][j] = 0;
			}
		}

		//Fill the board
		while(q--){
			ll x, y;
			cin>>x>>y;
			board[x-1][y-1] = 1;
		}


		//Creating a graph 2d array
		vector<pii>** graph = new vector<pii>*[n];
		for (ll i = 0; i < n; ++i)
		{
			graph[i] = new vector<pii>[m];
		}

		//Fill the graph
		fill_vector(graph, board, m, n);

		
		ll** visited = new ll*[n];
		for (ll i = 0; i < n; ++i)
		{
			visited[i] = new ll[m];;
			for (ll j = 0; j < m; ++j)
			{
				visited[i][j] = 0;
			}
		}

		ll ans = 1;
		for (ll i = 0; i < n; ++i)
		{
			for (ll j = 0; j < m; ++j)
			{
				if (visited[i][j] == 0 && board[i][j] == 1)
				{
					ans = (ans*factorial[dfs(i, j, graph, visited)])%MOD;
				}
				
			}
		}

		cout << ans << endl;
	}


	return 0 ; 

}