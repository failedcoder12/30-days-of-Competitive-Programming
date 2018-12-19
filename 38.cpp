// https://codeforces.com/contest/332/problem/B

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 400010;

ll sum[MAXN];

signed main(){
	FastRead;

	ll n,k; cin>>n>>k;

	ll a,b,c,mx,ans;

	a = b = c = -1;
	mx = 0,ans = 0;

	for(ll i=1;i<=n;i++){
		cin>>sum[i];
		sum[i] += sum[i-1];
	}

	for(ll i=n;i>=k;i--){
		sum[i] -= sum[i-k];
		if(ans <= mx+sum[i]){
			ans = mx+sum[i];
			a = i,b = c; 
		}
		if(sum[i+k-1] >= mx){
			mx = sum[i+k-1];
			c = i+k-1;
		}
	}

	cout<<a-k+1<<" "<<b-k+1<<endl;
}