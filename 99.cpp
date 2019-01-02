// https://codeforces.com/contest/283/problem/A

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

const ll MAXN = 2e5+5;
ll n = 1,q;
double sum = 0;
ll a[MAXN],bit[MAXN];

void update(ll idx,ll val){
	for(;idx<=MAXN;idx+=(idx&(-idx))){
		bit[idx] += val;
	}
}

ll summ(ll idx){
	ll ret = 0;
	for(;idx>0;idx-=(idx&(-idx))){
		ret += bit[idx];
	}
	return ret;
}

signed main(){
	FastRead;

	cin>>q;
	while(q--){
		ll type; cin>>type;

		if(type == 1){
			ll a,x; cin>>a>>x;
			sum += x*a;
			update(1,x);
			update(a+1,-x);
		}else if(type == 2){
			ll k; cin>>k;
			sum += k;
			n++;
			update(n,k);
			update(n+1,-k);
		}else {
			ll su = summ(n);
			sum -= su;
			update(n,-su);
			update(n+1,su);
			n--;
		}

		double avg = sum/n;
		cout<<fixed<<setprecision(7)<<avg<<endl;
	}

}