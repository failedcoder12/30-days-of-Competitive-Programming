// http://codeforces.com/contest/1082/problem/E

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 500005
ll last_pos[MAXN];

int main(){
	FastRead;

	memset(last_pos,-1,sizeof(last_pos));
	ll n,c;
	cin>>n>>c;

	ll a[n],prefix[n],suffix[n],best_suffix[n];

	for(ll i=0;i<n;i++) cin>>a[i];

	suffix[0] = (a[0] == c); prefix[n-1] = (a[n-1] == c);

	for(ll i=1;i<n;i++) suffix[i] = suffix[i-1] + (a[i]==c);

	for(ll i=n-2;i>=0;i--) prefix[i] = prefix[i+1] + (a[i]==c);

	last_pos[a[0]] = 0;

	best_suffix[0] = 1;

	for(ll i=1;i<n;i++){
		best_suffix[i] = suffix[i-1] + 1;

		ll last = last_pos[a[i]];

		if(last >= 0){
			best_suffix[i] = max(best_suffix[last]+1,best_suffix[i]);
		}

		last_pos[a[i]] = i;
	}

	ll ans = best_suffix[n-1];

	for(ll i=0;i<n-1;i++){
		ans = max(ans,best_suffix[i]+prefix[i+1]);
	}

	cout<<ans<<endl;
}