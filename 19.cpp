// https://codeforces.com/contest/1088/problem/E

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 300005
ll weights[MAXN];
vector<ll> graph[MAXN];
ll ans = -1e9;
ll dp[MAXN];
ll k = 0;

void dfs_1(ll u,ll p){

	dp[u] = weights[u];

	for(ll v:graph[u]){
		if(v!=p){
			dfs_1(v,u);
			dp[u] += max(dp[v],0LL);
		}
	}

	ans = max(ans,dp[u]);
}

void dfs_2(ll u,ll p){
	dp[u] = weights[u];

	for(ll v:graph[u]){
		if(v!=p){
			dfs_2(v,u);
			dp[u] += max(dp[v],0LL);
		}
	}

	if(dp[u] == ans){
		dp[u] = 0;
		k++;
	}
}

int main(){
	FastRead;
	
	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++) cin>>weights[i];

	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs_1(1,0);
	dfs_2(1,0);

	cout<<ans*k<<" "<<k<<endl;
}