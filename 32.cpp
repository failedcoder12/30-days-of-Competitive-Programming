// https://www.codechef.com/problems/FLIPCOIN

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.
const ll MAXN = 100002;
const ll SQRN = sqrt(MAXN+.0)+1;
ll a[MAXN];
ll sqa[SQRN];
bool reversed[SQRN];

ll type,l,r;
int main()
{
	FastRead;

	ll n,q;
	cin>>n>>q;

	while(q--){
		cin>>type>>l>>r;
		if(type == 1){
			ll c_l = l/SQRN,c_r = r/SQRN;

			ll ans = 0;
			if(c_l == c_r){
				if(!reversed[c_l])
					for(ll i=l;i<=r;i++){
						if(a[i] == 1) ans++;
					}
				else
					for(ll i=l;i<=r;i++){
						if(a[i] == 0) ans++;
					}
			}else {
				if(!reversed[c_l])
					for(ll i=l;i<(c_l+1)*SQRN;i++){
						if(a[i] == 1) ans++;
					}
				else
					for(ll i=l;i<(c_l+1)*SQRN;i++){
						if(a[i] == 0) ans++;
					}

				if(!reversed[c_r])
					for(ll i=c_r*SQRN;i<=r;i++){
						if(a[i] == 1) ans++;
					}
				else
					for(ll i=c_r*SQRN;i<=r;i++){
						if(a[i] == 0) ans++;
					}

				for(ll i=c_l+1;i<c_r;i++)
					ans += SQRN-sqa[i];
			}
			cout<<ans<<endl;
		}else {

			ll c_l = l/SQRN,c_r = r/SQRN;

			if(c_l == c_r){
				if(!reversed[c_l])
					for(ll i=l;i<=r;i++){
						a[i] = 1-a[i];
						if(a[i] == 1) sqa[c_l]++;
						else sqa[c_l]--;
					}
				else
					for(ll i=l;i<=r;i++){
						a[i] = 1-a[i];
						if(a[i] == 0) sqa[c_l]--;
						else sqa[c_l]++;
					}
			}else {
				if(!reversed[c_l])
					for(ll i=l;i<=(c_l+1)*SQRN;i++){
						a[i] = 1-a[i];
						if(a[i] == 1) sqa[c_l]++;
						else sqa[c_l]--;
					}
				else
					for(ll i=l;i<=(c_l+1)*SQRN;i++){
						a[i] = 1-a[i];
						if(a[i] == 0) sqa[c_l]--;
						else sqa[c_l]++;
					}


				if(!reversed[c_r])
					for(ll i=(c_r*SQRN);i<=r;i++){
						a[i] = 1-a[i];
						if(a[i] == 1) sqa[c_l]++;
						else sqa[c_l]--;
					}
				else
					for(ll i=(c_r*SQRN);i<=r;i++){
						a[i] = 1-a[i];
						if(a[i] == 0) sqa[c_l]--;
						else sqa[c_l]++;
					}

				for(ll i=c_l+1;i<c_r;i++){
					reversed[i] = 1-reversed[i];
					sqa[i] = SQRN-sqa[i];
				}
			}
		}
	}

}