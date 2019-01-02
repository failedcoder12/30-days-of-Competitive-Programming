// https://codeforces.com/contest/400/problem/D

// Taken From https://codeforces.com/contest/400/submission/45153131

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

const ll MAXN = 1e5 + 5;
const ll MAXM = 505;
const ll INF = 1e9;

ll n,m,k,grp = 0;
ll c[MAXM],vis[MAXN],comp[MAXN];
ll d[MAXM][MAXM];
vector<ll> graph[MAXN];

ll get(ll x){
	return (lower_bound(c+1,c+k+1,x)-c);
}

void dfs(ll u){
	if(vis[u]) return;
	vis[u] = 1;
	comp[u] = grp;
	for(ll v:graph[u]) dfs(v);
}

signed main(){
	FastRead;

	cin>>n>>m>>k;

	FOR(i,1,k){
		cin>>c[i];
		c[i] += c[i-1];
		FOR(j,1,k) d[i][j] = INF;
	}

	FOR(i,1,m){
		ll u,v,x; cin>>u>>v>>x;
		ll uu = get(u),vv = get(v);
		d[uu][vv] = min(d[uu][vv],x);
		d[vv][uu] = min(d[vv][uu],x);

		if(x == 0) graph[u].pb(v),graph[v].pb(u);
	}

	FOR(i,1,n) if(!vis[i]) dfs(i),grp++;

	bool check = true;

	FOR(i,1,k){
		d[i][i] = 0;
		ll val = -1;
		FOR(j,c[i-1]+1,c[i]){
			if(val == -1) val = comp[j];
			else {
				if(val!=comp[j]){
					check = false;
					break;
				}
			}
		}
	}

	if(!check){
		cout<<"No";
		return 0;
	}

	cout<<"Yes\n";

	FOR(mid,1,k){
		FOR(i,1,k){
			FOR(j,1,k){
				if(d[i][j]>d[i][mid]+d[mid][j]){
					d[i][j] = min(d[i][j],d[i][mid]+d[mid][j]);
				}
			}
		}
	}

	FOR(i,1,k){
		FOR(j,1,k){
			if(d[i][j] >= INF) d[i][j] = -1;
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
}