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

ll n;
vi a;

struct node {
	vi ones;

	node* left;
	node* right;

	node(ll num) {
		this->left = this->right = NULL;
		ones.resize(31,0);
		for(ll i=0;i<31;i++) {
			if (num & (1 << i)) {
				this->ones[i] += 1;
			}
			else {
				this->ones[i] -= 1;
			}
		}
	}
    
    node() {
		this->left = this->right = NULL;
		ones.resize(31,0);
	}
};

node* default_node = new node();

node* build(ll l=0, ll r=n-1) {
	if (l == r) {
		node* newnode = new node(~a[l]);
		return newnode;
	}
	ll mid = l + (r-l)/2;
	node* left = build(l,mid);
	node* right = build(mid+1,r);

	node* newnode = new node();
	newnode->left = left;
	newnode->right = right;
    ll i;
	FOR(i,0,31) {
		newnode->ones[i] = left->ones[i] + right->ones[i];
	}

	return newnode;
}

vi query(node* root, ll ql, ll qr, ll l=0, ll r=n-1) {
	if (ql > r or qr < l or l > r) {
		return default_node->ones;
	}
	if (ql <= l and r <= qr) {
		return root->ones;
	}
	ll mid = l + (r-l)/2;
	vi left = query(root->left, ql, qr, l, mid);
	vi right = query(root->right, ql, qr, mid+1, r);

	ll i;
	vi newarr(31,0);
	FOR(i,0,31) {
		newarr[i] = left[i] + right[i];
	}
	return newarr;
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,q,ql,qr,ans;
	sll(n);sll(q);
	a.resize(n);
	FOR(i,0,n) {
		sll(a[i]);
	}
	node* root = build();
	FOR(i,0,q) {
		sll(ql);sll(qr);
		ql -= 1;
		qr -= 1;
		vi resp = query(root,ql,qr);
		ans = 0;
		FOR(j,0,31) {
			if (resp[j] > 0) {
				ans += pow(2,j);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}