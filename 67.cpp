// https://codeforces.com/problemset/problem/808/D

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

signed main(){
	FastRead;

	ll n; cin>>n;

	ll a[n+1];

	ll bsum = 0;
	FOR(i,1,n) {cin>>a[i]; bsum+=a[i];}

	map<ll,ll> m1,m2;

	FOR(i,1,n) m2[a[i]]++;

	ll fsum = 0;
	
	bool flag = false;

	FOR(i,1,n){
		fsum += a[i];
		m1[a[i]]++;
		m2[a[i]]--;
		bsum -= a[i];
		if((fsum+bsum)%2 == 0){
			ll temp = (fsum+bsum)/2;
			if(m1[fsum-temp]!=0 || m2[bsum-temp]!=0){
				flag = true;
			}
		}
	}

	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}