// https://codeforces.com/contest/75/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

ll a,b;
vector<ll> v;

signed main(){

	FastRead;
	cin>>a>>b;

	for(ll i=1;i*i<=a;i++){
		if(a%i == 0){
			if(b%i == 0) v.push_back(i);
			if(b%(a/i) == 0) v.push_back(a/i);
		}
	}

	sort(v.begin(),v.end());

	ll q; cin>>q;
	while(q--){
		ll l,r;
		cin>>l>>r;

		auto fin = upper_bound(v.begin(),v.end(),r);
		fin--;

		if(*fin < l) cout<<"-1\n";
		else cout<<*fin<<endl;
	}
}
