// https://codeforces.com/contest/620/problem/E

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

const ll MAXN = 4e5 + 2;
vector<ll> graph[MAXN];
ll intime[MAXN],outtime[MAXN];
ll discover[2*MAXN];
ll tim = 0;
ll color[MAXN],seg[4*MAXN],lazy[4*MAXN];

void dfs(ll u,ll p){
	intime[u] = ++tim;
	discover[tim] = u;

	for(ll v:graph[u]){
		if(v!=p) dfs(v,u);
	}

	outtime[u] = tim;
}

void build(ll node,ll s,ll e){
	if(s>e) return;

	if(s == e){
		seg[node] = color[discover[s]];
		return;
	}

	ll mid = (s+e)>>1;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);

	seg[node] = seg[2*node]|seg[2*node+1];
}

void propogate(ll node,ll s,ll e){
	if(lazy[node] == 0) return;
	if(s!=e) lazy[2*node+1] = lazy[2*node] = lazy[node];
	seg[node] = lazy[node];
	lazy[node] = 0;
}

void paint(ll node,ll s,ll e,ll qs,ll qe,ll col){
	
	propogate(node,s,e);

	if(qs>e || qe<s || s>e) return;

	if(qs<=s && e<=qe){
		lazy[node] = (1LL<<col);
		propogate(node,s,e);
		return;
	}

	ll mid = (s+e)>>1;

	paint(2*node,s,mid,qs,qe,col);
	paint(2*node+1,mid+1,e,qs,qe,col);

	seg[node] = seg[2*node]|seg[2*node+1];
}

ll query(ll node,ll s,ll e,ll qs,ll qe){
	propogate(node,s,e);

	if(qs>e || qe<s || s>e) return 0;

	if(qs<=s && e<=qe){
		return seg[node];
	}	

	ll mid = (s+e)>>1;
	return query(2*node,s,mid,qs,qe)|query(2*node+1,mid+1,e,qs,qe);
}

signed main(){
	FastRead;

	ll n,m; cin>>n>>m;

	FOR(i,1,n){
		ll x; cin>>x;
		color[i] = (1LL<<x);
	}

	FOR(i,1,n-1){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1,0);

	build(1,1,n);

	while(m--){
		ll type; cin>>type;

		if(type == 1){
			ll v,c; cin>>v>>c;
			paint(1,1,n,intime[v],outtime[v],c);
		}else {
			ll v; cin>>v;
			ll ans = query(1,1,n,intime[v],outtime[v]);
			cout<<__builtin_popcountll(ans)<<endl;
		}
	}
}