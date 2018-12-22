// https://codeforces.com/contest/514/problem/D
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

const ll N = 1e5 + 5;
const ll M = 6;
ll a[N][M];
multiset<ll> s[M];
ll n,m,k;

void add(ll idx){
	FOR(i,1,m){
		s[i].insert(a[idx][i]);
	}
}

void remove(ll idx){
	FOR(i,1,m){
		s[i].erase(s[i].find(a[idx][i]));
	}
}

ll reqd(){
	if(s[1].size() == 0) return 0;
	ll ans = 0;
	FOR(i,1,m){
		ans += *(--s[i].end());
	}
	return ans;
}

signed main(){
	FastRead;
	cin>>n>>m>>k;

	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}
	ll ans = 0;

	ll l = 1;
    
    ll dp[m+1];
    ZERO(dp);
    
	FOR(r,1,n){
		add(r);
		while(reqd()>k) remove(l++);

		if(r-l+1 > ans){
			ans = r-l+1;
			FOR(i,1,m){
				dp[i] = *(--s[i].end());
			}
		}
	}

	FOR(i,1,m){
		cout<<dp[i]<<" ";
	}
}