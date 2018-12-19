// https://codeforces.com/contest/446/problem/A

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	ll n; cin>>n;

	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];

	ll l[n],r[n];
	   
	for(ll i=0;i<n;i++) l[i] = r[i] = 1;
    
	for(ll i=1;i<n;i++){
		if(a[i]>a[i-1]) l[i] = l[i-1]+1;
	}

	for(ll i=n-2;i>=0;i--){
		if(a[i+1]>a[i]) r[i] = r[i+1]+1;
	}

    if(n == 1) {
        cout<<1<<endl;
        return 0;
    }
	ll ans = 2;
	for(ll i=1;i<n-1;i++){
	    if(a[i-1]+1<a[i+1])
			ans = max(ans,l[i-1]+r[i+1]+1);
		else 
		    ans = max({ans,l[i-1]+1,r[i+1]+1});
	}
	
	ans = max(ans,l[n-2]+1);
	ans = max(ans,r[1]+1);

	cout<<ans<<endl;
}