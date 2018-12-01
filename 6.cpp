// https://www.codechef.com/problems/GIVEAWAY

// POLICY BASED DATA STRUCTURE

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
#define MAXN 500005

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

using namespace std;
ll arr[MAXN];

vector<pbds> seg(4*MAXN);

void build(ll node,ll s,ll e){
	if(s == e) {
		seg[node].insert(arr[s]);
		return;
	}

	ll mid = (s+e)>>1;

	build(2*node,s,mid);
	build(2*node+1,mid+1,e);

	for(auto it:seg[2*node]) seg[node].insert(*it);
	for(auto it:seg[2*node+1]) seg[node].insert(*it);		
}


ll query(ll node,ll s,ll e,ll qs,ll qe,ll c){
	if(qe<s || qs>e || s>e) return 0;

	if(qs<=s && e<=qe) return seg[node].size()-seg[node].order_of_key(c);

	ll mid = (s+e)>>1;

	return query(2*node,s,mid,qs,qe,c) + query(2*node+1,mid+1,e,qs,qe,c);
}

void update(ll node,ll s,ll e,ll idx,ll val){

	if(s>e) return;

	seg[node].erase(seg[node].find(arr[idx]));
	seg[node].insert(val);

	if(s == e) {
		arr[idx] = val;
		return;
	}

	ll mid = (s+e)>>1;

	if(idx<=mid) update(2*node,s,mid,idx,val);
	else update(2*node+1,mid+1,e,idx,val);
}

int main(){
	FastRead;

	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++) cin>>arr[i];

	build(1,1,n);

	ll q;
	cin>>q;

	while(q--){
		ll type;
		cin>>type;
		if(type == 0){
			ll a,b,c;
			cin>>a>>b>>c;
			cout<<query(1,1,n,a,b,c)<<"\n";
		}else {
			ll a,b;
			cin>>a>>b;
			update(1,1,n,a,b);
		}
	}
}