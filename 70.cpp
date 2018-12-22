// https://codeforces.com/contest/598/problem/D

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

const ll MAXN = 1001;
ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};

ll n,m,c; 
ll idx = 0;
char a[MAXN][MAXN];
ll anss[MAXN][MAXN];
bool visit[MAXN][MAXN];

vector<ll> ans;

ll check(ll x,ll y){
	if(x<=0 || y<=0 || x>n || y>m) return 0;
	if(a[x][y] == '*') return 2;
	return 1;
}

void bfs(ll starti,ll startj){

	ll an = 0;
	queue<pair<ll,ll>> q;
	q.push({starti,startj});
	visit[starti][startj] = true;

	while(!q.empty()){
		ll x = q.front().f,y = q.front().s;
		anss[x][y] = idx;
		q.pop();
		FOR(i,0,3){
			ll nextx = x+dx[i],nexty = y+dy[i];
			ll temp = check(nextx,nexty);
			if(temp == 0 || visit[nextx][nexty]) continue;
			else if(temp == 2) an++;
			else {
				q.push({nextx,nexty});
				visit[nextx][nexty] = true;
			}
		}
	}
	ans.push_back(an);
	idx++;
}

signed main(){
	FastRead;

	cin>>n>>m>>c;

	FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];

	FOR(i,1,n) FOR(j,1,m) if(!visit[i][j] && a[i][j] == '.') bfs(i,j);

	FOR(i,1,c){
		ll x,y; cin>>x>>y;
		cout<<ans[anss[x][y]]<<endl;
	}
}