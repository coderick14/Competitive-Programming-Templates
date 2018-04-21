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
struct command {
	ll type,l,r;
};

int main() {
	ll i,j,t,n,m;
	t = read_ll();
	while(t--) {
		n = read_ll();
		m = read_ll();
		vector<command> commands(m+1);
		vi frequency(m+2,0), diff(m+2,0), a(n+1,0);
		FOR(i,1,m+1) {
			S(commands[i].type);
			S(commands[i].l);
			S(commands[i].r);
		}

		diff[m+1] = -1;
		FREV(i,m,1) {
			frequency[i] = frequency[i+1] - diff[i+1];
			if (commands[i].type == 2) {
				diff[commands[i].l] += frequency[i];
				diff[commands[i].r + 1] -= frequency[i];
			}
		}
		FOR(i,1,m+1) {
			if (commands[i].type == 1) {
				a[commands[i].l] += frequency[i];
				a[commands[i].r + 1] -= frequency[i];
			}
		}
		FOR(i,1,n+1) {
			a[i] += a[i-1];
			printf("%lld ", a[i]);
		}
		printf("\n");
		
	}
	return 0;
}