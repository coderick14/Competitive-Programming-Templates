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

int main() {
	ll i,j,t,n;
	t = read_ll();
	while (t--) {
		n = read_ll();
		vi a(n), f(4,0);
		ll sum = 0;
		FOR(i,0,n) {
			a[i] = read_ll();
			a[i] = (a[i] % 4);
			sum += a[i];
			f[a[i]] += 1;
		}
		if (sum % 4 != 0) {
			printf("-1\n");
		}
		else {
			ll ans = 0;
			ans += f[2] / 2;
			f[2] = f[2] % 2;
			ll x = min(f[1], f[3]);
			ans += x;
			f[3] -= x;
			f[1] -= x;
			if (f[1] > 0) {
				ans += (f[1] / 4) * 3;
				f[1] /= 4;
				if (f[2] > 0) {
					ans += 2;
				}
			}
			else if (f[3] > 0) {
				ans += (f[3] / 4) * 3;
				f[3] /= 4;
				if (f[2] > 0) {
					ans += 2;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}