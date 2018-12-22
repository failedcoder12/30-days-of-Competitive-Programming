// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/question-5-34/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(1);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
#define s second
#define pb push_back
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// I am questioning life and universe and 
// everything else after looking at all this.
ll n,m;
const ll MAXN = 3e5+3;
vector<ll> graph[MAXN];
bool visit[MAXN],articulate[MAXN];
ll discover[MAXN],low[MAXN],arr[MAXN];
ll tim = 0;
ll total = 0;
ll subsum[MAXN],answer[MAXN];
 
void dfs(ll u,ll p){
	visit[u] = true;
	discover[u] = low[u] = ++tim;
 
	ll sum = arr[u];
	subsum[u] = arr[u];
	ll child = 0;
	for(ll v:graph[u]){
		if(v == p) continue;
 
		if(visit[v]){
			low[u] = min(low[u],discover[v]);
		}else {
			child++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			subsum[u] += subsum[v];
			if(low[v]>=discover[u] && p!=0){
				articulate[u] = true;
				answer[u] ^= subsum[v];
				sum += subsum[v];
			}
			if(p == 0 && child>1){
				articulate[u] = true;
				answer[u] ^= subsum[v];
				sum += subsum[v];	
			}
		}
	}
	
	answer[u] ^= (total-sum);
}
 
signed main(){
	FastRead;
	cin>>n>>m;
 
	FOR(i,1,n) cin>>arr[i],total+=arr[i];
 
	FOR(i,1,m){
		ll u,v; cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
 
	ll ans = -1;
	dfs(1,0);
	FOR(i,1,n) if(articulate[i]) ans = max(ans,answer[i]);
 
	cout<<ans<<endl;
}