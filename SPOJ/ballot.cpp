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

vector<ll> people;

bool check_for_x(ll x, ll n, ll b) {
	ll i, box_count = 0;
	FOR(i,0,n) {
		box_count += people[i]/x + (people[i]%x?1:0);
		if (box_count > b)
			return false;
	}
	return true;
}

ll solve(ll n, ll b) {
	ll mid, res, beg = 1, last = *max_element(all(people));
	while (beg <= last) {
		mid = beg + (last-beg)/2;
		if (check_for_x(mid, n, b)) {
			res = mid;
			last = mid - 1;
		}
		else {
			beg = mid + 1;
		}
	}
	return res;
}

int main() {
	ll i,j,t,n,b;
	while (1) {
		n = read_ll();
		b = read_ll();
		if (n == -1 and b == -1)
			break;

		people.resize(n);
		FOR(i,0,n) {
			people[i] = read_ll();
		}
		cout << solve(n,b) << "\n";
	}
	return 0;
}
