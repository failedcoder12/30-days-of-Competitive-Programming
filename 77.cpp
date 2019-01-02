// https://codeforces.com/contest/283/problem/B

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

const ll MAXN = 2e5 + 5;
ll n,a[MAXN],dp[MAXN][2];
bool visit[MAXN][2];

ll solve(ll x,ll sign){
	if(x<=0 || x>n) return 0;

	ll ans = dp[x][sign];

	if(ans!=-1) return ans;

	if(visit[x][sign]) return dp[x][sign] = -1e13;

	visit[x][sign] = true;

	if(!sign) ans=a[x]+solve(x+a[x],sign^1);
	else ans=a[x]+solve(x-a[x],sign^1);

	return dp[x][sign] = ans;
}

signed main(){
	FastRead;
	memset(dp,-1,sizeof(dp));

	cin>>n;
	FOR(i,2,n) cin>>a[i];

	FOR(i,1,n-1){
		ll ans = i + solve(i+1,1);
		if(ans<0) ans = -1;
		cout<<ans<<endl;
	}
}