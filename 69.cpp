// https://codeforces.com/contest/653/problem/B

// KHATARNAK BRUTE FORCE QUESTIONS
// DEKH KAR BHI KABHI KABHI SAMAJ AAAE 

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
const ll M = 50;
ll a[M],b[M],n,q,ans,c[M];
char s[M],ss[M];

bool check(ll x){
	FOR(i,0,n-1) c[i] = x%10,x/=10;
	ll curr = 0;
	while(curr<n-1){
		ll bf = 0;
		FOR(i,0,q-1){
			if(a[i] == 10*c[curr]+c[curr+1]){
				bf = 1;c[++curr] = b[i]; break;
			}
		}
		if(!bf) return 0;
	}
	if(c[curr] == 0) return 1;
	else return 0;
}

void dfs(ll x,ll dp){
	if(dp == n){
		if(check(x)) ans++;
		return;
	}
	FOR(i,0,5){
		dfs(10*x+i,dp+1);
	}
}

signed main(){
	FastRead;
	cin>>n>>q;

	FOR(i,0,q-1){
		cin>>s>>ss;
		a[i] = (s[0]-'a')*10 + s[1]-'a';
		b[i] = ss[0]-'a';
	}

	dfs(0,0);
	cout<<ans<<endl;
}