// https://codeforces.com/contest/1033/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.
#define MAXN 100002

ll a[MAXN],dp[MAXN];
pair<ll,ll> v[MAXN];

int main(){
	FastRead;
	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++){
		cin>>a[i];
		v[i] = {a[i],i};
	}

	memset(dp,-1,sizeof(dp));
	sort(v+1,v+n+1);

	for(ll i=n;i>=1;i--){
		ll jump = v[i].first;
		ll ind = v[i].second;

		ll ans = 0;
		for(ll j=ind+jump;j<=n;j+=jump){
			if(dp[j] == 0) ans|=1;
		}

		for(ll j=ind-jump;j>=1;j-=jump){
			if(dp[j]==0) ans|=1;
		}

		dp[ind] = ans;
	}

	for(ll i=1;i<=n;i++){
		if(dp[i]) cout<<"A";
		else cout<<"B";
	}
}