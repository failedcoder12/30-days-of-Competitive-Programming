// https://www.codechef.com/problems/SORTALGO

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	FastRead;
	ll t;
	cin>>t;

	while(t--){
		ll n; cin>>n;

		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];

		vector<ll> b;
		b.push_back(0);

		for(ll i=1;i<n;i++){
			if(a[i] >= a[b[b.size()-1]]){
				b.push_back(i);
			}
		}
		b.push_back(n);

		ll ans = b.size()-1;
		for(ll i=0;i<b.size()-1;i++){
			ll val = 0,cnt = 0;
			if(i!=0) val = a[b[i-1]];
			for(ll j=b[i]+1;j<b[i+1];j++){
				if(a[j]>=val){
					val = a[j];
					cnt++;
				}
			}
			ll curr = b.size()-2+cnt;
			ans = max(ans,curr);
		}

		cout<<ans<<endl;
	}
}