#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a;

struct node {
	vector<ll> vec;
	node *left, *right;

	node() {
		left = right = nullptr;
	}
};

node* build(ll l, ll r) {
	node* newnode = new node();
	if (l == r) {
		newnode->vec.push_back(a[l]);
		return newnode;
	}
	ll m = l+(r-l)/2;
	newnode->left = build(l,m);
	newnode->right = build(m+1,r);
	ll i = 0, j = 0;
	vector<ll> &vec_l = newnode->left->vec, &vec_r = newnode->right->vec;; 
	while (i < vec_l.size() and j < vec_r.size()) {
		if (vec_l[i] < vec_r[j]) {
			newnode->vec.push_back(vec_l[i]);
			i++;
		}
		else {
			newnode->vec.push_back(vec_r[j]);
			j++;
		}
	}

	while (i < vec_l.size()) {
		newnode->vec.push_back(vec_l[i]);
		i++;
	}

	while (j < vec_r.size()) {
		newnode->vec.push_back(vec_r[j]);
		j++;
	}

	return newnode;
}

// query to find number of elements less than k in [ql,qr]
ll query(node* root, ll ql, ll qr, ll l, ll r, ll &k) {
	if (ql > r or qr < l or l > r) {
		return 0;
	}
	if (ql <= l and r <= qr) {
		return lower_bound(root->vec.begin(), root->vec.end(),k) - root->vec.begin();
	}
	ll m = l+(r-l)/2;
	return query(root->left, ql, qr, l, m, k) + query(root->right, ql, qr, m+1, r, k);
}

int main() {
	ll i,n,k,q,l,r;
	cin >> n;
	a.resize(n);
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	node* root = build(0,n-1);
	cin >> q;
	while (q--) {
		cin >> l >> r >> k;
		l--;r--;
		cout << query(root,l,r,0,n-1,k) << endl;
	}
}
