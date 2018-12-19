// https://codeforces.com/contest/276/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define x f
#define y s
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	FastRead;
	
	ll n,q; cin>>n>>q;

	ll a[n];

	FI(i,n) cin>>a[i];
	ll query[n+1];
    ZERO(query);
    
	while(q--){
		ll l,r; cin>>l>>r;
		l--,r--;
		query[l]++;
		query[r+1]--;
	}

	FOR(i,1,n) query[i] += query[i-1];

	sort(a,a+n);
	sort(query,query+n);
		
	ll ans = 0;
	FI(i,n){
		ans+=query[i]*a[i];
	}

	cout<<ans<<endl;
}