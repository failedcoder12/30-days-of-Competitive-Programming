// https://codeforces.com/contest/739/problem/B

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
vector<pair<ll,ll>> graph[MAXN];
ll a[MAXN];
ll discovery[MAXN],start[MAXN],finish[MAXN];
ll tim = 0;
ll dist[MAXN];

void dfs(ll u,ll p,ll w){
	discovery[++tim] = u;
	start[u] = tim;
	dist[u] = dist[p]+w;
	for(auto vv:graph[u]){
		ll v = vv.f;
		if(v == p) continue;
		dfs(v,u,vv.s);
	}
	finish[u] = tim;
}

struct data {
	vector<ll> val;
}seg[3*MAXN];

void build(ll node,ll s,ll e){
	if(s>e) return;
	if(s == e){
		seg[node].val.push_back(dist[discovery[s]]);
		return;
	}	

	ll mid = (s+e)>>1;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);

	merge(seg[2*node].val.begin(),seg[2*node].val.end(),
		seg[2*node+1].val.begin(),seg[2*node+1].val.end(),
		back_inserter(seg[node].val));
}

ll query(ll node,ll s,ll e,ll qs,ll qe,ll uu){
	if(s>e || qe<s || qs>e) return 0;
	if(qs<=s && e<=qe){
		ll xx = lower_bound(seg[node].val.begin(),
			seg[node].val.end(),uu+1) - seg[node].val.begin();
		
		return xx;
	}

	ll mid = (s+e)/2;
	return query(2*node,s,mid,qs,qe,uu)+query(2*node+1,mid+1,e,qs,qe,uu);
}

signed main(){
	FastRead;

	ll n; cin>>n;

	FOR(i,1,n) cin>>a[i];

	if(n == 1){
		cout<<0<<endl;
		return 0;
	}

	FOR(i,2,n){
		ll u,w; cin>>u>>w;
		graph[i].push_back({u,w});
		graph[u].push_back({i,w});
	}

	dfs(1,0,0);
	
	FOR(i,1,n) dist[i] = dist[i]-a[i];
    
	build(1,1,tim);

	FOR(i,1,n){
		ll val = query(1,1,n,start[i]+1,finish[i],dist[i]+a[i]);
		cout<<val<<" ";
	}
}