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

int main() {
	ll i,j,t,n,sum,left,right;
	S(n);
	n += 1;
	vi a(n);
	FOR(i,0,n) {
		S(a[i]);
	}
	bool is_ambiguous = false;
	FOR(i,1,n) {
		if (a[i-1] > 1 and a[i] > 1) {
			t = i;
			is_ambiguous = true;
			break;
		}
	}
	if (is_ambiguous) {
		ll sum = 1;
		printf("ambiguous\n");
		printf("0 ");
		FOR(i,1,t) {
			FOR(j,0,a[i]) {
				printf("%lld ", sum);
			}
			sum += a[i];
		}
		left = floor(float(a[t]) / 2.0), right = ceil(float(a[t]) / 2.0);
		FOR(i,0,left) {
			printf("%lld ", sum-1);
		}
		FOR(i,0,right) {
			printf("%lld ", sum);
		}
		sum += a[t];
		FOR(i,t+1,n) {
			FOR(j,0,a[i]) {
				printf("%lld ", sum);
			}
			sum += a[i];
		}
		printf("\n");
		printf("0 ");
		sum = 1;
		FOR(i,1,n) {
			FOR(j,0,a[i]) {
				printf("%lld ", sum);
			}
			sum += a[i];
		}
	}
	else {
		printf("perfect");
	}
	return 0;
}