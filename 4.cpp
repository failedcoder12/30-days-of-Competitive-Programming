// https://www.codechef.com/problems/MINXOR

// https://www.codechef.com/viewsolution/21718823
// ERROR SEGMENTATION FAULT
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int 
const ll N = 250005;
const ll SQN = sqrt(N+.0)+1;

ll arr[N];
ll blocks_Xor[SQN];

struct Trie {
	ll count;
	Trie *child[2];
};

Trie *SQNTRIE[SQN];

Trie *new_node(){
	Trie *new_no = new Trie;
	new_no->count = 0;
	new_no->child[0] = NULL;
	new_no->child[1] = NULL;
	return new_no;
}

void insert_in_trie(Trie *root,ll val){
	for(ll i=15;i>=0;i--){
		ll position = (((1<<i)&val));

		if(root->child[position] == NULL){
			root->child[position] = new_node();
		}
		root = root->child[position];
		root->count++;
	}
}

void delete_in_trie(Trie *root,ll val){
	for(ll i=15;i>=0;i--){
		ll position = (((1<<i)&val));
		root = root->child[position];
		root->count--;		
	}
}

pair<ll,ll> find_min(Trie* root,ll val){
	ll ans = 0;
	for(ll i=15;i>=0;i--){
		ll position = (((1<<i)&val));
		if(root->child[position] && root->child[position]->count > 0){
			root = root->child[position];
		}else {
			root = root->child[!position];
			ans = ans+(1<<i);
		}
	}

	return make_pair(ans,root->count); 
}


ll n,q;

int main(){
	FastRead;
    
    for(ll i=0;i<SQN;i++) SQNTRIE[i] = new_node();
	cin>>n>>q;

	for(ll i=0;i<n;i++){
		cin>>arr[i];
		insert_in_trie(SQNTRIE[i/SQN],arr[i]);
	}

	while(q--){
		ll type;
		cin>>type;

		if(type == 1){
			ll l,r;
			cin>>l>>r;l--,r--;

			ll c_l = l/SQN,r_l = r/SQN;

			if(c_l == r_l){

				ll ans = INT_MAX,index = -1;
				for(ll i=l;i<=r;i++){
					if((blocks_Xor[i/SQN]^arr[i]) < ans){
						ans = (blocks_Xor[i/SQN]^arr[i]);
						index = 1;
					}else if((blocks_Xor[i/SQN]^arr[i]) == ans){
						index++;
					}
				}
				cout<<ans<<" "<<index<<endl;
			}else {

				ll ans = INT_MAX,index = -1;
				for(ll i=l;i<(c_l+1)*SQN;i++){
					if((blocks_Xor[i/SQN]^arr[i]) < ans){
						ans = (blocks_Xor[i/SQN]^arr[i]);
						index = 1;
					}else if((blocks_Xor[i/SQN]^arr[i]) == ans){
						index++;
					}
				}

				for(ll i=c_l+1;i<r_l;i++){
					auto p = find_min(SQNTRIE[i],blocks_Xor[i]);
					if(p.first < ans){
						ans = p.first;
						index = p.second;
					}else if(p.first == ans){
						index += p.second;
					}
				}
				
				for(ll i=r_l*SQN;i<=r;i++){
					if((blocks_Xor[i/SQN]^arr[i]) < ans){
						ans = (blocks_Xor[i/SQN]^arr[i]);
						index = 1;
					}else if((blocks_Xor[i/SQN]^arr[i]) == ans){
						index++;
					}
				}

				cout<<ans<<" "<<index<<endl;
			}			

		}else {
			ll l,r,k;
			cin>>l>>r>>k;l--,r--;
            
            ll c_l = l/SQN,r_l = r/SQN;
            
            if(c_l == r_l){
                for(ll i=l;i<=r;i++){
            		delete_in_trie(SQNTRIE[i/SQN],arr[i]);
    				arr[i] = k^arr[i];
    				insert_in_trie(SQNTRIE[i/SQN],arr[i]);
    		    }
            }else {
    			for(ll i=l;i<(c_l+1)*SQN;i++){
    				delete_in_trie(SQNTRIE[i/SQN],arr[i]);
    				arr[i] = k^arr[i];
    				insert_in_trie(SQNTRIE[i/SQN],arr[i]);
    			}
    
    			for(ll i=c_l+1;i<r_l;i++){
    				blocks_Xor[i] = blocks_Xor[i]^k;
    			}
    
    			for(ll i=r_l*SQN;i<=r;i++){
    				delete_in_trie(SQNTRIE[i/SQN],arr[i]);
    				arr[i] = k^arr[i];
    				insert_in_trie(SQNTRIE[i/SQN],arr[i]);				
    			}
		    }
		}
	}
}