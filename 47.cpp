// https://codeforces.com/contest/494/problem/A

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	FastRead;
	
	string s;
	cin>>s;

	stack<ll> stac;
	ll last = -1;
	ll count = 0;
	for(ll i=0;i<s.length();i++){
		if(s[i] == '('){
			stac.push(i);
		}else {
			if(stac.empty()){
				cout<<"-1\n";
				return 0;
			}
			stac.pop();
			if(s[i] == '#'){
				last = i,count++;
			}
		}
	}

	ll k = stac.size();
	while(!stac.empty()){
		if(stac.top()>last){
			cout<<"-1\n";
			return 0;
		}
		stac.pop();
	}

	for(ll i=0;i<count-1;i++){
		cout<<"1\n";
	}
	cout<<1+k<<endl;
}