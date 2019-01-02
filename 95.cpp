// https://codeforces.com/contest/568/problem/A
// Number of primes not greater than n = n/logn
// Number of Palindrome less than n = n^(1/2)

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

ll pi[1300005],rub[1300005],A[12];

ll palin(ll N){
	ll m = 0;
	while(N){
		A[m++] = N%10;
		N = N/10;
	}

	for(ll i=0,j=m-1;i<=j;i++,j--){
		if(A[i] != A[j]) return 0;
	}
	return 1;
}

signed main(){
	FastRead;

	memset(pi,1LL,sizeof(pi));
	pi[0] = 0,pi[1] = 0;
	FOR(i,2,1200){
		if(pi[i]){
			for(ll j=i*i;j<=1300000;j+=i){
				pi[j] = 0;
			}
		}
	}

	FOR(i,1,1300000){
		rub[i] = rub[i-1];
		if(palin(i)) rub[i]++;
		pi[i] += pi[i-1];
	}

	ll P,Q;
	cin>>P>>Q;
	ll ans = 0;

	FOR(i,1,1300000){
		if(pi[i]*Q<=rub[i]*P){
			ans = i;
		}
	}

	if(ans) cout<<ans<<endl;
	else cout<<"Palindromic tree is better than splay tree\n";
}