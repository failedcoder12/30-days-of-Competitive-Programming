https://codeforces.com/contest/982/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100005
// I am questioning life and universe and 
// everything else after looking at all this.

vector<ll> graph[MAXN];
ll subtree[MAXN];
ll ans = 0;
void dfs(ll u,ll p){

	subtree[u] = 1;
	for(ll v:graph[u]){
		if(v!=p){
			dfs(v,u);
			subtree[u] += subtree[v];
		}
	}

	if(subtreeu[u]%2 == 0){
		ans++;
	}
}

int main(){
	ll n;
	cin>>n;

	for(ll i=1;i<n;i++) {
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if(n%2 == 1){
		cout<<"-1\n";
		return 0;
	}

	dfs(1,0);
	cout<<ans-1<<endl;
}