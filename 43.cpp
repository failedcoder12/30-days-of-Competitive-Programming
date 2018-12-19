// https://codeforces.com/contest/231/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.
const ll N = 1e5 + 5;
ll n,k,store;
ll a[N],pref[N];

bool check(ll m){
	for(ll i=m;i<=n;i++){
		ll req = (a[i]*m)-(pref[i]-pref[i-m]);
		if(req<=k){
			store = a[i];
			return 1;
		}
	}
	return 0;
}

signed main(){
	FastRead;

	cin>>n>>k;

	for(ll i=1;i<=n;i++) cin>>a[i];

	sort(a+1,a+n+1);

	for(ll i=1;i<=n;i++) pref[i] = pref[i-1]+a[i];

	ll s = 1,e = n;

	while(s<e){
		ll mid = (s+e+1)>>1;
		if(check(mid)) s = mid;
		else e = mid-1;
	}

	check(s);
	cout<<s<<" "<<store<<endl;
}