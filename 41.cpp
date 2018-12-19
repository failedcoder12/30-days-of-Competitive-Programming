// https://codeforces.com/contest/486/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

ll n,p;
string s;
vector<ll> a,b;

signed main(){

	cin>>n>>p>>s;

	p--;

	ll ans = 0;

	for(ll i=0,j=n-1;i<j;i++,j--){
		ans += min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
		if(s[i] != s[j]){
			a.push_back(i),b.push_back(j);
		}
	}

	reverse(b.begin(),b.end());
	if(a.size()==0){
		cout<<0<<endl;
		return 0;
	}

	ll left_a = abs(a[0]-p)+abs(a[a.size()-1]-a[0]);
	ll right_a = abs(a[a.size()-1]-p)+abs(a[a.size()-1]-a[0]);

	ll left_b = abs(b[0]-p)+abs(b[b.size()-1]-b[0]);
	ll right_b = abs(b[b.size()-1]-p)+abs(b[b.size()-1]-b[0]);

	ans += min({left_b,left_a,right_b,right_a});

	cout<<ans<<endl;
}