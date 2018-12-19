// https://codeforces.com/contest/61/problem/E

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
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

signed main(){
	FastRead;

	ll n; cin>>n;

	ll a[n];
	FI(i,n) cin>>a[i];

	ordered_set lset,rset;

	FI(i,n) rset.insert(a[i]);

	ll ans = 0;

	FI(i,n){
		rset.erase(a[i]);
		ll leftCnt = lset.size() - lset.order_of_key(a[i]);
		ll rightCnt = rset.order_of_key(a[i]);
		ans += leftCnt*rightCnt;
		lset.insert(a[i]);
	}

	cout<<ans;
}