// https://codeforces.com/contest/463/problem/D

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
const ll MAXN = 1001;
vector<ll> graph[MAXN];
ll a[6][MAXN];
ll pos[6][MAXN];
bool visit[MAXN];
ll best[MAXN];
ll ans;

void dfs(ll u){
	visit[u] = true;
	for(ll v:graph[u]){
		if(!visit[v]){
			dfs(v);
		}
		best[u] = max(best[u],best[v]+1);
	}
	best[u] = max(best[u],1LL);
	ans = max(ans,best[u]);
}

signed main(){
	FastRead;

	ll n,k; cin>>n>>k;

	FOR(i,1,k){
		FOR(j,1,n){
			cin>>a[i][j];
			pos[i][a[i][j]] = j;
		}
	}

	FOR(i,1,n){
		FOR(j,1,n){
			if(i == j) continue;
			bool ok = true;
			FOR(K,1,k){
				if(pos[K][i] >= pos[K][j]){
					ok = false;
				}
			}
			if(ok) graph[i].push_back(j);
		}
	}

	FOR(i,1,n) if(!visit[i]) dfs(i);

	cout<<ans<<endl;
}