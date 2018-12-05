// https://csacademy.com/contest/archive/task/divisor_clique/statement/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

int main(){
	FastRead;
	
	ll n;
	cin>>n;

	ll a[n];

	for(ll i=0;i<n;i++) cin>>a[i];

	sort(a,a+n);

	ll ans[n];
	for(ll i=0;i<n;i++) ans[i] = 0;
	ans[0] = 1;
	for(ll i=0;i<n;i++){
	    for(ll j=i+1;j<n;j++){
	        if(a[j]%a[i] == 0) ans[j] = ans[i] + 1;
	    }
	}

	ll count = *max_element(ans,ans+n);
	cout<<count<<endl;
}