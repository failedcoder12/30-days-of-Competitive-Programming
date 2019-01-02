// https://www.codechef.com/problems/YVSTR

// JUST COPY PASTED FROM EDITORIAL 
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
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at all this.

ll single[30];
vector<pair<ll,ll>> v[30][30];

ll calc(ll a,ll b){
	sort(v[a][b].begin(),v[a][b].end());
	vector<pair<ll,ll>> vec;

	for(auto P:v[a][b]){
		while(!vec.empty()&&vec.back().s <=P.s){
			vec.pop_back();
		}
		vec.pb(P);
	}

	ll last = 0,ans = 0;

	for(auto P:vec){
		ans += (P.f-last)*P.s;
		last = P.f;
	}

	return ans;
}

signed main(){
	FastRead;

	ll t; cin>>t;

	while(t--){
		string s; ll n;
		cin>>n>>s;

		ll last = -1,c = 0;

		for(ll i=0;i<30;i++){
			single[i] = 0;
			for(ll j=0;j<30;j++){
				v[i][j].clear();
			}
		}

		vector<pair<ll,ll>> letters;
		for(ll i=0;i<s.length();i++){
			if(s[i]!=last){
				if(i) letters.push_back({last,c});
				last = s[i];
				c = 1;
			}else c++;
		}
		if(c) letters.push_back({last,c});

		for(ll i=0;i<letters.size();i++){
			ll let = letters[i].f - 'a';
			single[let] = max(single[let],letters[i].s);
		}

		for(ll i=0;i+1<letters.size();i++){
			ll a = letters[i].f-'a',b = letters[i+1].f-'a';
			v[a][b].pb({letters[i].s,letters[i+1].s});
		}

		ll ans = 0;

		for(ll i=0;i<26;i++){
			ans += single[i];
			for(ll j=0;j<26;j++){
				ans += calc(i,j);
			}
		}

		cout<<ans<<endl;
	}
}