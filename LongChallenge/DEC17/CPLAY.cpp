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
	ll i,j,t,n,score1,score2,kicks;
	char shots[30];
	while(scanf("%s", shots) != EOF) {
		score1 = score2 = kicks = 0;
		FOR(i,0,5) {
			score1 += (shots[2*i] - '0');
			kicks++;
			if (score1 > score2 + (5 - i) or score1 + (4 - i) < score2) {
				break;
			}
			score2 += (shots[2*i+1] - '0');
			kicks++;
			if (score2 > score1 + (4 - i) or score2 + (4 - i) < score1) {
				break;
			}
		}
		if (score1 > score2) {
			printf("TEAM-A %lld\n", kicks);
			continue;
		}
		else if (score1 < score2) {
			printf("TEAM-B %lld\n", kicks);
			continue;
		}

		FOR(i,5,10) {
			score1 += (shots[2*i] - '0');
			score2 += (shots[2*i+1] - '0');
			kicks += 2;
			if (score1 != score2) {
				break;
			}
		}

		if (score1 > score2) {
			printf("TEAM-A %lld\n", kicks);
		}
		else if (score1 < score2) {
			printf("TEAM-B %lld\n", kicks);
		}
		else {
			printf("TIE\n");
		}

	}
	return 0;
}