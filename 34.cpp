// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/mr-x-and-string-4836920e/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
 
signed main(){
FastRead;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
 
    ll t; cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        string a[2];
        cin>>a[0]>>a[1];
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++) if(a[0][i]!=a[1][i]) v.push_back({i,0}),v.push_back({i,1});
        
        if(v.size() >= 7) cout<<"NO\n";
        else if(v.size() <= 2) cout<<"YES\n";
        else{
            bool ans = 0;
 
            for(ll i=0;i<v.size();i++){
                for(ll j=0;j<i;j++){
                    swap(a[v[i].second][v[i].first],a[v[j].second][v[j].first]);
                    
                    ll cc = 0;
                    for(ll k=0;k<n;k++){
                        if(a[0][k]!=a[1][k]){
                            cc++;
                        }
                    }                 
 
                    if(cc <= 1) ans = 1;
                    swap(a[v[i].second][v[i].first],a[v[j].second][v[j].first]);   
                }
            }
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
 
 
// #ifndef ONLINE_JUDGE
//     cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
// #endif
}