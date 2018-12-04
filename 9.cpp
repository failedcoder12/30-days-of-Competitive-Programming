// https://www.hackerrank.com/contests/hourrank-31/challenges/save-the-queen/

#include<bits/stdc++.h>
using namespace std;
#define ll double

int main(){

    int n,k;
    cin>>n>>k;

    ll a[k];

    for(int i=0;i<k;i++) cin>>a[i];

    sort(a,a+k);reverse(a,a+k);
    ll s = 0,e = accumulate(a,a+k,0);
    
    auto possible = [&](ll val){
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(a[i] >= val) continue;
            else sum += val-a[i];
        }    

        ll sum2 = 0;
        for(int i=n;i<k;i++){
            sum2 += a[i];
        }
        return (sum<=sum2);
    };

    ll ans = 0;
    while(abs(e-s)>(1e-5)){
        ll mid = (s+e)/2;

        if(possible(mid)){
            s = mid+0.00001;
            ans = mid;
        }else {
            e = mid-0.00001;
        }
    }
    
    cout<<fixed<<setprecision(5)<<ans<<endl;
}