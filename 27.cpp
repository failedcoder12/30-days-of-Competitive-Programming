// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/unfair-nim-afea7c42/description/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MOD 1000000007
// I am questioning life and universe and 
// everything else after looking at all this.

vector<ll> A,B;

ll dp[69][2][2][2][2][2];

void getNum(ll N,vector<ll> &X){
	X.clear();
	while(N){
		X.push_back(N%2);
		N = N/2;
	}
}

// lo1 = 0 x is not less than N yet
// lo2 = 0 x is not less than x yet
// carry1 = 0 we are not allowed to generate a carry at MSB
// carry2 = {0,1} the next position may or may not have a carry
// is_zero = we will set if at least 1 non zero bit

ll solve(ll indx,ll lo1,ll lo2,ll carry1,ll carry2,ll is_zero){
	if(indx == A.size()){
		return (carry2 + carry1 == 0 && lo2 == 1 && is_zero == 1);
	}

	if(dp[indx][lo1][lo2][carry1][carry2][is_zero]!=-1)
		return dp[indx][lo1][lo2][carry1][carry2][is_zero];
	
	ll ans = 0;

	for(ll x=0;x<2;x++){
		if(lo1 == 0 && x>A[indx]) break;

		for(ll y=0;y<2;y++){
			if(lo2 == 0 && y>x) break;
			if((x+y+carry2>1) == carry1 && (x^y^((x+y+carry2)%2)) == B[indx]){
				ans += solve(indx+1,(lo1|x<A[indx]),(lo2|y<x),carry2,0,(is_zero|(y>0)));
				ans += solve(indx+1,(lo1|x<A[indx]),(lo2|y<x),carry2,1,(is_zero|(y>0)));
			}
		}
	}

	return dp[indx][lo1][lo2][carry1][carry2][is_zero] = ans%MOD;
}

int main(){
	FastRead;

	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll target = 0;	
		if(n%4 == 0) target = n;
		else if(n%4 == 1) target = 1;
		else if(n%4 == 2) target = n+1;

		getNum(n,A);
		getNum(target,B);

		while(B.size()<A.size()) B.push_back(0);

		reverse(A.begin(),A.end());
		reverse(B.begin(),B.end());

		memset(dp,-1,sizeof(dp));

		cout<<(solve(0,0,0,0,0,0)+solve(0,0,0,0,1,0))%MOD<<endl;
	}
}