// https://codeforces.com/contest/276/problem/D
// NEED TO DO IT AGAIN 

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

string s1,s2;
ll dp[70][2][2][2][2];

string getBin(ll num){
	string res = "";
	while(num){
		res += ((num&1)+'0');
		num/=2;
	}
	reverse(all(res));
	return res;
}

ll solve(ll p,ll fl1,ll fl2,ll fr1,ll fr2){
	if(p == s1.size()){
		return 0;
	}

	if(dp[p][fl1][fl2][fr1][fr2]!=-1) return dp[p][fl1][fl2][fr1][fr2];

	ll min1 = 0,max1 = 1;

	if(!fl1 && (s1[p]=='1')) min1 = 1;
	if(!fl2 && (s2[p]=='0')) max1 = 0;

	ll min2 = 0,max2 = 1;
	if(!fr1 && (s1[p]=='1')) min2 = 1;
	if(!fr2 && (s2[p]=='0')) max2 = 0;

	ll res = 0;

	for(ll i=min1;i<=max1;i++){
		for(ll j=min2;j<=max2;j++){
			ll v = (i^j);
			ll add = 0;

			if(v == 1){
				ll step = s1.size()-p-1;
				add = (1LL<<step);
			}

			ll nfl1 = fl1,nfl2 = fl2,nfr1 = fr1,nfr2 = fr2;

			if(i>s1[p]-'0') nfl1 = 1;
			if(i<s2[p]-'0') nfl2 = 1;
			if(j>s1[p]-'0') nfr1 = 1;
			if(j<s2[p]-'0') nfr2 = 1;

			res = max(res,add+solve(p+1,nfl1,nfl2,nfr1,nfr2));
		}
	}

	return dp[p][fl1][fl2][fr1][fr2] = res;
}

signed main(){
	FastRead;

	ll l,r; cin>>l>>r;
	s1 = getBin(l);
	s2 = getBin(r);

	while(s1.size()<s2.size()){
		s1 = "0"+s1;
	}

	memset(dp,-1,sizeof(dp));

	ll ans = solve(0,0,0,0,0);

	cout<<ans<<endl;
}