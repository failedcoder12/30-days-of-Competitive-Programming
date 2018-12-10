// https://codeforces.com/contest/982/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100005

// DP SAMAJ NA AAE, GRAPH TOH UPAR SE JAE :)
// I am questioning life and universe and everything else after looking at DP and GRAPH

ll parent[MAXN],siz[MAXN];
pair<ll,ll> arr[MAXN];
map<ll,ll> sizes;
bool visit[MAXN];

ll find_parent(ll x){
	if(x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}

void unionn(ll x,ll y){
	x = find_parent(x),y = find_parent(y);

	if(x == y) return;

	if(siz[x] < siz[y]) swap(x,y);

	sizes[siz[x]]--,sizes[siz[y]]--;

	if(sizes[siz[x]] == 0) sizes.erase(siz[x]);
	if(sizes[siz[y]] == 0) sizes.erase(siz[y]);

	siz[x] += siz[y];
	parent[y] = parent[x];

	sizes[siz[x]]++;
}

int main(){
	FastRead;

	ll n,ans = 0,prev_size = 0;
	cin>>n;

	for(ll i=1;i<=n;i++){
		cin>>arr[i].first; arr[i].second = i;
		parent[i] = i,siz[i] = 1;
	} 

	sort(arr+1,arr+n+1);

	for(ll i=1;i<=n;i++){
		ll val = arr[i].first,pos = arr[i].second;
		sizes[1]++;
		visit[pos] = true;

		if(visit[pos-1]) unionn(pos,pos-1);
		if(visit[pos+1]) unionn(pos,pos+1);

		if(sizes.size() == 1 && sizes.begin()->second > prev_size){
			ans = val+1,prev_size = sizes.begin()->second;
		}
	}

	cout<<ans<<endl;
}