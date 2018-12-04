// https://www.hackerearth.com/problem/algorithm/digit-deletion-927a9262/description/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

// LOWER BOUND OR NEAREST POSITION CAN BE USED TO FIND A PERMUTATION 
// OR ALL THE POSSIBLE PERMUTATION

ll dp[101][1024];
vector<ll> pos[10];
ll final_mask;
string n;

ll solve(ll i,ll mask){

	if(mask == final_mask) return 1;
	if(i>=n.size()) return 0;

	if(dp[i][mask] != -1) return dp[i][mask];

	ll ans = 0;

	for(ll di = 0;di<10;di++){
		if(mask & (1<<di)) continue;

		ll x = lower_bound(pos[di].begin(),pos[di].end(),i) - pos[di].begin();

		if(x!=pos[di].size()) ans += solve(pos[di][x] + 1,(mask|(1<<di)));
	}

	return dp[i][mask] = ans;
}

int main(){
	FastRead;

	ll t;
	cin>>t;

	while(t--){
		final_mask = 0;
		
		cin>>n;

		for(ll i=0;i<10;i++) pos[i].clear();

		for(ll i=0;i<n.size();i++) pos[n[i]-'0'].push_back(i);

		for(ll i=0;i<n.size();i++) final_mask |= (1<<(n[i]-'0'));

		memset(dp,-1,sizeof(dp));

		cout<<solve(0,0)<<endl;
	}
}