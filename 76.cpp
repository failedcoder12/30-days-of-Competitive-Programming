// https://codeforces.com/contest/700/problem/B

// NEED TO DO IT AGAIN

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

const ll MAXN = 2e5 + 2;
const ll L = 18;
ll n,k;
ll arr[MAXN];
vector<ll> graph[MAXN];
ll depth[MAXN],parent[L][MAXN];
ll discover[MAXN];
ll tim = 0,ans = 0;

void dfs(ll u,ll p){
	depth[u] = depth[p] + 1;
	parent[0][u] = p;
	discover[u] = ++tim;

	for(ll v:graph[u]) if(p!=v) dfs(v,u);
}

ll lca(ll a,ll b){
	if(depth[a]<depth[b]) swap(a,b);
	ll diff = depth[a]-depth[b];

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

ll distan(ll a,ll b){
	return depth[a] + depth[b] - 2*depth[lca(a,b)];
}

signed main(){
	cin>>n>>k;

	FOR(i,1,k+k) cin>>arr[i];

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1,0);

	FOR(i,1,L-1){
		FOR(j,1,n){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	auto cmp = [&](ll a,ll b){return discover[a]<discover[b];};

	sort(arr+1,arr+1+2*k,cmp);

	FOR(i,1,k){
		ans += distan(arr[i],arr[i+k]);
	}

	cout<<ans<<endl;
}