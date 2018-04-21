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

ll right(ll left, ll n) {
	return (left + n - 1) % n;
}

ll left(ll right, ll n) {
	return (right + 1) % n;
}

int main() {
	ll i,j,t,n,m,tastiness,shift;
	t = read_ll();
	while(t--) {
		n = read_ll();
		vector<pp > ingredients[n];
		vector<pp > maxims(n, {-INF,-INF});
		FOR(i,0,n) {
			m = read_ll();
			FOR(j,0,m) {
				tastiness = read_ll();
				ingredients[i].pb({tastiness,0});
			}
		}

		FOR(i,0,ingredients[0].size()) {
			maxims[0].first = max(maxims[0].first, -ingredients[0][i].first);
			maxims[0].second = max(maxims[0].second, ingredients[0][i].first);
		}

		ll left_element, right_element, val, prev_right;

		FOR(i,1,n) {
			FOR(shift,0,ingredients[i].size()) {
				left_element = ingredients[i][shift].first;
				right_element = ingredients[i][(shift+ingredients[i].size()-1) % ingredients[i].size()].first;
				val = max(maxims[i-1].first + i * left_element, maxims[i-1].second - i * left_element);
				ingredients[i][shift].second = val;
				maxims[i].first = max(maxims[i].first, val - (i+1) * right_element);
				maxims[i].second = max(maxims[i].second, val + (i+1) * right_element);
			}
		}

		ll res = 0;
		FOR(i,0,ingredients[n-1].size()) {
			res = max(res, ingredients[n-1][i].second);
		}

		printf("%lld\n", res);
	}
	return 0;
}
