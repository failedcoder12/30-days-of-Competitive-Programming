// https://www.codechef.com/problems/CHEFLAND
// GIVING WRONG ANSWER

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
ll n,m;
const ll MAXN = 2e5 + 2;
vector<ll> graph[MAXN],indexs[MAXN];
bool visit[MAXN],bridge[MAXN];
ll discovery[MAXN],low[MAXN];
ll tim = 0,c = 0;
ll compoment[MAXN];
ll degree[MAXN];
map<pair<ll,ll>,ll> new_edges;

void find_bridges(ll u,ll p){
	visit[u] = true;
	discovery[u] = low[u] = ++tim;

	for(ll i=0;i<graph[u].size();i++){
		ll v = graph[u][i];
		if(v == p) continue;
		if(visit[v]){
			low[u] = min(low[u],discovery[v]);
		}else {
			find_bridges(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v]>discovery[u]){
				bridge[indexs[u][i]] = true;
			}
		}
	}
}

void dfs(ll u){
	compoment[u] = c;
	visit[u] = true;

	for(ll i=0;i<graph[u].size();i++){
		if(visit[graph[u][i]] || bridge[indexs[u][i]]) continue;
		dfs(graph[u][i]);
	}
}

signed main(){
	FastRead;
	cin>>n>>m;

	FOR(i,1,m){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
		indexs[u].pb(i);
		indexs[v].pb(i);
	}

	find_bridges(1,0);

	ZERO(visit);

	FOR(i,1,n){
		if(!visit[i]) c++,dfs(i);
	}

	FOR(u,1,n){
		for(ll j=0;j<graph[u].size();j++){
			ll v = graph[u][j];
			ll idx = indexs[u][j];

			if(!bridge[idx]) continue;

			if(!new_edges[{compoment[u],compoment[v]}]){
				new_edges[{compoment[u],compoment[v]}] = 1;
				new_edges[{compoment[v],compoment[u]}] = 1;
				degree[compoment[u]]++;
				degree[compoment[v]]++;
			}
		}
	}

	bool flag = true;

	FOR(i,1,c){
		if(degree[i]>2) flag = false;
	}

	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}