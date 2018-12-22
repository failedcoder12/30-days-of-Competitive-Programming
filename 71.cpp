// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/description/

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

set<ll> art;
ll n,m,q;
const ll MAXN = 1e2 + 4;
vector<ll> graph[MAXN];
ll tim = 0;
ll low[MAXN],discover[MAXN];
bool visit[MAXN];

void dfs(ll u,ll p){
	visit[u] = true;
	low[u] = discover[u] = ++tim;
	ll child = 0;

	for(ll v:graph[u]){
		if(v == p) continue;
		if(!visit[v]){
			child++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(p == 0 && child>1) art.insert(u);
			if(p != 0 && low[v]>=discover[u]) art.insert(u);
		}else low[u] = min(low[u],discover[v]);
	}
}

signed main(){
	FastRead;

	cin>>n>>m;

	FOR(i,1,m){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	FOR(i,1,n) if(!visit[i]) dfs(i,0);

	cin>>q;

	while(q--){
		ll x; cin>>x;
		if(art.find(x)!=art.end()) cout<<"Satisfied "<<graph[x].size()<<endl;
		else cout<<"Not Satisfied\n";
	}
}