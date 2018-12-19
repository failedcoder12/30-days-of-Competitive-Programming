// https://codeforces.com/contest/1093/problem/G

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
// I am questioning life and universe and 
// everything else after looking at all this.
#define MAXN 200005

ll n,k;

ll arr[MAXN][5];

struct data{
	ll max_arr[32];
	ll min_arr[32];
}seg[4*MAXN];

ll b[5];

void build(ll node,ll s,ll e){
	if(s>e) return;

	if(s == e){
		for(ll i=0;i<(1<<k);i++){
			ll curr = 0;
			for(ll j=0;j<k;j++){
				if(i&(1<<j)) curr+=arr[s][j];
				else curr-=arr[s][j];
			}
			seg[node].max_arr[i] = curr;
			seg[node].min_arr[i] = curr;
		}
		return;
	}

	ll mid = (s+e)>>1;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);

	for(ll i=0;i<(1<<k);i++){
		seg[node].max_arr[i] = max(seg[2*node].max_arr[i],seg[2*node+1].max_arr[i]);
		seg[node].min_arr[i] = min(seg[2*node].min_arr[i],seg[2*node+1].min_arr[i]);
	}
}

void update(ll node,ll s,ll e,ll pos){
	if(s>e) return;

	if(s == e){
		for(ll i=0;i<(1<<k);i++){
			ll curr = 0;
			for(ll j=0;j<k;j++){
				if(i&(1<<j)) curr+=b[j];
				else curr-=b[j];
			}
			seg[node].max_arr[i] = curr;
			seg[node].min_arr[i] = curr;
		}
		return;
	}

	ll mid = (s+e)>>1;
	if(pos<=mid) update(2*node,s,mid,pos);
	else update(2*node+1,mid+1,e,pos);

	for(ll i=0;i<(1<<k);i++){
		seg[node].max_arr[i] = max(seg[2*node].max_arr[i],seg[2*node+1].max_arr[i]);
		seg[node].min_arr[i] = min(seg[2*node].min_arr[i],seg[2*node+1].min_arr[i]);
	}	
}

pair<ll,ll> query(ll node,ll s,ll e,ll qs,ll qe,ll x){
	if(s>e || qe<s || qs>e) return make_pair(INT_MIN,INT_MAX);

	if(qs<=s && e<=qe){
		return make_pair(seg[node].max_arr[x],seg[node].min_arr[x]);
	} 

	ll mid = (s+e)>>1;
	pair<ll,ll> left = query(2*node,s,mid,qs,qe,x);
	pair<ll,ll> right = query(2*node+1,mid+1,e,qs,qe,x);

	return make_pair(max(left.first,right.first),min(left.second,right.second));
}

signed main(){
	FastRead;

	cin>>n>>k;

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}

	build(1,1,n);
	ll q; cin>>q;

	while(q--){
		ll type; cin>>type;

		if(type == 1){
			ll pos;
			cin>>pos;
			for(ll i=0;i<k;i++) cin>>b[i];
			update(1,1,n,pos);
		}else {
			ll l,r; cin>>l>>r;
			ll ans = 0;
			for(ll i=0;i<(1<<k);i++){
				pair<ll,ll> xx = query(1,1,n,l,r,i);
				ans = max(ans,xx.first-xx.second);
			}
			cout<<ans<<"\n";
		}
	}
}
