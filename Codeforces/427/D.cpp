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

// #ifndef ONLINE_JUDGE
// #define gc getchar
// #define pc putchar
// #else
// #define gc getchar_unlocked
// #define pc putchar_unlocked
// #endif

using namespace std;

// int read_int() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     int ret = 0, neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

// ll read_ll() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     ll ret = 0;
//     int neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

vector<ll> xorhash, sumhash;

bool check_equal(int i, int j, int l) {
	int left_start, left_end, right_start, right_end;
	right_start = (l & 1 ? i + l/2 + 1 : i + l/2);
	left_start = i, left_end = i + l/2 - 1, right_end = j;

	ll lxor = xorhash[left_end] ^ (left_start == 0 ? 0 : xorhash[left_start-1]);
	ll lsum = sumhash[left_end] - (left_start == 0 ? 0 : sumhash[left_start-1]);

	ll rxor = xorhash[right_end] ^ xorhash[right_start-1];
	ll rsum = sumhash[right_end] - sumhash[right_start-1];
	return (lxor == rxor and lsum == rsum);
}

int main() {
	int i,j,t,n,l;
	string s;
	cin >> s;
	n = s.length();
	short dp[n+1][n+1];
	xorhash.resize(n);
	sumhash.resize(n);
	FOR(i,0,n+1) {
		FOR(j,i,n+1) {
			dp[i][j] = 0;
		}
	}
	xorhash[0] = sumhash[0] = (ll)(s[0]);
	FOR(i,1,n) {
		xorhash[i] = xorhash[i-1] ^ (ll)(s[i]);
		sumhash[i] = sumhash[i-1] + (ll)(s[i]);
	}
	FOR(i,0,n) {
		dp[i][i] = 1;
	}
	FOR(l,2,n+1) {
		FOR(i,0,n-l+1) {
			j = i + l - 1;
			if (l == 2) {
				if (s[i] == s[j]) {
					dp[i][j] = 2;
				}
			}
			else if (dp[i+1][j-1] > 0 and s[i] == s[j]) {
				dp[i][j] = 1;
				if (check_equal(i,j,l)) {
					if (l & 1) {
						if (dp[i][i+l/2-1] == dp[i+l/2+1][j]) {
							dp[i][j] = dp[i][i+l/2-1] + 1;
						}
					}
					else {
						if (dp[i][i+l/2-1] == dp[i+l/2][j]) {
							dp[i][j] = dp[i][i+l/2-1] + 1;
						}
					}
				}
			}
		}
	}

	vector<ll> ans(n+1,0);

	FOR(l,1,n+1) {
		FOR(i,0,n-l+1) {
			j = i + l - 1;
			ans[dp[i][j]] += 1;
		}
	}
	FREV(i,n-1,0) {
		ans[i] += ans[i+1];
	}
	FOR(i,1,n+1) {
		printf("%lld ", ans[i]);
	}
	return 0;
}