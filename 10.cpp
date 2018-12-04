// https://code.google.com/codejam/contest/dashboard?c=9234486#s=p0

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin>>t;

    for(ll tt = 1;tt<=t;tt++){
        cout<<"Case #"<<tt<<": ";
    	ll n;
    	cin>>n;

    	ll pos = -1;
    	ll temp = n;
    	ll last_pos = 0;

    	ll j = 0;
    	while(temp){
    		ll temp2 = temp%10;
    		if(temp2%2 != 0){
    			pos = j;
    			last_pos = temp2;
    		}
    		j++;
    		temp = temp/10;
    	}
    	
    	if(pos == -1){
    	    cout<<0<<endl;
    	    continue;
    	}
    	
    	
    	ll poww = pow(10,pos);
    	ll ans = n%poww; 
        ll pp = 0;
    	ll temp3 = 0;
    	while(pp < pos){
    		temp3 = temp3*10 + 8;
    		pp++;
    	}
    	ans = ans + (poww - temp3);
    	if(last_pos != 9){
	    	ll ans2 = poww - n%poww;
	    	ans = min(ans,ans2);
	    	cout<<ans<<endl;
    	}else {
    	    cout<<ans<<endl;
    	}
    	
    }
}