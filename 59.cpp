// https://codeforces.com/contest/329/problem/B

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
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.

ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};

ll n,m; 
bool check(ll x,ll y){
	if(x<=0 || y<=0 || x>n || y>m) return false;
	return true;
}

signed main(){
	FastRead;
	cin>>n>>m;

	char a[n+1][m+1];

	FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];

	bool visit[n+1][m+1];
	ll dist[n+1][m+1];
	FOR(i,1,n) FOR(j,1,m) dist[i][j] = 1e7;
	ZERO(visit);

	queue<pair<ll,ll>> q;
	ll firstx,firsty,lastx,lasty;

	FOR(i,1,n) FOR(j,1,m) if(a[i][j] == 'E'){
		q.push({i,j});
		firstx = i,firsty = j;
		visit[i][j] = true;
		dist[i][j] = 0;
	}else if(a[i][j] == 'S'){
	    lastx = i,lasty = j;
	}

	while(!q.empty()){

		ll x = q.front().f,y = q.front().s;
		q.pop();
		FOR(i,0,3){
			ll next_x = x+dx[i],next_y = y+dy[i];
    
			if(check(next_x,next_y)&&!visit[next_x][next_y] && a[next_x][next_y] != 'T'){
				q.push({next_x,next_y});
				visit[next_x][next_y] = 1;
				dist[next_x][next_y] = dist[x][y] + 1;
			}
		}
	}
    
	ll ans = 0;

	FOR(i,1,n){
		FOR(j,1,m){
			if(a[i][j] != 'E' && a[i][j] !='S' && a[i][j] != 'T' && a[i][j] != '0'){
				if(dist[i][j] <= dist[lastx][lasty]){
					ans += a[i][j]-'0';
				}
			}
		}
	}

	cout<<ans<<endl;
}