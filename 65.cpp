// https://codeforces.com/contest/34/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(1);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
#define s second
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.

const ll MAXN = 5e4 + 5;
vector<ll> graph[MAXN];
ll n,r1,r2;

ll parent[MAXN];
void dfs(ll u,ll p){
	parent[u] = p;

	for(ll v:graph[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}

signed main(){
	FastRead;
	cin>>n>>r1>>r2;

	FOR(i,1,n){
		if(i == r1) continue;
		ll x; cin>>x;
		graph[x].push_back(i);
		graph[i].push_back(x);
	}

	dfs(r2,0);

	FOR(i,1,n){
		if(i == r2) continue;
		cout<<parent[i]<<" ";
	}
}