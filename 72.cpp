// https://www.codechef.com/problems/KINGCON

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

ll t,n,m,k;
const ll MAXN = 3e3 + 2;
vector<ll> graph[MAXN];
bool visit[MAXN];
bool articulate[MAXN];
ll discover[MAXN],low[MAXN];
ll tim = 0;

void dfs(ll u,ll p){
	visit[u] = true;

	discover[u] = low[u] = ++tim;

	ll child = 0;
	for(ll v:graph[u]){
		if(v == p) continue;

		if(visit[v]){
			low[u] = min(low[u],discover[v]);
		}else {
			child++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= discover[u] && p!=0) articulate[u] = true;
		}
	}
	if(p == 0 && child>1) articulate[u] = true;
}

signed main(){
	FastRead;

	ll t; cin>>t;

	while(t--){
		cin>>n>>m>>k;

		FOR(i,1,n){
			graph[i].clear();
			visit[i] = 0,articulate[i] = 0;
		}

		FOR(i,1,m){
			ll u,v; cin>>u>>v; u++,v++;
			graph[u].pb(v);
			graph[v].pb(u);
		}

		dfs(1,0);

		ll ans = 0;
		FOR(i,1,n) if(articulate[i]) ans++;

		cout<<ans*k<<endl;
	}
}