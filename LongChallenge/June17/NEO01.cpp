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

bool comp(ll a, ll b) {
	return a > b;
}

ll a[100005], prefix[100005];

int main() {
	ll i,j,t,n,contrib,res;
	t = read_ll();
	while(t--) {
		n = read_ll();
		FOR(i,0,n) {
			a[i] = read_ll();
		}
		sort(a,a+n,comp);

		prefix[0] = a[0];
		FOR(i,1,n) {
			prefix[i] = prefix[i-1] + a[i];
		}
		// all negative
		if (a[0] <= 0) {
			printf("%lld\n", prefix[n-1]);
			continue;
		}
		// all positive
		if (a[n-1] >= 0) {
			printf("%lld\n", prefix[n-1] * n);
			continue;
		}
		FOR(i,1,n) {
			contrib = prefix[i-1] + (i+1) * a[i];
			if (contrib < 0 && contrib < a[i]) {
				break;
			}
		}
		res = prefix[i-1] * i + (prefix[n-1] - prefix[i-1]);
		printf("%lld\n", res);
	}
	return 0;
}