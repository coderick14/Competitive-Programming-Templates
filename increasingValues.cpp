// Hackerearth May circuits
/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define INF 1e18
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

ll timer = 0, res = 0;
vi st(100005), et(100005), val_from_st(100005);
vector<bool> is_good(100005,false);
ll binary_ancestor[100005][20];

struct node {
	vi adj;
	ll val;
};
vector<node> tree;

struct seg_node {
	ll val;
	seg_node *left, *right;

	seg_node() {
		this->val = 0;
		this->left = this->right = NULL;
	}
};

seg_node* build(ll l, ll r) {
	seg_node* newnode = new seg_node();
	if (l == r) {
		newnode->val = val_from_st[l];
		return newnode;
	}
	ll m = l + (r-l)/2;
	newnode->left = build(l,m);
	newnode->right = build(m+1,r);
	newnode->val = newnode->left->val + newnode->right->val;
	return newnode;
}

void update(seg_node* &root, ll l, ll r, ll idx, ll delta) {
	if (l == r) {
		root->val += delta;
		return;
	}
	ll m = l + (r-l)/2;
	if (idx <= m) {
		update(root->left, l, m, idx, delta);
	}
	else {
		update(root->right, m+1, r, idx, delta);
	}
	root->val = root->left->val + root->right->val;
}

ll query(seg_node* root, ll l, ll r, ll ql, ll qr) {
	if (ql > r or qr < l or l > r) {
		return 0;
	}
	if (ql <= l and r <= qr) {
		return root->val;
	}
	ll m = l + (r-l)/2;
	return query(root->left,l,m,ql,qr) + query(root->right,m+1,r,ql,qr);
}

ll dfs(ll u, ll p, ll &x) {
	st[u] = ++timer;
	val_from_st[st[u]] = tree[u].val;
	binary_ancestor[u][0] = p;
	ll subsum = tree[u].val;
	for(auto v : tree[u].adj) {
		if (v != p) {
			subsum += dfs(v,u,x);
		}
	}
	if (subsum > x) {
		res++;
		is_good[u] = true;
	}
	et[u] = timer;
	return subsum;
}

void binary_lifting(ll n) {
	ll i, j;
	for(j = 1; j <= 19; j++) {
		for(i = 1; i <= n; i++) {
			if (binary_ancestor[i][j-1] != -1)
				binary_ancestor[i][j] = binary_ancestor[binary_ancestor[i][j-1]][j-1];
		}
	}
}

ll get_good_parent(seg_node* root, ll n, ll u, ll x) {
	if(query(root,1,n,st[u],et[u]) > x) 
		return u;
	ll i;
	FREV(i,19,0) {
		if (binary_ancestor[u][i] == -1) continue;
		if (query(root,1,n,st[binary_ancestor[u][i]],et[binary_ancestor[u][i]]) > x) continue;
		u = binary_ancestor[u][i];
	}
	return binary_ancestor[u][0];
}
 
int main() {
	ll i,j,t,n,q,x,u,v;
	n = read_ll();
	q = read_ll();
	x = read_ll();
	tree.resize(n+1);
	FOR(i,0,n-1) {
		u = read_ll();
		v = read_ll();
		tree[u].adj.pb(v);
		tree[v].adj.pb(u);
	}
	FOR(i,1,n+1) {
		// sll(j);
		tree[i].val = read_ll();
	}
	memset(binary_ancestor,-1,sizeof(binary_ancestor));
	dfs(1,-1,x);
	binary_lifting(n);
	seg_node* root = build(1,n);
	while (q--) {
		u = read_ll();
		v = read_ll();
		// sll(u); sll(v);
		update(root,1,n,st[u],v);
		u = get_good_parent(root,n,u,x);
		
		while (u > 0 and is_good[u] == false) {
			is_good[u] = true;
			res++;
			u = binary_ancestor[u][0];
		}
		printf("%lld\n", res);
	}
	return 0;
}
