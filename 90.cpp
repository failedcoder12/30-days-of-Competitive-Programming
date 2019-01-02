// https://codeforces.com/contest/442/problem/A
// NEED TO DO IT AGAIN COPY PASTED
// KHATARNAK

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
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
	
const ll MAXN = 101;
ll colo[MAXN],num[MAXN];
ll mark[MAXN];
signed main(){
	FastRead;

	map<char,ll> m;
	m['R'] = 0,m['G'] = 1,m['B'] = 2,m['Y'] = 3,m['W'] = 4;

	ll n; cin>>n;

	FOR(i,0,n-1){
		string s; cin>>s;
		colo[i] = m[s[0]];
		num[i] = s[1]-'1';
	}

	ll ans = 100;

	for(ll i=0;i<(1<<10);i++){
		ll req = __builtin_popcount(i);
		FOR(j,0,n-1) mark[j] = 0;

		for(ll j=0;j<5;j++){
			if(i&(1<<j)){
				FOR(k,0,n-1) if(colo[k] == j) mark[k] |= (1<<j);
			}
		}

		for(ll j=5;j<10;j++){
			if(i&(1<<j)){
				FOR(k,0,n-1) if(num[k] == j-5) mark[k] |= (1<<j);
			}
		}

		bool able = true;

		FOR(j,0,n-1){
			FOR(k,0,n-1){
				if(colo[j]!=colo[k] || num[j]!=num[k]){
					if(mark[j] == mark[k]) able = false;
				}
			}
		}
		
		if(able) ans = min(ans,req);
	}

	cout<<ans<<endl;
}