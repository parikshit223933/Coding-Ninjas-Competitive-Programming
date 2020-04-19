/* Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1 */



//for simpler version of this code, please check out "c2f75e6ebb613453e6e61385fdc41984b83c0c1c" commit in the history.
#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

stack<int> st;  
vector<int> adjList[100010];
bool visited[100010];


void dfs2(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs2(adjList[index][j]);
		}
	}
}

void dfs(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs(adjList[index][j]);
		}
	}
	st.push(index);
}
	

int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		memset(visited,false,sizeof(visited));
		
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adjList[a].push_back(b);
		}
		
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		memset(visited,false,sizeof(visited));
		int count=0;
		while(!st.empty()){
			int index=st.top();
			st.pop();
			if(!visited[index]){
				count++;
				dfs2(index);
			}
		}
		printf("%d\n",count);
		for(int i=1;i<=n;i++){
			adjList[i].clear();
		}
	}
	return 0;
}
