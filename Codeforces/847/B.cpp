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

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	ll i,j,t,n,next=0;
	S(n);
	vi a(n);
	vi aux;
	vector<ll>::iterator it;
	vi res[200005];
	FOR(i,0,n) {
		S(a[i]);
	}
	FOR(i,0,n) {
		if (aux.size() == 0) {
			aux.pb(a[i]);
			res[0].pb(a[i]);
			next++;
			continue;
		}
		it = lower_bound(all(aux),a[i],comp);
		if (it != aux.end()) {
			ll count = it - aux.begin();
			res[count].pb(a[i]);
			*it = a[i];
		}
		else {
			res[next].pb(a[i]);
			aux.pb(a[i]);
			next++;
		}
	}
	FOR(i,0,n) {
		for(it = res[i].begin(); it != res[i].end(); it++) {
			printf("%lld ", *it);
		}
		printf("\n");
	}
	return 0;
}