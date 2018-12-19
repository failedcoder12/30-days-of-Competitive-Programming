// https://codeforces.com/contest/755/problem/D

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
const ll MAXN = 1e6+5;
ll bit[MAXN];

void update(ll idx,ll k){
	for(;idx<MAXN;idx+=(idx&(-idx))){
		bit[idx] += k;
	}
}

ll sum(ll idx){
	ll ans = 0;
	for(;idx>0;idx-=(idx&(-idx))){
		ans += bit[idx];
	}
	return ans;
}

signed main(){
	FastRead;

	ll n,k; cin>>n>>k;

	k = min(k,n-k);
	ll prev = 1,ans = 1;

	for(ll i=1;i<=n;i++){
		ll curr = prev+k;
		if(curr > n) curr-=n;

		if(curr > prev){
			ans += sum(curr-1)-sum(prev)+1;
		}else {
			ans += sum(n)-sum(prev);
			ans += sum(curr-1) + 1;
		}

		cout<<ans<<" ";
		update(prev,1);
		update(curr,1);
		prev = curr;
	}
}