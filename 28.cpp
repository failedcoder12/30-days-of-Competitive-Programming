// https://www.codechef.com/NOV18A/problems/BINSTR

// TAKEN FROM ----------------------------------
// https://www.codechef.com/viewsolution/21617045
// TAKEN FROM ----------------------------------

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MAXN 100001
// I am questioning life and universe and 
// everything else after looking at all this.

string arr[MAXN];
ll padar[MAXN];
const ll ALPHABET_SIZE = 2;

struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	// Stores the children of node
	TrieNode *nxt;
	// Store the next node. Used for compression if a node has bith left 
	// and right nxt point to itself
	vector<ll>v;
	// stores index of all strings that pass through node
	ll depth;
	// Depth if node where dpeth refers to index of element
	// of string we are traversting
}

TrieNode *getNode(){
	TrieNode *pNode = new TrieNode;
	pNode->nxt = NULL;
	pNode->depth = 0;
	for(ll i=0;i<ALPHABET_SIZE;i++) pNode->children[i] = NULL;
	return pNode;
}

ll idx;
void insert(TrieNode *root,string key,ll dep){
	TrieNode *pCrawl = root;
	ll index,flag = 0;

	for(ll i=0;i<key.length();i++){
		ll index = key[i]-'0';
		if(!pCrawl->children[index]){
			pCrawl->children[index] = getNode();
			pCrawl->children[index]->depth = dep+i+1;
		}
		pCrawl = pCrawl->children[index];
	}
	pCrawl->v.push_back(idx);
}

map<ll,TrieNode*> mp;

void padding_insert(TrieNode *root,ll len){
	mp[0] = root;
	for(ll i=1;i<=len;i++){
		root->children[0] = getNode();
		root = root->children[0];
		mp[i] = root;
	}
}

void dfs_compression(TrieNode *root){
	if(!root->children[0] && !root->children[1]){
		// No Children of root
		root->nxt = root;
		return;
	}

	if(root->children[0]){
		// If only 0 as children is present
		root->children[0]->depth = root->depth+1;
		dfs_compression(root->children[0]);
	}
	if(root->children[1]){
		// If only 1 as children is present
		root->children[1]->depth = root->depth+1;
		dfs_compression(root->children[1]);
	}

	if(!root->children[0] || root->children[0]->nxt == NULL || root->children[0]->nxt->v.size()==0){
		root->children[0] = NULL;
		if(!root->children[1]){
			root->children[1] = NULL;
			root->nxt = root;
			return;
		}
		root->nxt = root->children[1]->nxt;
		return;
	}

	if(!root->children[1] || root->children[1]->nxt == NULL || root->children[1]->nxt->v.size()==0){
		root->children[1] = NULL;
		if(!root->children[0]){
			root->children[0] = NULL;
			root->nxt = root;
			return;
		}
		root->nxt = root->children[0]->nxt;
		return;
	}

	root->v.assign(root->children[0]->nxt->v.size()+
		root->children[1]->nxt->v.size(),-1);
	merge(root->children[0]->nxt->v.begin(),
		root->children[0]->nxt->v.end(),
		root->children[1]->nxt->v.begin(),
		root->children[1]->nxt->v.end(),
		root->v.begin());
	root->nxt = root;
}

ll L,R;

ll search(TrieNode *root,string key,ll pad){
	TrieNode *pCrawl = root;
	ll index,flag = 0,ndep;
	while(true){
		if(!pCrawl->children[0] && !pCrawl->children[1]){
			break;
		}
		ndep = pCrawl->depth;

		if(ndep<pad){
			index = 1;
		}else {
			index = key[ndep-pad]-'0';
			index = 1-index;
		}
		if(!pCrawl->children[index]){
			pCrawl = pCrawl->children[1-index]->nxt;
		}else {
			ll pos = lower_bound(pCrawl->children[index]->nxt->v.begin(),
				pCrawl->children[index]->nxt->v.end(),L)-pCrawl->children[index]->nxt->begin();

			if(pos>=pCrawl->children[index]->nxt->v.size()||
				pCrawl->children[index]->nxt->v[pos]>R){
				pCrawl=pCrawl->children[1-index]->nxt;
			}else {
				pCrawl = pCrawl->children[index]->nxt;
			}
		}
	}

	pos = lower_bound(pCrawl->v.begin(),pCrawl->v.end(),L)-pCrawl->v.begin();
	return pCrawl->v[pos];
}

int main(){
	FastRead;

	ll n,q,i,j,l,r;
	cin>>n>>q;

	ll maxi = 0,pad;

	TrieNode *root = getNode();

	for(ll i=0;i<n;i++){
		cin>>arr[i];
		maxi = max(maxi,arr[i].length());
	}

	padding_insert(root,maxi);

	for(ll i=0;i<n;i++){
		idx = i+1;
		pad = maxi-arr[i].length();
		insert(mp[pad],arr[i],pad);
	}

	dfs_compression(root);

	string s;
	ll st;
	while(q>0){
		cin>>l>>r>>s;
		L = l,R = r;
		if(s.length() > maxi){
			s = s.substr(s.length()-maxi);
			pad = 0;
		}else {
			pad = maxi - s.length();
		}
		cout<<search(root,s,pad)<<endl;
		q--;
	}
}