// https://www.codechef.com/problems/POSTTREE/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100005
// I am questioning life and universe and 
// everything else after looking at all this.

ll n,x,val[20][MAXN],parent[20][MAXN],level[MAXN],arr[MAXN],ans[MAXN];
vector<ll> graph[MAXN];

void dfs(ll u,ll p){
	ll v = u;

	for(ll i=19;i>=0;i--){
		if(val[i][v] >= arr[u]){
			v = parent[i][v];
		}
	}

	v = parent[0][v];
	ans[u] = ans[v] + (level[u]-level[v])*arr[u];

	for(ll vv:graph[u]){
		if(vv == p) continue;
		parent[0][vv] = u;
		val[0][vv] = arr[u];

		for(ll i=1;i<=19;i++){
			parent[i][vv] = parent[i-1][parent[i-1][vv]];
			val[i][vv] = min(val[i-1][vv],val[i-1][parent[i-1][vv]]);
		}
		level[vv] = level[u] + 1;
		dfs(vv,u);
	}

}

int main(){
	FastRead;
    
    level[1] = 1;
	cin>>n;
	for(ll i=2;i<=n;i++){
		cin>>x;
		graph[x].push_back(i);
		graph[i].push_back(x);
	}

	for(ll i=1;i<=n;i++) cin>>arr[i];

	dfs(1,0);

	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
}