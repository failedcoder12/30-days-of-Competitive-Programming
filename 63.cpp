// https://codeforces.com/contest/682/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
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
const ll MAXN = 1e5 + 5;
vector<pair<ll,ll>> graph[MAXN];
ll a[MAXN];
ll dist[MAXN];
ll ans = 0;

void dfs(ll u,ll p,ll w){
	dist[u] = w;
	if(dist[u]>a[u]){
		return;
	}
	ans++;

	for(auto vv:graph[u]){
		if(vv.f==p) continue;
		dfs(vv.f,u,max(vv.s,vv.s+w));
	}
}

signed main(){
	FastRead;

	ll n; cin>>n;

	FOR(i,1,n) cin>>a[i];

	FOR(i,2,n){
		ll u,w; cin>>u>>w;
		graph[u].push_back({i,w});
		graph[i].push_back({u,w});
	}

	dfs(1,0,0);

	cout<<n-ans;
}