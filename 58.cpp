// https://codeforces.com/contest/735/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(1);--i)
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

ll f[300];

signed main(){
	ll k,n;
	cin>>n;

	if(n == 2){
		cout<<1<<endl;
		return 0;
	}

	f[1] = 2,f[2] = 3;

	FOR(i,3,299){
		f[i] = f[i-1] + f[i-2];
		if(f[i]>n){
			k = i-1;
			break;
		}
	}
	cout<<k<<endl;
}