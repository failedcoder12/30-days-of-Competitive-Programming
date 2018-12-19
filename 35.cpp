// https://codeforces.com/contest/759/problem/B

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll MAXN = 1e5 + 5;
// I am questioning life and universe and 
// everything else after looking at all this.

ll dp[MAXN],a[MAXN];
ll n;
ll prev_charged = 0;

ll solve(ll indx){
	if(indx <= 0) return 0;
	if(dp[indx] != -1) return dp[indx];
	ll ans = 20 + solve(indx-1);

	ll prev_90 = upper_bound(a,a+indx+1,a[indx]-90)-a-1;
	ans = min(ans,50+solve(prev_90));
	ll prev_1440 = upper_bound(a,a+indx+1,a[indx]-1440)-a-1;
	ans = min(ans,120+solve(prev_1440));

	return dp[indx] = ans;
}

signed main(){

	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ll cost = solve(i);
		cout<<cost-prev_charged<<endl;
		prev_charged += cost-prev_charged;
	}
}