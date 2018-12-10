// https://csacademy.com/contest/archive/task/and-closure/statement/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll kMaxVal = 1e6, kMaxBit = 20,kMaxN = 1e5,kUnavailable = (1<<(kMaxN+1))-1;

// Khatarnak Question on BIT and DP

ll dp[kMaxVal + 1];

int main(){
	FastRead;

	for(ll i=0;i<kMaxVal;i++) dp[i] = kUnavailable;

	ll n;
	cin>>n;

	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		dp[x] = x;
	}

	ll answer = 1;
	for(ll i=kMaxVal-1;i>=1;i--){
		if(dp[i] == i){
			answer++;
		}

		for(ll bit=0;bit<=kMaxBit;bit++){
			if(i&(1<<bit)){
				dp[i^(1<<bit)] &= dp[i];
			}
		}
	}

	cout<<answer<<endl;
}