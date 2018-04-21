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
vi cooling_time;
ll t,n;

// BRUTE SOLUTION
// ll solve(ll bowl_num, ll reach_at) {
// 	if (bowl_num > n || reach_at >= t) {
// 		return 0;
// 	}
// 	ll waiting_time = cooling_time[bowl_num] - reach_at;
// 	if (waiting_time < 0) {
// 		waiting_time = 0;
// 	}
// 	ll if_eats = solve(bowl_num+1,reach_at+waiting_time+1) + 1;
// 	ll if_skips = solve(bowl_num+1,reach_at+1);
// 	return max(if_eats,if_skips);
// }


ll solve() {
	vector<pp > intervals;
	ll i;
	FOR(i,1,n+1) {
		ll wait_min = cooling_time[i] - i;
		ll wait_max = t - i;

		if (wait_max > 0 && wait_max > wait_min) {
			intervals.pb(mp(wait_min,1));
			intervals.pb(mp(wait_max,-1));
		}
	}
	sort(all(intervals));
	ll cur = 0, bowl_count = 0;
	FOR(i,0,intervals.size()) {
		cur += intervals[i].second;
		bowl_count = max(bowl_count,cur);
	}
	printf("%lld\n", bowl_count);

}

int main() {
	ll i,j;
	S(n);S(t);
	cooling_time.resize(n+1);
	FOR(i,1,n+1) {
		S(cooling_time[i]);
	}
	// printf("%lld\n", solve(1,1));
	solve();

	return 0;
}