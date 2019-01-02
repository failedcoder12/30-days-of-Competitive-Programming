// https://codeforces.com/contest/1096/problem/D
// DO IT AGAIN

// TAKEN FROM https://codeforces.com/contest/1096/submission/47637502

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
const ll MAXN = 1e5+3;
ll a[MAXN];
ll dp[MAXN][10];
ll nn,mm;
string s; 

ll solve(ll n,ll m){
	if(n == 0) return 0;

	if(dp[n][m]!=-1) return dp[n][m];

	ll ans = 0;

	if(m == 4){
		if(s[n-1] == 'd') ans = min(solve(n-1,m-1),solve(n-1,m)+a[n]);
		else ans = solve(n-1,m);
	}else if(m == 3){
		if(s[n-1] == 'r') ans = min(solve(n-1,m-1),solve(n-1,m)+a[n]);
		else ans = solve(n-1,m);
	}else if(m==2){
		if(s[n-1] == 'a') ans = min(solve(n-1,m-1),solve(n-1,m)+a[n]);
		else ans = solve(n-1,m);
	}else {
		if(s[n-1] == 'h') ans = solve(n-1,m)+a[n];
		else ans = solve(n-1,m);
	}
	return dp[n][m] = ans;
}

signed main(){
	FastRead;

	memset(dp,-1,sizeof(dp));
	ll n; cin>>n; nn = n;
	
	cin>>s;

	FOR(i,1,n) cin>>a[i];

	ll ans = solve(n,4);
	cout<<ans<<endl;
}