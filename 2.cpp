// http://codeforces.com/contest/1082/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll SIZE = 400; 
vector<pair<ll,ll>> graph;

int main(){
	FastRead;

	vector<ll> leaves,non_leaves;
	ll n;
	cin>>n;

	ll non_leaf[n+1];
	memset(non_leaf,0,sizeof(non_leaf));
	vector<pair<ll,ll>> pairs;

	ll a[n+1],total_degree = 0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		total_degree += a[i];
		if(a[i] == 1) leaves.push_back(i);
		else non_leaves.push_back(i),non_leaf[i] = 1;
	}

	if(total_degree < 2*n -2){
		cout<<"NO\n";
		return 0;
	}

	ll ans = non_leaves.size();

	if(leaves.size() == 1) ans++;
	else if(leaves.size() > 1) ans += 2;

	cout<<"YES "<<ans-1<<endl;

	auto add_edge = [&](ll u,ll v){
		a[u]--,a[v]--;
		graph.push_back({u,v});
		return;
	};

	auto get_free = [&](){
		for(ll i=1;i<=n;i++){
			if(non_leaf[i] == 1 && a[i] > 0)
				return i;
		}
		return -1;
	};

	for(ll i=1;i<non_leaves.size();i++){
		add_edge(non_leaves[i-1],non_leaves[i]);
	}

	for(ll i=0;i<leaves.size();i++){
		if(i == 0) add_edge(leaves[i],non_leaves[0]);
		else if(i == 1) add_edge(leaves[i],non_leaves[non_leaves.size()-1]);
		else {
			ll p = get_free();
			add_edge(leaves[i],p);
		}
	}

	cout<<graph.size()<<endl;

	for(ll i=0;i<graph.size();i++) cout<<graph[i].first<<" "<<graph[i].second<<endl;
}