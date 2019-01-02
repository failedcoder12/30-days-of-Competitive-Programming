// KUCH SAMAJ NA AAE
//https://codeforces.com/contest/766/problem/E
// NEED TO DO IT AGAIN COPY PASTED

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
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 1e5 + 3;
vector<ll> graph[MAXN];
ll dp[MAXN][2];
ll a[MAXN],w[MAXN];
ll res;

void dfs(ll u,ll p){
	dp[u][w[u]] = 1;
	if(w[u]) res++;

	for(ll v:graph[u]){
		if(v == p) continue;

		dfs(v,u);

		res += dp[u][0]*dp[v][1];
		res += dp[u][1]*dp[v][0];

		dp[u][w[u]] += dp[v][0];
		dp[u][1^w[u]] += dp[v][1];
	}
}

signed main(){
	FastRead;
	
	ll n; cin>>n;

	FOR(i,1,n) cin>>a[i];

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	ll ans = 0;
	FOR(i,0,20){
		ZERO(dp);
		res = 0;

		FOR(j,1,n){
			w[j] = a[j]%2;
			a[j] = a[j]/2;
		}

		dfs(1,0);
		ans += res*(1LL<<i);
	}

	cout<<ans<<endl;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define ll long long int
// #define FOR(i,a,n) for (int i=(a);i<=(n);++i)
// #define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
// #define FI(i,n) for (int i=0; i<(n); ++i)
// #define ZERO(a) memset((a),0,sizeof((a)))
// #define f first
// #define s second
// #define pb push_back
// #define mk make_pair
// #define all(g) g.begin(),g.end()
// int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
// int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// // #include <ext/pb_ds/assoc_container.hpp> // Common file
// // #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// // using namespace __gnu_pbds;
// // typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// // I am questioning life and universe and 
// // everything else after looking at all this.
// const ll MAXN = 1e5 + 3;
// vector<ll> graph[MAXN];
// ll dp[MAXN][2];
// ll a[MAXN],w[MAXN];
// ll pre[MAXN];
// ll dfs(ll u,ll p){

// 	pre[u] = w[u]^pre[p];
// 	dp[u][w[u]]++;
// 	ll res = 0;
// 	if(pre[u]) res++;

// 	for(ll v:graph[u]){
// 		if(v == p) continue;

// 		res += dfs(v,u);

// 		if(w[u]){
// 			res += dp[u][1]*dp[v][1];
// 			res += dp[u][0]*dp[v][0];
// 		}else {
// 			res += dp[u][1]*dp[v][0];
// 			res += dp[u][0]*dp[v][1];
// 		}

// 		dp[u][0] += dp[v][0];
// 		dp[u][1] += dp[v][1];
// 	}

// 	return res;
// }

// signed main(){
// 	FastRead;
	
// 	ll n; cin>>n;

// 	FOR(i,1,n) cin>>a[i];

// 	FOR(i,1,n-1){
// 		ll u,v; cin>>u>>v;
// 		graph[u].pb(v);
// 		graph[v].pb(u);
// 	}

// 	ll ans = 0;
// 	FOR(i,0,20){
// 		ZERO(dp);

// 		FOR(j,1,n){
// 			w[j] = a[j]%2;
// 			a[j] = a[j]/2;
// 		}

// 		ll res = dfs(1,0);
// 		ans += res*(1LL<<i);
// 	}

// 	cout<<ans<<endl;
// }