// https://codeforces.com/contest/1089/problem/K

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 2000005
struct data {
	ll val,lazy;
}seg[4*MAXN];

void build(ll node,ll s,ll e){
	if(s>e) return;
	if(s == e){ seg[node].val = s;return; }

	ll mid = (s+e)>>1;

	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node].val = max(seg[2*node].val,seg[2*node+1].val);
}

void propogate(ll node,ll s,ll e){
	if(seg[node].lazy){
		seg[node].val += seg[node].lazy;
		if(s != e){
			seg[2*node].lazy += seg[node].lazy;
			seg[2*node+1].lazy += seg[node].lazy;	
		}
		seg[node].lazy = 0;
	}
}

void update(ll node,ll s,ll e,ll qs,ll qe,ll val){
	propogate(node,s,e);
	if(qe < s||qs > e||s>e){
		return;
	}

	if(qs<=s && e<=qe){
		seg[node].lazy += val;
		propogate(node,s,e);
		return;
	}

	ll mid = (s+e)>>1;

	update(2*node,s,mid,qs,qe,val);
	update(2*node+1,mid+1,e,qs,qe,val);
	seg[node].val = max(seg[2*node].val,seg[2*node+1].val);
}

ll query(ll node,ll s,ll e,ll qs,ll qe){
	propogate(node,s,e);
	if(qe < s||qs > e||s>e){
		return 0;
	}

	if(qs<=s && e<=qe){
		return seg[node].val;
	}

	ll mid = (s+e)>>1;

	return max(query(2*node,s,mid,qs,qe),query(2*node+1,mid+1,e,qs,qe));
}

int main(){
	FastRead;

	ll q;
	cin>>q;
	pair<ll,ll> knights[MAXN];
	ll count = 1;
	build(1,1,MAXN);
	while(q--){
		char type;cin>>type;

		if(type == '+'){
			ll t,d;cin>>t>>d;
			knights[count++] = make_pair(t,d);
			update(1,1,MAXN,1,t,d);
		}else if(type == '-'){
			count++;
			ll i;cin>>i;
			update(1,1,MAXN,1,knights[i].first,-knights[i].second);
		}else {
			count++;
			ll t;cin>>t;
			cout<<query(1,1,MAXN,1,t)-query(1,1,MAXN,t+1,t+1)+1<<endl;
		}
	}
}