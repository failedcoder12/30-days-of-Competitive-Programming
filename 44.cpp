// https://codeforces.com/problemset/problem/115/A

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

#define MAXN 2005
vector<ll> graph[MAXN];
bool visited[MAXN];
ll ans = 0;

void dfs(ll u,ll p,ll level){
	visited[u] = true;
	ans = max(ans,level);
	for(ll v:graph[u]){
		if(!visited[v]){
			dfs(v,u,level+1);
		}
	}
}

signed main(){
	FastRead;

	ll n;
	cin>>n;
	ll pa[n+1];
	for(ll i=1;i<=n;i++){
		ll p; cin>>p;
		pa[i] = p;
		if(p != -1){
			graph[i].push_back(p);
			graph[p].push_back(i);
		}
	}

	for(ll i=1;i<=n;i++){
		if(pa[i] == -1) dfs(i,0,1);
	}

	cout<<ans<<endl;
}