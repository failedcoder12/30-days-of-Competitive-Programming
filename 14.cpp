// https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/substring-deletion-eda3c1ec/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

// Masking can be used over all the alphabets

string s,ans;
ll mask[4000002];
vector<ll> indexs[26];

int main(){

    while(cin>>s){
    	
    	ll n = s.length();
    	mask[n] = 0;

    	for(ll i=n-1;i>=0;i--) mask[i] = mask[i+1]|(1<<(s[i]-'a'));

    	for(ll i=0;i<26;i++) indexs[i].clear();

    	for(ll i=0;i<n;i++) indexs[s[i]-'a'].push_back(i);

    	ans.clear();

    	ll done = 0,ptr = 0;

    	for(ll j=0;j<26;j++){
    		for(ll i=0;i<26;i++){
    			if((mask[0] & (1<<i)) == 0) continue;
    			if((done & (1<<i))) continue;

    			ll x = lower_bound(indexs[i].begin(),indexs[i].end(),ptr)-indexs[i].begin();

    			if((mask[indexs[i][x]+1] | done | (1<<i)) == mask[0]){
    				done |= (1<<i);
    				ans.push_back(i+'a');
    				ptr = indexs[i][x]+1;
    				break;
    			}
    		}
    	}

    	cout<<ans<<endl;
    }
}
