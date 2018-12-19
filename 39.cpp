// https://codeforces.com/contest/493/problem/D

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
// I am questioning life and universe and 
// everything else after looking at all this.

signed main(){
	ll n;
	cin>>n;

	// If n is even then white can move to 1 2 
	// then symmetric to black

	// If n is odd black can just move 
	// symmetric to white

	if(n%2 == 0){
		cout<<"white\n1 2\n";
	}else {
		cout<<"black\n";
	}
}