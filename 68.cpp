// https://codeforces.com/contest/744/problem/A

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
#define pb push_back
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 1e5 + 5;
vector<ll> graph[MAXN];
ll a[MAXN];
ll n,m,k;
ll have = 0;
bool visit[MAXN];

void dfs(ll u){
	visit[u] = true;
	have++;

	for(ll v:graph[u]){
		if(!visit[v]) dfs(v);
	}
}

signed main(){
	FastRead;
	cin>>n>>m>>k;

	ll total = n;
	FOR(i,1,k) cin>>a[i];

	FOR(i,1,m){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	ll maxx = 0,ans = 0;
	FOR(i,1,k){
		have = 0;
		dfs(a[i]);
		ans += have*(have-1)/2;
		maxx = max(have,maxx);
		total -= have;
	}

	ans += total*(total-1)/2;
	ans += maxx*total;
	ans -= m;
	cout<<ans<<endl;
}