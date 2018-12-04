// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/ratio-d0549bb2/description/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

int main(){
	FastRead;

	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		vector<ll> val;
		vector<char> c;

		ll prev = -1;
		for(ll i=0;i<n;i++){
			ll temp_val; char temp_c;
			cin>>temp_val>>temp_c;

			if(prev == temp_c){
				val.back() += temp_val;
			}else {
				val.push_back(temp_val);
				c.push_back(temp_c);
			}
			prev = temp_c;
		}


		n = val.size();
		ll a_count = 0,b_count = 0;

		for(ll i=0;i<n;i++){
			if(i%2 == 0) b_count += val[i];
			else a_count += val[i]; 
		}		

        ll a = a_count,b = b_count;
		ll prev_a = 0,prev_b = 0;
		ll i = 0,cnt = 0;
    
        if(a == 0||b == 0){
        	cout<<val.back()<<endl;
        	continue;
        }
        
		while(i<n){
			if(i%2 == 0){
				if(prev_a > 0 && b*prev_a % a == 0){
					ll req = b*prev_a/a;
					if(req - prev_b > 0 && req - prev_b <= val[i]){
						cnt++;
						prev_b = val[i] - (req-prev_b);
						prev_a = 0;
					}else {
						prev_b += val[i];
					}
				}else {
					prev_b += val[i];
				}   
			}else {
				if(prev_b > 0 && a*prev_b % b == 0){
					ll req = a*prev_b/b;
					if(req - prev_a > 0 && req - prev_a <= val[i]){
						cnt++;
						prev_a = val[i] - (req-prev_a);
						prev_b = 0;
					}else {
						prev_a += val[i];
					}
				}else {
					prev_a += val[i];
				}
			}
			i++;
		}

		cout<<cnt<<endl;
	}
}