#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void make_set(vector<ll> &id, vector<ll> &rank, ll n) {
    for(ll i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
    }
}

ll find_set(vector<ll> &id, ll p) {
    ll root = p;
    //find the root
    while(root != id[root]) {
        root = id[root];
    }
    //perform path compression
    while(p != root) {
        ll newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}

void merge_set(vector<ll> &id, vector<ll> &rank, ll x, ll y) {
    x = find_set(id, x);
    y = find_set(id, y);
    if(rank[x] > rank[y])
        id[y] = x;
    else
        id[x] = y;
    if(rank[x] == rank[y])
        rank[y] += 1;
}

int main() {
	ll i,n,res = 0;
	cin>>n;
	vector<ll> forest(n+1), rank(n+1), id(n+1);
	for(i=1;i<=n;i++) {
	    cin>>forest[i];
	}
	make_set(id, rank, n);
	for(i=1;i<=n;i++) {
	    merge_set(id, rank, i, forest[i]);
	}
	for(i=1;i<=n;i++) {
	    if(id[i] == i)
	        res++;
	}
	cout<<res;
	return 0;
}

