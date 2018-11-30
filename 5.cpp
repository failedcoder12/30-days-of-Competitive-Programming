// https://www.codechef.com/problems/RRPLAYER

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

// COUPON COLLECTION PROBLEM 
// n*Hn Harmonic Series

int main(){
	FastRead;

	ll t;
	cin>>t;

	while(t--){
		float n;
		cin>>n;

		float ans = n*log(n) + n*(0.577216) + 0.50;

		printf("%.2f\n",ans);
	}
}