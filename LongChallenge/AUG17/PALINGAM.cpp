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
	string sa, sb;
	int A[26], B[26];
	t = read_ll();
	while (t--) {
		cin >> sa >> sb;
		n = sa.length();
		FOR(i,0,26) {
			A[i] = B[i] = 0;
		}
		FOR(i,0,n) {
			A[sa[i] - 'a']++;
			B[sb[i] - 'a']++;
		}
		// check if B has all characters that A has
		FOR(i,0,26) {
			if (A[i] > 0 and B[i] == 0)
				break;
		}
		if (i >= 26) {
			printf("B\n");
			continue;
		}

		// A has some character which B doesn't.
		// Check if A has all characters which B has.
		FOR(i,0,26) {
			if (B[i] > 0 and A[i] == 0)
				break;
		}
		if (i >= 26) {
			printf("A\n");
			continue;
		}

		// Check if A has an extra charater at least twice
		FOR(i,0,26) {
			if (B[i] == 0 and A[i] > 1)
				break;
		}
		if (i < 26) {
			printf("A\n");
			continue;
		}

		printf("B\n");

	}
	return 0;
}