// https://code.google.com/codejam/contest/10284486/dashboard#s=p0

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
ll dp[20][10][2];
ll digit;
ll number[20];

ll solve(ll pos,ll sum,ll last_or_not){
	if(pos > digit){
		if(sum%9 == 0) return 0;
		return 1;
	}

	if(dp[pos][sum][last_or_not]!=-1) return dp[pos][sum][last_or_not];

	ll ans = 0;
	if(!last_or_not){
		ll last = number[pos];

		for(ll i=0;i<last;i++) ans += solve(pos+1,(sum+i)%9,1);
		
		if(last != 9) ans += solve(pos+1,(sum+last)%9,0);

		return dp[pos][sum][last_or_not] = ans;
	}else {
		for(ll i=0;i<9;i++) ans += solve(pos+1,(sum+i)%9,1);

		return dp[pos][sum][last_or_not] = ans;
	}
}

ll convert_to_digit(ll x){

	digit = 0;
	memset(number,0,sizeof(number));
	ll tmp = x;
	while(tmp){
		tmp /= 10;
		digit++;
	}

	ll pos = digit;
	while(x){
		number[pos] = x%10;
		x /= 10;
		pos--;
	}

	memset(dp,-1,sizeof(dp));
	return solve(1,0,0);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin>>t;

    for(ll tt = 1;tt<=t;tt++){

    	cout<<"Case #"<<tt<<": ";
    	ll l,r;
    	cin>>l>>r;
    	ll ans_l = convert_to_digit(l-1);
    	ll ans_r = convert_to_digit(r);

    	cout<<ans_r-ans_l<<endl;
    }

}