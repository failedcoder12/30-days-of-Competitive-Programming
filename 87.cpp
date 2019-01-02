// https://codeforces.com/contest/519/problem/E

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

const ll MAXN = 1e5 + 3,L = 19;
vector<ll> graph[MAXN];
ll level[MAXN];
ll subtree[MAXN];
ll parent[L][MAXN];

void dfs(ll u,ll p){
	level[u] = level[p] + 1;
	parent[0][u] = p;
	subtree[u] = 1;

	for(ll v:graph[u]){
		if(v == p) continue;
		dfs(v,u);
		subtree[u] += subtree[v];
	}
}

ll lca_(ll a,ll b){
	if(level[a]<level[b]) swap(a,b);

	ll diff = level[a]-level[b];

	RFOR(i,0,L-1) if(diff&(1<<i)) a = parent[i][a];

	if(a == b) return a;

	RFOR(i,0,L-1){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

ll dist(ll a,ll b){
	return level[a] + level[b] - 2*level[lca_(a,b)];
}

signed main(){
	FastRead;

	ll n; cin>>n;

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1,0);

	FOR(i,1,L-1){
		FOR(j,1,MAXN-1){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	ll m; cin>>m;
	while(m--){
		ll a,b; cin>>a>>b;
		if(a == b){
			cout<<n<<endl;
			continue;
		}

		if(dist(a,b)%2 == 1){
			cout<<0<<endl;
			continue;
		}

		ll lca = lca_(a,b);

		if(dist(a,lca) == dist(b,lca)){
			ll diff_a = level[a]-level[lca]-1;
			FOR(i,0,L-1) if(diff_a&(1<<i)) a = parent[i][a];

			ll diff_b = level[b]-level[lca]-1;
			FOR(i,0,L-1) if(diff_b&(1<<i)) b = parent[i][b];	
			ll ans = n - subtree[a] - subtree[b];
			cout<<ans<<endl;

			continue;		
		}

		if(level[a]<level[b]) swap(a,b);

		ll dis = dist(a,b)/2-1;

		FOR(i,0,L-1) if(dis&(1<<i)) a = parent[i][a];

		ll ans = subtree[parent[0][a]] - subtree[a];

		cout<<ans<<endl;
	}
}