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

int main() {
	ll i,j,t,n,k,c;
	int elem;
	t = read_ll();
	while(t--) {
		n = read_ll();
		k = read_ll();
		ll res = 0;
		vector<int> sets[n];
		FOR(i,0,n) {
			c = read_ll();
			FOR(j,0,c) {
				elem = read_ll();
				sets[i].pb(elem);
			}
		}
		FOR(i,0,n) {
			FOR(j,i+1,n) {
				if (sets[i].size() + sets[j].size() >= k) {
					int counter = 0;
					vector<bool> flag(k+1,false);
					FOR(c,0,sets[i].size()) {
						if(flag[sets[i][c]] == false) {
							flag[sets[i][c]] = true;
							counter++;
						}
					}
					FOR(c,0,sets[j].size()) {
						if(flag[sets[j][c]] == false) {
							flag[sets[j][c]] = true;
							counter++;
						}
					}
					if (counter == k)
						res++;
				}
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}