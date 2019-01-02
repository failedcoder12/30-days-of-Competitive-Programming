// https://www.codechef.com/problems/YVNUM

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
const ll MOD = 1e9 + 7;

ll power(ll x,ll y){
	ll res = 1;

	while(y>0){
		if(y&1) res = (res*x)%MOD;
		y = y>>1;
		x = (x*x)%MOD;
	}
	return res;
}

ll invers(ll x){
	return power(x,MOD-2);
}

const ll MAXN = 1e5+2;

signed main(){
	FastRead;

	ll t; cin>>t;

	while(t--){
		string s; cin>>s;

		ll prev = 0;
		ll n = s.length();
		for(ll i=0;i<s.length();i++){
			ll temp = ((s[i]-'0')*power(10,n-i-1))%MOD;
			prev = (prev + temp)%MOD;
		}

		ll ans = prev;
		for(ll i=1;i<s.length();i++){
			ll temp = (prev*10)%MOD;
			temp = (temp + (s[i-1]-'0'))%MOD;
			temp = (temp - ((s[i-1]-'0')*power(10,n))%MOD)%MOD;
			temp = (temp+MOD)%MOD;
			ans = (ans*power(10,n))%MOD;
			ans = (ans+temp)%MOD;
			prev = temp;
		}

		cout<<ans<<endl;
	}
	
}