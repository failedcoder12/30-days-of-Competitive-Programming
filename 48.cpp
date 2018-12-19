// https://www.codechef.com/problems/SQRTRI

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	FastRead;

	auto check = [&](ll h,ll b,ll l){
		return h*l >= ((h-l)*b);
	};

	ll t; cin>>t;

	while(t--){
		ll a,b,x,y;
		cin>>a>>b>>x>>y;

		if(check(x+b,a,b) || check(a-x,a,b) || check(y+b,a,b) || check(a-y,a,b)){
			cout<<"yes\n";
		}else {
			cout<<"no\n";
		}
	}
}