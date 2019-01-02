// https://codeforces.com/contest/333/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.

const ll MAXN = 1001;
ll a[MAXN][MAXN];
ll go[MAXN][MAXN];
vector<ll> on[MAXN];

signed main(){
	FastRead;

	ll n,m; cin>>n>>m;

	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}

	vector<pair<ll,pair<ll,ll>>> g;

	FOR(i,1,n) FOR(j,1,m) g.pb(mk(a[i][j],mk(i,j)));

	sort(all(g));
	reverse(all(g));

	FOR(i,0,g.size()-1){
		ll x = g[i].s.f,y = g[i].s.s;	
		for(ll j=0;j<on[x].size();j++){
			ll y2 = on[x][j];
			ll y1 = y;
			if(go[y1][y2] != 0){
				cout<<g[i].f<<endl;
				return 0;
			}
			go[y1][y2] = go[y2][y1] = 1;
		}
		on[x].pb(y);
	}
}