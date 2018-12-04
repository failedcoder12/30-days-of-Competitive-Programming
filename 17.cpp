// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/clothes-arrangement-2ef4d85b/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;
#define MAXN 100005
#define MXA 1000006
rb_tree r_tree[MAXN];
ll bit[MXA];

// Great Use of RBTREE

void update(ll pos){
	for(ll i=pos;i<MXA;i += (i&-i)){
		bit[i] += -1;
	}
}

ll query(ll pos){
	ll ans = 0;

	for(ll i=pos;i>0;i-=(i&-i)){
		ans += bit[i];
	}

	return ans;
}

int main(){
	FastRead;

	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++){
		ll x; cin>>x;
		r_tree[x].insert(i);
	}

	ll q;
	cin>>q;
	while(q--){
		ll type;
		cin>>type;

		if(type == 1){
			ll c; cin>>c;
			r_tree[c].insert(++n);
			continue;
		}

		ll c,k; cin>>c>>k;

		if(r_tree[c].size() < k){
			cout<<"-1\n";
			continue;
		}

		auto it = r_tree[c].find_by_order(r_tree[c].size()-k);
		
		ll pos = *it;
		r_tree[c].erase(it);
		update(pos);

		cout<<n+query(n)-(pos+query(pos))<<"\n";
	}
}