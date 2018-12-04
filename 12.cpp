// https://code.google.com/codejam/contest/dashboard?c=9234486#s=p2

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int

//NOT ABLE TO SOLVE IT :P

int main(){


    ll t;
    cin>>t;

    for(ll tt=1;tt<=t;tt++){
    	cout<<"Case #"<<tt<<": ";
    	ll l;
    	cin>>l;

    	string s[l];

    	for(ll i=0;i<l;i++) cin>>s[i];

    	char s1,s2;
    	ll n,a,b,c,d;
    	cin>>s1>>s2>>n>>a>>b>>c>>d;

    	vector<ll> check;

    	a = a%d,b = b%d,c = c%d;
    	check.push_back(0);
    	check.push_back(s1);
    	check.push_back(s2);
    	for(ll i=3;i<=n;i++){
    		ll x = (a*check[i-1] + b*check[i-2] + c)%d;
    		check.push_back(x);
    	}

    	string check_string = "";
    	check_string += s1;
    	check_string += s2;
    	for(ll i=3;i<=n;i++){
    		check_string += (char)(97 + check[i]%26);
    	}
    		
    	ll ans = 0;
    	for(ll i=0;i<l;i++){

    		vector<ll> freq(26,0),freq_in(26,0);
    		ll x = s[i].length();
    		for(ll j=0;j<x;j++){
    			freq_in[(ll)(s[i][j])-96]++;
    		}

    		for(ll j=0;j<x;j++){
    			freq[(ll)(check_string[j])-96]++;
    		}

    		if(freq == freq_in){
    			ans++;
    			continue;
    		}

    		for(ll j=x;j<check_string.length();j++){
    			freq[(ll)(check_string[j])-96]++;
    			freq[(ll)(check_string[j-x])-96]--;
				if(freq == freq_in){
    				ans++;
    				break;
    			}    			
    		}
    	}
    	cout<<ans<<endl;
    }
}