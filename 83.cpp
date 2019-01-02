// https://codeforces.com/contest/191/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
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
const ll MAXN = 2e5+3;
const ll L = 19;
vector<ll> graph[MAXN],indd[MAXN];
ll ans[MAXN];
ll parent[L][MAXN];
ll level[MAXN];
ll store[MAXN];

void dfs(ll u,ll p){
	parent[0][u] = p;
	level[u] = level[p] + 1;

	for(ll v:graph[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}

ll lca_(ll a,ll b){
	if(level[a] < level[b]) swap(a,b);

	ll diff = level[a]-level[b];

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

ll dfs_2(ll u,ll p,ll ind){
	ll curr = 0;
	for(ll i=0;i<graph[u].size();i++){
		if(graph[u][i] == p) continue;
		curr += dfs_2(graph[u][i],u,indd[u][i]);
	}
	curr += store[u];
	return ans[ind] = curr;
}

signed main(){
	ll n; cin>>n;

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);

		indd[u].pb(i);
		indd[v].pb(i);
	}

	dfs(1,0);

	FOR(i,1,L-1){
		FOR(j,1,n){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	ll q; cin>>q;

	while(q--){
		ll u,v; cin>>u>>v;
		store[u]++,store[v]++;
		store[lca_(u,v)]-=2;
	}

	dfs_2(1,0,0);

	FOR(i,1,n-1) cout<<ans[i]<<" ";
}