// https://www.codechef.com/problems/HPIRATES

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define N 105

ll n,m;
vector<ll> graph[N];
ll height[N];
ll width[N];
ll visit[N];
ll grid[1002][1003];
bool isTree = false;

void dfs_tree(ll u,ll p){
	visit[u] = true;

	for(ll v:graph[u]){
		if(v!=p){
			if(visit[v]) isTree = false;
			else dfs_tree(v,u);
		}
	}
}

void dfs_width(ll u,ll p){
	height[u] = 0,width[u] = 0;

	for(ll v:graph[u]){
		if(v != p){
			dfs_width(v,u);
			height[u] = max(height[u],height[v]);
			width[u] += width[v] + 1;
		}
	}
	height[u]++,width[u]++;
}

void dfs_fill_grid(ll u,ll p,ll x,ll y,ll color){

	for(ll i=x;i<x+height[u];i++){
		for(ll j=y;j<y+width[u];j++){
			grid[i][j] = color;
		}
	}

	ll curr = y;

	for(ll v:graph[u]){
		if(v!=p){
			curr++;
			dfs_fill_grid(v,u,x,curr,1-color);
			curr += width[v];
		}
	}
}

int main(){
	FastRead;

	cin>>n>>m;

	for(ll i=0;i<m;i++){
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(ll i=1;i<=n;i++) visit[i] = false;

	isTree = true;
	dfs_tree(1,-1);
	
	for(ll i=1;i<=n;i++) if(visit[i] == false) isTree = false;

	if(!isTree){ 
		cout<<"-1\n"; 
		return 0;
	}

	dfs_width(1,-1);
	cout<<height[1]<<" "<<width[1]<<"\n";

	dfs_fill_grid(1,-1,0,0,0);

	for(ll i=0;i<height[1];i++){
		for(ll j=0;j<width[1];j++){
			cout<<grid[i][j];
		}
		cout<<"\n";
	}

}