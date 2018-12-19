// https://codeforces.com/contest/629/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define x f
#define y s
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.

#define M_PI 3.14159265358979323846
const ll MAXN = 1e5+5;
ll r[MAXN],h[MAXN];
ll v[MAXN],bit[MAXN],DP[MAXN];

map<ll,ll> compress;

void update(ll idx,ll val){
	for(;idx<MAXN;idx+=(idx&(-idx))){
		bit[idx] = max(bit[idx],val);
	}
}

ll RMQ(ll idx){
	ll val = 0;
	for(;idx>0;idx-=(idx&(-idx))){
		val = max(bit[idx],val);
	}	
	return val;
}

ll volume(ll i){
	return r[i]*r[i]*h[i];
}

signed main(){
	FastRead;

	ll n; cin>>n;

	FOR(i,1,n){
		cin>>r[i]>>h[i];
		v[i] = volume(i);
		compress[v[i]];
	}

	ll com_i = 1;

	for(auto x:compress) compress[x.first] = com_i++;

	ll res = 0;

	FOR(i,1,n){
		ll v = compress[volume(i)];
		DP[v] = volume(i)+RMQ(v-1);
		update(v,DP[v]);
		res = max(res,DP[v]);
	}

	printf("%.10f\n",double(res)*M_PI);
}