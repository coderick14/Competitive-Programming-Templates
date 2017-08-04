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
#define MOD1 1000000007
#define MOD2 1000000009

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

// Extended Euclid's Algorithm
ll xGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Multiplicative modular inverse using Extended Euclid's Algorithm
ll find_inverse(ll n, ll mod) {
	ll x,y;
	xGCD(n,mod,x,y);

	if (x < 0) {
		x = x + mod;
	}

	return x;
}

int main() {
	ll i,j,t,n;
	t = read_ll();
	while (t--) {
		n = read_ll();
		ll res1 = (1LL * (n%MOD1 * (n-1)%MOD1)%MOD1 * find_inverse((2 * (n + n -3)%MOD1)%MOD1, MOD1)%MOD1)%MOD1;
		ll res2 = (1LL * (n%MOD2 * (n-1)%MOD2)%MOD2 * find_inverse((2 * (n + n -3)%MOD2)%MOD2, MOD2)%MOD2)%MOD2;
		printf("%lld %lld\n", res1, res2);
	}
	return 0;
}
