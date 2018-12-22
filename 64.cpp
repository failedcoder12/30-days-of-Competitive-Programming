// https://codeforces.com/contest/220/problem/B

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
const ll N = 1e5+5;
const ll SQN = sqrt(N+.0)+1;
vector<pair<ll,pair<ll,ll>>> query;
ll cnt[N];

signed main(){
	FastRead;

	ll n,q; cin>>n>>q;

	ll a[n];

	FOR(i,0,n-1) cin>>a[i];

	FOR(i,0,q-1){
		ll l,r; cin>>l>>r; l--,r--;
		query.push_back(make_pair(i,make_pair(l,r)));
	}

	auto cmp = [&](pair<ll,pair<ll,ll>> &a,pair<ll,pair<ll,ll>> &b){
		if(a.s.f/SQN == b.s.f/SQN){
			return a.s.s<b.s.s;
		}
		return a.s.f<b.s.f;
	};

	sort(query.begin(),query.end(),cmp);

	ll answer = 0;
	ll ans[q];
	ZERO(ans);

	auto add =[&](ll val){
		if(val > 100000) return;
		if(cnt[val] == val) answer--;
		cnt[val]++;
		if(cnt[val] == val) answer++;
	};

	auto remove = [&](ll val){
		if(val > 100000) return;
		if(cnt[val] == val) answer--;
		cnt[val]--;
		if(cnt[val] == val) answer++;
	};

	ll s = 0,e = 0;
	for(ll i=0;i<query.size();i++){
		ll l = query[i].s.f,r = query[i].s.s;
		ll idx = query[i].f;
		
		while(s<l){
			remove(a[s]);
			s++;
		}

		while(s>l){
			s--;
			add(a[s]);
		}

		while(e<=r){
			add(a[e]);
			e++;
		}

		while(e>r+1){
			e--;
			remove(a[e]);
		}

		ans[idx] = answer;
	}

	FOR(i,0,q-1) cout<<ans[i]<<endl;
}