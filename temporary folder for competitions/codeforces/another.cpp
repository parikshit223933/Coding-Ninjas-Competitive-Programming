#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        int remainder=n%x;
        if(remainder-y==0){
            cout<<n<<endl;
        }
        else if(remainder-y>0){
            cout<<n-(remainder-y)<<endl;
        }
        else{
            cout<<n-(remainder+x-y)<<endl;
        }
    }


    return 0;
}