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
	ll i,j,t,n,a,b,k,f,fare;
	string src,dest,last_dest="";
	map<pair<string,string>, ll> trips;
	map<pair<string,string>, ll>::iterator it;
	vi costs;
	S(n);S(a);S(b);S(k);S(f);
	FOR(i,0,n) {
		cin >> src;
		cin >> dest;
		if (src.compare(last_dest) == 0) {
			fare = b;
		}
		else {
			fare = a;
		}
		last_dest = dest;
		if (src.compare(dest) < 0) {
			trips[mp(src,dest)] += fare;
		}
		else {
			trips[mp(dest,src)] += fare;
		}
	}
	for(it = trips.begin(); it != trips.end(); it++) {
		costs.pb(it->second);
	}
	sort(all(costs),comp);
	ll ans = 0;
	FOR(i,0,costs.size()) {
		if (k > 0 && costs[i] > f) {
			ans += f;
			k -= 1;
		}
		else {
			ans += costs[i];
		}
	}
	printf("%lld", ans);
	return 0;
}