// https://codeforces.com/contest/597/problem/C

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100001
// I am questioning life and universe and 
// everything else after looking at all this.

ll arr[MAXN],bit[12][MAXN];
ll n;

void update(ll idx,ll i,ll val){
	for(;i<=n;i+=(i&(-i))){
		bit[idx][i] += val;
	}
}

ll sum(ll idx,ll i){
	ll sum = 0;
	for(;i>0;i-=(i&(-i))){
		sum += bit[idx][i];
	}
	return sum;
}

int main(){
	FastRead;

	ll k;
	cin>>n>>k;

	for(ll i=1;i<=n;i++) cin>>arr[i];

	for(ll i=1;i<=n;i++){
		update(1,arr[i],1);
		clog<<sum(1,arr[i]);
		for(ll c=2;c<=k+1;c++){
			update(c,arr[i],sum(c-1,arr[i]-1));
		}
	}

	cout<<sum(k+1,n)<<endl;
}