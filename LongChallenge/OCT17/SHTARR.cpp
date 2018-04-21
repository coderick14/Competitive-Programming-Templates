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

vi segtree;

ll left(ll x) {
	return 2*x;
}

ll right(ll x) {
	return 2*x+1;
}

void build_segtree(ll n) {
	segtree.resize(2*n);
	for(ll i = n-1; i > 0; i--) {
		segtree[i] = max(segtree[left(i)], segtree[right(i)]);
	}
}

void update(ll index, ll val) {
	segtree[index+n] += val;
	index /= 2;
	for(; index > 0; index /= 2) {
		segtree[index] = max(segtree[left(index)], segtree[right(index)]);
	}
}

ll query(ll ql, ll qr, ll l, ll r, ll index) {
	if (l > qr or r < ql or ql > qr) {
		return -INF;
	}

	if (ql <= l and r <= qr) {
		return segtree[index];
	}

	ll mid = r + (r-l) / 2;
	return max(query(ql, qr, l, mid, left(index)), query(ql, qr, mid+1, r, right(index)));
}

int main() {
	ll i,j,t,n,q,l,r;
	t = read_ll();
	while (t--) {
		n = read_ll();
		q = read_ll();

		vi heights(n+1);

		FOR(i,1,n+1) {
			heights[i] = read_ll();
		}
	}
	return 0;
}