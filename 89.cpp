// https://codeforces.com/contest/510/problem/D

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
	
const ll MAXN = 302;
const ll inf = 1e9;
ll L[MAXN],C[MAXN];
map<pair<ll,ll>,ll> dp;

ll solve(ll n,ll g){
	if(n == 0){
		if(g == 1) return 0;
		else return inf;
	}

	if(dp.count({n,g})) return dp[{n,g}];

	ll ans = min(solve(n-1,g),solve(n-1,__gcd(g,L[n])) + C[n]);

	return dp[{n,g}] = ans;
}

signed main(){
	FastRead;

	ll n; cin>>n;

	FOR(i,1,n) cin>>L[i];
	FOR(i,1,n) cin>>C[i];

	ll ans = solve(n,0);

	if(ans == inf) cout<<-1<<endl;
	else cout<<ans<<endl;
}