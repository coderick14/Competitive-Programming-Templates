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

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

vi power(100005);
vi dp(100005), super_dp(100005);
void calc_pow() {
	power[0] = 1;
	ll i;
	FOR(i,1,100002) {
		power[i] = (power[i-1]*2)%MOD;
	}
}

int main() {
	ll i,j,t,n,poly;
	calc_pow();
	t = read_ll();
	while(t--) {
		n = read_ll();
		vi a(n+1);
		FOR(i,1,n+1) {
			a[i] = read_ll();
		}
		poly = a[1];
		dp[0] = super_dp[0] = 0;
		dp[1] = super_dp[1] = a[1];
		FOR(i,2,n+1) {
			poly = ((poly + power[i-2])%MOD * a[i])%MOD;
			dp[i] = (super_dp[i-1] + poly)%MOD;
			super_dp[i] = (super_dp[i-1] + dp[i])%MOD;	
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}