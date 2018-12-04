// https://code.google.com/codejam/contest/dashboard?c=9234486#s=p1

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll double

// Expected value (e[k]) = (Summation) max(vi,e[k-1])/N

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin>>t;

    for(int tt = 1;tt<=t;tt++){

    	cout<<"Case #"<<tt<<": ";
    	int n,k;
    	cin>>n>>k;

    	ll v[n];

    	for(int i=0;i<n;i++) cin>>v[i];

    	sort(v,v+n);

    	ll sum[n];
    	sum[0] = v[0];

    	for(int i=1;i<n;i++) sum[i] = sum[i-1]+v[i];

    	ll ans = 0;
    	for(int i=0;i<k+1;i++){
    		int pos = upper_bound(v,v+n,ans)-v;
    		if(v[pos] > ans) pos--;
    		if(pos < 0 || pos >= n){
    			ans = (sum[n-1]/n);
    			continue;
    		}
    		ll temp_ans = (pos+1)*ans;
    		temp_ans += sum[n-1]-sum[pos];

    		ans = temp_ans/n;
    	}

    	cout<<fixed<<setprecision(7)<<ans<<endl;
    }

}