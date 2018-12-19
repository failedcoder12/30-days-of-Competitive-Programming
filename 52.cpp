// https://codeforces.com/contest/383/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define x f
#define y s
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// I am questioning life and universe and 
// everything else after looking at all this.

const ll N = 2e5 + 5;
ll n,m,tim = 0;
ll a[N],level[N],discovery[N],start[N],finish[N];
vector<ll> graph[N];
ll bit[N][2];

void dfs(ll u,ll p,ll lvl){
	level[u] = lvl%2;
	discovery[++tim] = u;
	start[u] = tim;
	for(ll v:graph[u]){
		if(v == p) continue;
		dfs(v,u,lvl+1);
	}
	finish[u] = tim;
}

void update(ll idx,ll id,ll k){
	for(;idx<=n;idx+=(idx&(-idx))){
		bit[idx][id] += k;
	}
}

ll sum(ll idx,ll id){
	ll ans = 0;
	for(;idx>0;idx-=(idx&(-idx))){
		ans+=bit[idx][id];
	}
	return ans;
}

signed main(){
	FastRead;

	cin>>n>>m;

	FOR(i,1,n) cin>>a[i];

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0,1);

	FOR(i,1,m){
		ll type; cin>>type;

		if(type == 1){
			ll x,val; cin>>x>>val;
			ll curlvl = level[x];
			update(start[x],curlvl,val);
			update(finish[x]+1,curlvl,-val);
			update(start[x],curlvl^1,-val);
			update(finish[x]+1,curlvl^1,val);
		}else {
			ll x; cin>>x;
			ll ans = a[x]+sum(start[x],level[x]);
			cout<<ans<<endl;
		}
	}
}