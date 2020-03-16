
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