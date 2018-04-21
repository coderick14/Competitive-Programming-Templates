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
	ll i,j,t,n,m,cost1,cost2,row_start,current_cherry;
	ll cost[2] = {3, 5};
	char types[2] = {'R', 'G'};
	t = read_ll();
	while (t--) {
		n = read_ll();
		m = read_ll();
		vector<string> cherries(n);
		FOR(i,0,n) {
			cin >> cherries[i];
		}
		cost1 = cost2 = 0;

		row_start = 0;
		FOR(i,0,n) {
			current_cherry = row_start;
			FOR(j,0,m) {
				if (cherries[i][j] != types[current_cherry]) {
					cost1 += cost[current_cherry];
				}
				current_cherry = 1 - current_cherry;
			}
			row_start = 1 - row_start;
		}

		row_start = 1;
		FOR(i,0,n) {
			current_cherry = row_start;
			FOR(j,0,m) {
				if (cherries[i][j] != types[current_cherry]) {
					cost2 += cost[current_cherry];
				}
				current_cherry = 1 - current_cherry;
			}
			row_start = 1 - row_start;
		}

		printf("%lld\n", min(cost1, cost2));
	}
	return 0;
}