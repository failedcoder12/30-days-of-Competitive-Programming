// https://codeforces.com/contest/587/problem/C
// NEED TO DO AGAIN

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
const ll MAXN = 1e5 + 3;
const ll L = 19;
vector<ll>graph[MAXN];
vector<ll>vals[L][MAXN];
ll level[MAXN];
ll parent[L][MAXN];

void dfs(ll u,ll p){
	level[u] = level[p] + 1;
	parent[0][u] = p;

	for(ll v:graph[u]){
		if(v!=p) dfs(v,u);
	}
}

ll lca_(ll a,ll b){
	if(level[a]<level[b]) swap(a,b);

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

vector<ll> get(ll u,ll diff){
	vector<ll> ans;

	FOR(i,0,L-1){
		if(diff&(1<<i)){
			for(ll x:vals[i][u]) ans.pb(x);

			sort(ans.begin(),ans.end());

			if(ans.size()>10) ans.resize(10);

			u = parent[i][u];
		}
	}
	return ans;
}

signed main(){
	FastRead;

	ll n,m,q; cin>>n>>m>>q;

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	FOR(i,1,m){
		ll c; cin>>c;
		vals[0][c].pb(i);
	}

	dfs(1,0);

	FOR(i,1,L-1){
		FOR(j,1,MAXN-1){
			parent[i][j] = parent[i-1][parent[i-1][j]];

			for(ll x:vals[i-1][j]) vals[i][j].pb(x);
			for(ll x:vals[i-1][parent[i-1][j]]) vals[i][j].pb(x);

			sort(vals[i][j].begin(),vals[i][j].end());

			if(vals[i][j].size() > 10) vals[i][j].resize(10);
		}
	}

	while(q--){
		ll u,v,k; cin>>u>>v>>k;

		ll p = lca_(u,v);
		vector<ll> left = get(u,level[u]-level[p]);
		vector<ll> right = get(v,level[v]-level[p]+1);

		vector<ll> ans;

		for(ll x:left) ans.pb(x);
		for(ll x:right) ans.pb(x);

		sort(ans.begin(),ans.end());

		k = min(k,(ll)ans.size());

		cout<<k<<" ";
		for(ll i=0;i<k;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}