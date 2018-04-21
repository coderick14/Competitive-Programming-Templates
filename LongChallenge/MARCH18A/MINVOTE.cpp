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

struct node {
	ll votes;
	ll lazy;
	node* left;
	node* right;

	node(ll votes) {
		this->votes = votes;
		this->lazy = 0;
		this->left = this->right = NULL;
	}
};

ll n;
vi a,pre,suf;

node* build(ll l=0, ll r=n-1) {
	node* newnode = new node(0);
	if (l == r) {
		return newnode;
	}
	ll mid = l+(r-l)/2;
	newnode->left = build(l,mid);
	newnode->right = build(mid+1,r);
	return newnode;
}

void propagate(node* &root) {
	root->left->lazy += root->lazy;
	root->right->lazy += root->lazy;
	root->lazy = 0;
}

void range_update(node* &root, ll ql, ll qr, ll l = 0, ll r = n-1) {
	if (ql > r or qr < l or l > r) {
		return;
	}
	if (l == r) {
		root->votes += 1;
		return;
	}
	if (ql <= l and r <= qr) {
		root->lazy += 1;
		return;
	}
	ll mid = l+(r-l)/2;
	propagate(root);
	range_update(root->left, ql, qr, l, mid);
	range_update(root->right, ql, qr, mid+1, r);
}

ll query(node* root, ll &index, ll l = 0, ll r = n-1) {
	if (l == r) {
		return root->lazy + root->votes;
	}
	ll mid = l+(r-l)/2;
	propagate(root);
	if (index <= mid) {
		return query(root->left, index, l, mid);
	}
	return query(root->right, index, mid+1, r);
}

ll right_search(ll idx) {
	ll mid, l = idx+1, r = n-1;
	while (r-l > 1) {
		mid = l + (r-l)/2;
		if (pre[mid]-pre[idx] <= a[idx]) {
			l = mid;
		}
		else {
			r = mid-1;
		}
	}
	
	if(pre[r] - pre[idx] <= a[idx]) {
		return r;
	}
	return l;
}

ll left_search(ll idx) {
	ll mid, l = 0, r = idx-1;
	while (r-l > 1) {
		ll mid = l+(r-l)/2;
		if (suf[mid] - suf[idx] <= a[idx]) {
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	//cout<<a[idx]<<" "<<l<<" "<<r<<endl;
	if (suf[l] - suf[idx] <= a[idx]) {
		return l;
	}
	return r;
}

int main() {
	ll i,j,t,ql,qr;
	sll(t);
	while(t--) {
		sll(n);
		a.resize(n);pre.resize(n);suf.resize(n);
		READ(a,i,n);
		pre[0] = a[0];
		FOR(i,1,n) {
			pre[i] = pre[i-1] + a[i];
		}
		suf[n-1] = a[n-1];
		FREV(i,n-2,0) {
			suf[i] = suf[i+1] + a[i];
		}
		node* root = build();

		FOR(i,0,n) {
			if (i > 0) {
				ql = left_search(i);
                //cout<<"returned:"<<ql<<endl;
				if (ql > 0 and suf[ql]-suf[i] <= a[i]) {
					ql -= 1;
				}
				//DEBUG(ql);
				range_update(root,ql,i-1);
			}
			if (i < n-1) {
				qr = right_search(i);
				if (qr < n-1 and pre[qr] - pre[i] <= a[i]) {
					qr += 1;
				}
				//DEBUG(qr);
				range_update(root,i+1,qr);
			}
           // cout<<"----------\n";
			// printf("i : %lld ql : %lld qr : %lld\n", i,ql,qr);
		}
		FOR(i,0,n) {
			printf("%lld ", query(root,i));
		}
		printf("\n");
	}
	return 0;
}