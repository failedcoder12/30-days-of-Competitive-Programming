// https://codeforces.com/contest/372/problem/B
// KHATARNAK QUESTION NEED TO SEE IT AGAIN

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
const ll N = 42;
ll check_rect[N][N][N][N];
ll ans[N][N][N][N];
ll arr[N][N];

signed main(){
	FastRead;

	ll n,m,q; cin>>n>>m>>q;

	FOR(i,1,n){
		FOR(j,1,m){
			char c; cin>>c;
			arr[i][j] = c-'0';
		}
	}

	FOR(i,1,n){
		FOR(j,1,m){
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}

	FOR(i,1,n){
		FOR(j,1,m){
			FOR(k,i,n){
				FOR(l,j,m){
					ll val = arr[k][l] - arr[i-1][l] - arr[k][j-1] + arr[i-1][j-1];
					if(val == 0) check_rect[i][j][k][l] = 1;
				}
			}
		}
	}

	FOR(i,1,n){
		FOR(j,1,m){
			FOR(k,i,n){
				FOR(l,j,m){
					ans[i][j][k][l] = ans[i][j][k-1][l] + ans[i][j][k][l-1] - ans[i][j][k-1][l-1] + check_rect[i][j][k][l];
				}
			}
		}
	}

	RFOR(k,1,n){
		RFOR(l,1,m){
			RFOR(i,1,k){
				RFOR(j,1,l){
					ans[i][j][k][l] += ans[i+1][j][k][l] + ans[i][j+1][k][l] - ans[i+1][j+1][k][l];
				}
			}
		}
	}

	while(q--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		cout<<ans[a][b][c][d]<<endl;
	}
}