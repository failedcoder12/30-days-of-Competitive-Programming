// http://codeforces.com/contest/1082/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int 
const ll N = 1e5 + 5;
ll best[N];

int main(){
	FastRead;

	ll n,m;
	cin>>n>>m;

	vector<ll> specialize[m+1];
	for(ll i=0;i<n;i++){
		ll s,r;
		cin>>s>>r;
		specialize[s+1].push_back(r);
	}

	for(ll i=1;i<=m;i++) sort(specialize[i].begin(),specialize[i].end());


	for(ll i=1;i<=m;i++){
		ll curr = 0;
		for(ll j=0;j<specialize[i].size();j++){
			curr += specialize[i][j];
			if(curr < 0) break;
			best[j+1] += curr;
		}
	}

	ll ans = 0;
	for(ll i=1;i<=n;i++){
		ans = max(ans,best[i]);
	}

	cout<<ans<<endl;
}