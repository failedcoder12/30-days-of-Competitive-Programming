// Learning Fast Min and Max
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
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.
const int MAXN = 1001;
int a[MAXN][MAXN];
ll w,h;

signed main(){
	FastRead;
	cin>>h>>w;

	FOR(y,0,h-1) FOR(x,0,w-1) cin>>a[y][x];

	int ans = -1;

	FOR(y1,0,h-1){
		FOR(y2,y1+1,h-1){
			int m1 = -1,m2 = -1;
			FOR(x,0,w-1){
				const int v = fastMin(a[y1][x],a[y2][x]);
				if(m1<v){m2 = m1; m1 = v;}
				else if(m2<v){m2 = v;}
			}
			ans = fastMax(ans,m2);
		}
	}
	cout<<ans<<'\n';
}