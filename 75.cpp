// https://codeforces.com/contest/449/problem/B

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

const ll MAXN = 1e5 + 3;
const ll INF = 1e9;
ll n,m,k;
vector<pair<ll,ll>> graph[MAXN];
set<pair<ll,ll>> trains; 
ll distan[MAXN];

void dijiktras(ll src){
	set<pair<ll,ll>> heap;

	heap.insert({0,src});
	distan[src] = 0;

	while(!heap.empty()){
		pair<ll,ll> tmp = *(heap.begin());
		heap.erase(heap.begin());

		ll u = tmp.s;

		for(pair<ll,ll> vv:graph[u]){
			ll v = vv.f,weight = vv.s;
			if(distan[v] > distan[u] + weight){
				if(distan[v] != INF){
					heap.erase(heap.find({distan[v],v}));
				}

				distan[v] = distan[u]+weight;
				heap.insert({distan[v],v});
			}
		}
	}
}

signed main(){
	FastRead;
    
	cin>>n>>m>>k;
    
    FOR(i,1,n) distan[i] = INF;

	FOR(i,1,m){
		ll u,v,w; cin>>u>>v>>w;
		graph[u].pb({v,w});
		graph[v].pb({u,w});
	}

	FOR(i,1,k){
		ll v,w; cin>>v>>w;
		graph[1].pb({v,w});
		trains.insert({v,w});
	}

	dijiktras(1);

	ll ans = k-trains.size();
	for(pair<ll,ll> vv:trains){
		ll v = vv.f,dist = vv.s;
		if(distan[v] < dist) ans++;
		else if(dist == distan[v]){
			for(pair<ll,ll> uu:graph[v]){
				if(distan[uu.f] + uu.s == distan[v]){ ans++;break; }
			}
		} 
	}

	cout<<ans<<endl;
}