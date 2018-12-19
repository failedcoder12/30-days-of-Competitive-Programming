// https://www.hackerearth.com/challenge/competitive/december-easy-18/algorithm/meetup-point-61916d93/description/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 200005
// I am questioning life and universe and 
// everything else after looking at all this.
vector<ll> graph[MAXN];
ll lca[18][MAXN],level[MAXN];

void dfs(ll u,ll p,ll lvl){
	lca[0][i] = p;
	level[i] = lvl;

	for(ll v:graph[u]){
		if(v!=p){
			dfs(v,u,lvl+1);
		}
	}
}

ll getLCA(ll a,ll b){
	if(level[a] > level[b]) swap(a,b);
	ll dist = level[b] - level[a];

	for(ll i=17;i>=0;i--){
		if(dist & (1<<i)) b = lca[i][b];
	}

	if(a == b) return a;

	for(ll i=17;i>=0;i--){
		if(lca[i][a] != lca[i][b]){
			a = lca[i][a];
			b = lca[i][b];
		}
	}
	return lca[0][a];
}

ll getDist(ll a,ll b){
	return level[a]+level[b] - 2*level[getLCA(a,b)];
}

ll getNode(ll a,ll d){
	for(ll i=0;i<18;i++){
		if(d&(1<<i)) a = lca[i][a];
	}
	return a;
}

ll getCenter(ll a,ll b){
	ll dist = getDist(a,b);
	ll c = getLCA(a,b);

	if(level[a] - level[c] < level[b] - level[c]){
		swap(a,b);
	}

	if(dist%2 == 0) return getNode(a,dist/2);

	return min(getNode(a,dist/2),getNode(a,dist/2+1));
}

int main(){
	FastRead;
	
	ll n;
	cin>>n;

	for(ll i=0;i<n-1;i++){
		ll u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0,1);

	for(ll i=1;i<18;i++){
		for(ll j=1;j<=N;j++){
			lca[i][j] = lca[i-1][lca[i-1][j]];
		}
	}

	ll a,b;
	cin>>a;
	b = a;

	cout<<a<<" ";

	ll diameter = 0;
	for(ll i=2;i<=n;i++){
		ll c;
		cin>>c;

		ll lenA = getDist(a,c);
		ll lenB = getDist(b,c);
		if(lenA<lenB) swap(lenA,lenB),swap(a,b);
		if(lenA>diameter) diameter = lenA,b = c;

		cout<<getCenter(a,b)<<" ";
	}
}