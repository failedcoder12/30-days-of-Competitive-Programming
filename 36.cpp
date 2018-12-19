// https://codeforces.com/contest/839/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll MAXN = 1e5 + 5;
// I am questioning life and universe and 
// everything else after looking at all this.

vector<ll> graph[MAXN];
double values[MAXN];
ll length[MAXN];

void dfs(ll u,ll p,double val){
	values[u] = 1/val;
	length[u] = length[p]+1;

	ll child = graph[u].size();
	if(p != 0) child--;
	for(ll v:graph[u]){
		if(v!=p){
			dfs(v,u,val/child);
		}
	}
}

signed main(){
	FastRead;

	length[0] = -1;
	ll n;
	cin>>n;

	for(ll i=0;i<n-1;i++) {
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0,1);

	double val = 0;

	for(ll i=1;i<=n;i++){
	    if(graph[i].size() == 1)
		val += length[i]/values[i];
	}

	cout<<fixed<<setprecision(6)<<val<<endl;
}