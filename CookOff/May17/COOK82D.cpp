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
#define SULL(n) scanf("%llu", &n)
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

int main() {
	ll i,j,t,n,m,l,r,u,v;
	n = read_ll();
	m = read_ll();
    vi hash(n+1);
    vi edges(2*m+1);
    FOR(i,1,n+1) {
        hash[i] = (rand() * 1LL * rand()) % MOD;
    }
	FOR(i,0,m) {
		u = read_ll();
		v = read_ll();
        edges[2*i + 1] = hash[u];
        edges[2*i + 2] = hash[v];
	}
    FOR(i,1,2*m+1) {
        edges[i] = edges[i] ^ edges[i-1];
    }
    t = read_ll();
	FOR(i,0,t) {
		l = read_ll();
		r = read_ll();
        l = 2*l - 2;
        r = 2*r;
        if (edges[l] == edges[r]) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
	}
	
	return 0;
}