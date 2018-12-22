// https://codeforces.com/contest/161/problem/D

// NEED TO DO IT AGAIN
// JUST A COPY PASTE

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
const ll MAXN = 50001;
const ll MAXK = 501;
ll ans = 0;
ll dp[MAXN][MAXK];
vector<ll> graph[MAXN];
ll n,k; 

void dfs(ll u,ll p){
	dp[u][0] = 1;

	for(ll v:graph[u]){
		if(v == p) continue;
		dfs(v,u);
		FOR(i,0,k-1){
			ans += dp[u][i]*dp[v][k-i-1];
		}
		FOR(i,0,k){
			dp[u][i+1] += dp[v][i];
		}
	}
}


signed main(){
	FastRead;

	cin>>n>>k;

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}