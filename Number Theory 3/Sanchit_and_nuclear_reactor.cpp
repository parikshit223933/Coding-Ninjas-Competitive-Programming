#include<iostream>
#define endl '\n'
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
long long fact(int a, int m){
	long long res=1;
	for(int i=2;i<=a;i++)
		res=(res%m * i%m)%m;
	return res;
}
int32_t main(){
    fast
	int n;
	cin>>n;
	while(n--){
		int t;
		int m;
		cin>>t>>m;
		if(t<m){
			if(m-t==1){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<fact(t, m)%m<<endl;
				continue;
			}
		}
		else{
			int last = t%m;
			int facto=fact(last, m)%m;

			if((t/m)%2==0)
				cout<<facto<<endl;
			else
				cout<<((m-1)%m*facto%m)%m<<endl;
		}
	}
	return 0;
}