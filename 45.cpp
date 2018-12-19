// https://codeforces.com/contest/269/problem/B

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

const ll MAXN = 5005;

ll n,m,a[MAXN],dp[MAXN];
double x;

signed main(){
	FastRead;

	cin>>n>>m;

	ll ans = 0;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>x;
		dp[i] = 1;
		for(ll j=1;j<i;j++){
			if(a[j]<=a[i]){
				dp[i] = max(dp[j]+1,dp[i]);
			} 
		}
		ans = max(ans,dp[i]);
	}

	cout<<n-ans<<endl;
}