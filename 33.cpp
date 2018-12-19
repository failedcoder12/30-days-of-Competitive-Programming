// https://www.spoj.com/problems/KATHTHI/
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.
 
ll n,m;
 
bool check(ll x,ll y){
	if(x<0||y<0||x>=n||y>=m) return false;
	return true;
}
 
ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};
 
int main(){
	FastRead;
 
	ll t;
	cin>>t;
 
	while(t--){
		cin>>n>>m;
 
		char a[n][m];
 
		bool visit[n][m];
 
		ll dist[n][m];
		for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) visit[i][j] = 0,dist[i][j] = 3e7;
		
		for(ll i=0;i<n;i++)for(ll j=0;j<m;j++) cin>>a[i][j];
 
		deque<pair<ll,ll>> q;
 
		q.push_front({0,0});
		dist[0][0] = 0;
 
		while(!q.empty()){
			ll x_top = q.front().first;
			ll y_top = q.front().second;
            visit[x_top][y_top] = true;
			q.pop_front();
            
			for(ll i=0;i<4;i++){
				ll next_x = x_top + dx[i];
				ll next_y = y_top + dy[i];
 
				if(check(next_x,next_y) &&
				dist[next_x][next_y] > dist[x_top][y_top] + (a[x_top][y_top] != a[next_x][next_y])){
					dist[next_x][next_y] = dist[x_top][y_top] + (a[x_top][y_top] != a[next_x][next_y]);
 
					if((a[x_top][y_top] == a[next_x][next_y])) q.push_front({next_x,next_y});
					else q.push_back({next_x,next_y});
				}
			}
		}
		cout<<dist[n-1][m-1]<<endl;
	}
} 