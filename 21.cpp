// https://csacademy.com/contest/archive/task/max-score-tree/statement/

// DP IS JUST LIKE GIRLS NA KARNE SE PEHLE SAMAJ AATA 
// AUR NA KARNE KE BAAD :P
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100005
ll cost[MAXN];
vector<ll> graph[MAXN];
bool visit[MAXN];
ll result = -1e10;

ll dfs_kind(ll u){
	visit[u] = true;
	vector<ll> children;

	for(ll v:graph[u]){
		if(!visit[v]) children.push_back(dfs_kind(v));
	}

	sort(children.begin(),children.end());
	reverse(children.begin(),children.end());

	ll best_for_parent = cost[1];
	ll current_cost = 0;

	for(ll i=0;i<children.size();i++){
		current_cost += children[i];
		best_for_parent = max(best_for_parent,current_cost + cost[i+2]);
		result = max(result,current_cost + cost[i+1]);
	}

	return best_for_parent;
}

int main(){
	FastRead;

	ll n;
	cin>>n;

	for(ll i=0;i<n;i++) cin>>cost[i];

	for(ll i=0;i<n-1;i++){
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	result = cost[0];
	dfs_kind(1);
	cout<<result<<endl;
}