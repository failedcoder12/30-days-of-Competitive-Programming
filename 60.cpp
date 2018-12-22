// https://codeforces.com/contest/219/problem/D

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
const ll MAXN = 2e5 + 5;
vector<ll> graph[MAXN];
map<pair<ll,ll>,ll> direction;
ll inv_in_path[MAXN];
ll total_in_path[MAXN];
ll total_inv = 0;
bool visit[MAXN];

void dfs(ll u,ll p){
	visit[u] = true;

	for(ll v:graph[u]){
		if(v == p) continue;
		if(direction[{u,v}] == -1){
			inv_in_path[v] = inv_in_path[u]+1;
			total_inv++;
		}else {
			inv_in_path[v] = inv_in_path[u];
		}
		total_in_path[v] = total_in_path[u] + 1;
		dfs(v,u);
	}
}

signed main(){
	FastRead;
	ll n;
	cin>>n;

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		direction[{u,v}] = 1,direction[{v,u}] = -1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0);

	ll ans = LLONG_MAX;
	FOR(i,1,n){
		ans = min(ans,total_inv - 2*inv_in_path[i] + total_in_path[i]);
	}
	cout<<ans<<endl;
	
	FOR(i,1,n){
	    if(total_inv - 2*inv_in_path[i] + total_in_path[i] == ans) cout<<i<<" ";
	}

}