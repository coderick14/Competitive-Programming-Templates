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

vi digit_diffs(2000005, 0);
vi dp(1000002, 0);

ll get_val(ll n) {
	ll rem, ans = 0;
	while(n > 0) {
		rem = n % 10;
		n /= 10;
		if (rem % 2 == 1) {
			ans += rem;
		}
		else {
			ans -= rem;
		}
	}
	return abs(ans);
}

int main() {
	ll i,j,t,n;
	FOR(i,2,digit_diffs.size()) {
		digit_diffs[i] = get_val(i);
		digit_diffs[i] += digit_diffs[i-1];
	}
	FOR(i,1,dp.size()) {
		dp[i] = dp[i-1] + (digit_diffs[2*i] - digit_diffs[2*i-1]) + 2 * (digit_diffs[2*i-1] - digit_diffs[i]);
	}
	t = read_ll();
	while (t--) {
		n = read_ll();
		printf("%lld\n", dp[n]);
	}
	return 0;
}