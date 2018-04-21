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
	ll i,j,t,n,m,last_company,hired,sum,companies;
	vi minsal(1003), offersal(1003), jobs(1003), cursal(1003), hire_count(1003);
	short qual[1002][1002];
	t = read_ll();
	while (t--) {
		n = read_ll();
		m = read_ll();

		READ(minsal,i,n);
		FOR(i,0,m) {
			offersal[i] = read_ll();
			jobs[i] = read_ll();
			hire_count[i] = 0;
		}

		FOR(i,0,n) {
			cursal[i] = -1;
			FOR(j,0,m) {
				scanf("%1hd", &qual[i][j]);
			}
		}

		FOR(i,0,n) {
			last_company = -1;
			FOR(j,0,m) {
				if (qual[i][j] and offersal[j] >= max(minsal[i], cursal[i]) and jobs[j] > 0) {
					cursal[i] = offersal[j];
					jobs[j] -= 1;
					hire_count[j] += 1;
					if (last_company != -1) {
						jobs[last_company] += 1;
						hire_count[last_company] -= 1;
					}
					last_company = j;
				}
			}
		}

		sum = hired = companies = 0;
		
		FOR(i,0,n) {
			if (cursal[i] >= minsal[i]) {
				sum += cursal[i];
				hired++;
			}
		}
		FOR(i,0,m) {
			if (hire_count[i] > 0) {
				companies++;
			}
		}

		printf("%lld %lld %lld\n", hired, sum, m - companies);
	}
	return 0;
}