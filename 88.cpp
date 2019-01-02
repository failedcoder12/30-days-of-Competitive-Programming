// https://codeforces.com/contest/243/problem/A

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
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
const ll MAXN = 1e5+2;
const ll BIT = 21;
const ll MMM = 1e7;
ll pre[MMM];

ll a[MAXN];
ll bit[BIT][MAXN];
ll bb[BIT][MAXN];
ll nextt[BIT][MAXN];

signed main(){
	FastRead;
	ll n; cin>>n;

	FOR(i,1,n){
		cin>>a[i];
		FOR(j,0,20){
			bit[j][i] = ((a[i]&(1<<j)) > 0);
			bb[j][i] = bit[j][i];
			bit[j][i] += bit[j][i-1];
		}
	}
	
	FOR(j,0,20){
		bit[j][n+1] = bit[j][n]+1;
	}
	

	ll ans = 0;
	FOR(i,1,n){
		ll ii = i;
		ll pres = 0;
		while(ii<=n){
			pres|=a[ii];
			if(pre[pres] == 0) ans++;
			pre[pres] = 1;
			ll minn = n+1;
			
			FOR(j,0,20){
				if((((pres)&(1<<j)) == 0)) nextt[j][ii] = upper_bound(bit[j]+ii,bit[j]+n+1,bit[j][ii])-bit[j],minn = min(minn,nextt[j][ii]);
			}

			ii = minn;
		}
	}
	
	cout<<ans<<endl;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define ll int
// #define FOR(i,a,n) for (int i=(a);i<=(n);++i)
// #define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
// #define FI(i,n) for (int i=0; i<(n); ++i)
// #define ZERO(a) memset((a),0,sizeof((a)))
// #define f first
// #define s second
// #define pb push_back
// // #include <ext/pb_ds/assoc_container.hpp> // Common file
// // #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// // using namespace __gnu_pbds;
// // typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// // I am questioning life and universe and 
// // everything else after looking at all this.

// const ll MAXN = 1e5+2;

// signed main(){
// 	FastRead;

// 	set<ll> g,s,s1;
// 	ll n; cin>>n;

// 	FOR(i,1,n){
// 		ll x; cin>>x;
// 		s1.insert(x);
// 		for(ll y:s){
// 			s1.insert(y|x);
// 		}
// 		s = s1;

// 		for(ll y:s){
// 			g.insert(y);
// 		}
// 		s1.clear();
// 	}

// 	cout<<g.size()<<endl;
// }