// https://codeforces.com/contest/832/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
#define s second
#define pb push_back
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 2e5 + 2;
const ll L = 20;
vector<ll> graph[MAXN];
ll level[MAXN];
ll parent[L][MAXN];

void dfs(ll u,ll p){
	level[u] = level[p] + 1;
	parent[0][u] = p;

	for(ll v:graph[u]){
		if(v == p) continue;
		dfs(v,u);
	}
}

ll lca_(ll a,ll b){
	if(level[a]<level[b]) swap(a,b);

	ll diff = level[a] - level[b];

	FOR(i,0,L-1) if(diff&(1<<i)) a = parent[i][a];

	if(a == b) return a;

	RFOR(i,0,L-1){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return parent[0][a];
}

ll dis(ll a,ll b){
	return level[a] + level[b] - 2*level[lca_(a,b)] + 1;
}

ll calc(ll f,ll s,ll t){
	return (dis(f,s) + dis(f,t) - dis(s,t)+1)/2;
}

signed main(){
	FastRead;
	
	ll n,q; cin>>n>>q;

	FOR(u,2,n){
		ll v; cin>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1,0);

	FOR(i,1,L-1){
		FOR(j,1,MAXN){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	while(q--){
		ll f,s,t; cin>>f>>s>>t;

		cout<<max({calc(f,s,t),calc(s,f,t),calc(t,s,f)})<<endl;
	}
}