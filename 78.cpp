// https://codeforces.com/contest/117/problem/C

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

const ll MAXN = 5005;
ll n,vis[MAXN];
char graph[MAXN][MAXN];

void dfs(ll u,ll p){
	if(vis[u]) return;
	vis[u] = 1;
	FOR(i,1,n){
		if(graph[u][i] == '0') continue;
		dfs(i,u);
		if(graph[i][p] == '1'){
			cout<<p<<" "<<u<<" "<<i;
			exit(0);
		}
	}
}

signed main(){
	FastRead;

	cin>>n;

	FOR(i,1,n) FOR(j,1,n) cin>>graph[i][j];

	FOR(i,1,n) dfs(i,0);

	cout<<-1<<endl;
}