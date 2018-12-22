// https://codeforces.com/contest/404/problem/C
// WRONG BUT GALTI NAHI MILI

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(1);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define x f
#define y s
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 1e5 + 5;
vector<ll> graph[MAXN];
vector<ll> level[MAXN];
signed main(){

	ll n,k; cin>>n>>k;

	ll a[n+1];
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]>=n){
			cout<<-1<<endl;
			return 0;
		}
		level[a[i]].push_back(i);
	}

	if(level[0].size() == 0 || level[0].size()>1){
		cout<<-1<<endl;
		return 0;
	}

	if(level[1].size()>k){
		cout<<-1<<endl;
		return 0;
	}
	
	FOR(l,2,n){
		if(level[l].size() > 0 && level[l-1].size() == 0){
			cout<<-1<<endl;
			return 0;
		}

		if(level[l].size() > level[l-1].size()*(k-1)){
			cout<<-1<<endl;
			return 0;
		}
	}

	FOR(l,0,n-1){
		ll siz = level[l+1].size()-1;
		ll j = 0;
		ll z = k;
		while(siz>=0){
			if(z>0){
				graph[level[l][j]].push_back(level[l+1][siz]);
				z--;
			}else {
				j++;
				z = k;
				graph[level[l][j]].push_back(level[l+1][siz]);
				z--;
			}
			siz--;
		}
	}

	ll sum = 0;
	FOR(i,1,n){
		sum += graph[i].size();
	}

	if(sum != n-1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<n-1<<endl;

	FOR(i,1,n){
		for(ll j=0;j<graph[i].size();j++){
			cout<<i<<" "<<graph[i][j]<<endl;
		}
	}
}