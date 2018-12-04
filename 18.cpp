// https://codeforces.com/contest/1088/problem/D
// Khatarnak Questiom

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

bool ask(ll x,ll y){
	cout<<'?'<<' '<<x<<' '<<y<<endl;
	ll ans;
	cin>>ans;

	return ans == -1;
}

void answer(ll a,ll b){
	cout<<'!'<<' '<<a<<' '<<b<<endl;
}

int main(){
	FastRead;

	bool swapped;

	ll a = 0,b = 0;
	swapped = ask(0,0);

	for(ll i=29;i>=0;i--){
		ll u = ask((swapped?b:a)^(1<<i),(swapped?a:b));
		ll v = ask((swapped?b:a),(swapped?a:b)^(1<<i));

		if(u == v){
			(swapped?b:a) ^= (1<<i);
			swapped = u;
		}else if(u){
			a ^= (1<<i);
			b ^= (1<<i);
		}
	}

	answer(a,b);
}