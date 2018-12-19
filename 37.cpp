// https://codeforces.com/contest/786/problem/A
// SAMAJ NAHI AAYA JUST A TRY

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll MAXN = 7005;
// I am questioning life and universe and 
// everything else after looking at all this.

ll A[MAXN],B[MAXN];
ll visit[MAXN][2],win[MAXN][2],done[MAXN][2];

queue<pair<ll,ll>> Q;

ll N,K1,K2;

signed main(){
	FastRead;

	cin>>N;

	cin>>K1;
	for(ll i=1;i<=K1;i++) cin>>A[i];

	cin>>K2;
	for(ll i=1;i<=K2;i++) cin>>B[i];

	Q.push({0,0});
	Q.push({0,1});

	win[0][0] = win[0][1] = -1;

	while(!Q.empty()){
		pair<ll,ll> z = Q.front();
		Q.pop();

		ll x = z.first,y = z.second;

		if(visit[x][y]) continue;
		visit[x][y] = 1;

		if(y == 0){
			for(ll j=1;B[j];j++){
				if(win[x][y] == -1){
					win[(x-B[j]+N)%N][1] = 1;
					Q.push({(x-B[j]+N)%N,1});
				}else {
					done[(x-B[j]+N)%N][1]++;
					if(done[(x-B[j]+N)%N][1] == K2){
						win[(x-B[j]+N)%N][1] = -1;
						Q.push({(x-B[j]+N)%N,1});
					}
				}
			}
		}else {
			for(ll j=1;A[j];j++){
				if(win[x][y] == -1){
					win[(x-A[j]+N)%N][0] = 1;
					Q.push({(x-A[j]+N)%N,0});
				}else {
					done[(x-A[j]+N)%N][0]++;
					if(done[(x-A[j]+N)%N][0] == K1){
						win[(x-A[j]+N)%N][0] = -1;
						Q.push({(x-A[j]+N)%N,0});
					}
				}
			}
		}
	}

	for(ll i=1;i<N;i++){
		if(win[i][0] == 1) cout<<"Win ";
		else if(win[i][0] == -1) cout<<"Lose ";
		else cout<<"Loop ";
	}

	cout<<endl;

	for(ll i=1;i<N;i++){
		if(win[i][1] == 1) cout<<"Win ";
		else if(win[i][1] == -1) cout<<"Lose ";
		else cout<<"Loop ";
	}

}