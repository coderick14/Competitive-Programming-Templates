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
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
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
	ll len;
	ll res, prefix, suffix;
	node(ll value = 0) {
		assert(value == 0 or value == 1);
		len = 1;
		res = prefix = suffix = value;
	}
};

vector<node> segL, segR;
ll L,R;

node merge(node a, node b) {
	node combined;

	combined.len = a.len + b.len;

	combined.res = a.res + b.res + a.suffix * b.prefix;
	
	combined.prefix = a.prefix;
	if (a.prefix == a.len) {
		combined.prefix += b.prefix;
	}

	combined.suffix = b.suffix;
	if (b.suffix == b.len) {
		combined.suffix += a.suffix;
	}

	return combined;	
	
}


void updateUtil(ll t, ll index, ll value, ll l, ll r) {
	if (l == r) {
		segL[t] = node(value < L);
		segR[t] = node(value < R+1);
		return;
	}

	ll m = (l + r) / 2;
	if (index <= m) {
		updateUtil(2*t+1, index, value, l, m);
	}
	else {
		updateUtil(2*t+2, index, value, m+1, r);
	}

	segL[t] = merge(segL[2*t+1], segL[2*t+2]);
	segR[t] = merge(segR[2*t+1], segR[2*t+2]);
}

void update(ll index, ll value, ll n) {
	updateUtil(0, index, value, 0, n-1);
}

void build_tree(ll n) {
	ll i;
	FOR(i,0,n) {
		update(i,0,n);
	}
}

node queryUtil(vector<node> &seg, ll t, ll l, ll r, ll start, ll end) {
	if (l > end or r < start or start > end) {
		return node();
	}

	if (l <= start and end <= r) {
		return seg[t];
	}

	ll m = (start + end) / 2;
	return merge(queryUtil(seg, 2*t+1, l, r, start, m), queryUtil(seg, 2*t+2, l, r, m+1, end));
}

ll query(ll l, ll r, ll n) {
	return  queryUtil(segR, 0, l, r, 0, n-1).res - queryUtil(segL, 0, l, r, 0, n-1).res; 
}

int main() {
	ll i,j,n,q,l,r,ch,x,y;
	n = read_ll();
	q = read_ll();
	L = read_ll();
	R = read_ll();

	segL.resize(4*n);
	segR.resize(4*n);

	build_tree(n);

	FOR(i,0,q) {
		ch = read_ll();
		if (ch == 1) {
			x = read_ll();
			y = read_ll();
			update(x-1,y,n);
		}
		else {
			l = read_ll();
			r = read_ll();
			printf("%lld\n", query(l-1,r-1,n));
		}
	}
	return 0;
}