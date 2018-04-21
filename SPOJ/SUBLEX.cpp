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

ll P[20][100000];
vector<ll> sa, lcp;

struct triplet {
	ll index, first, second;
};

bool comp(triplet a, triplet b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void build_suffix_array(string s) {
	const ll n = s.length();
	const ll lgn = ceil(log2(n));

	vector<triplet> ranks(n);

	ll i, j;

	FOR(j,0,n) {
		P[0][j] = s[j] - 'a';
	}

	FOR(i,1,lgn+1) {
		FOR(j,0,n) {
			ranks[j].index = j;
			ranks[j].first = P[i-1][j];
			ranks[j].second = (j + pow(2,i-1) < n) ? P[i-1][j + (ll)pow(2,i-1)] : -1; 
		}
		sort(all(ranks), comp);

		FOR(j,0,n) {
			P[i][ranks[j].index] = (j > 0 and ranks[j].first == ranks[j-1].first and ranks[j].second == ranks[j-1].second) ? P[i][ranks[j-1].index] : j;
		}
	}

	sa.resize(n);

	FOR(i,0,n) {
		sa[P[lgn][i]] = i;
	}
}

void build_lcp_array(ll n) {
	lcp.resize(n);
	ll k, i, j, x, delta, step = ceil(log2(n));

	FOR(k,1,n) {
		i = k;
		j = i-1;
		lcp[i] = 0;
		FREV(x,step,0) {
			if (P[x][sa[i]] == P[x][sa[j]]) {
				delta = pow(2,x);
				lcp[i] += delta;
				i += delta;
				j += delta;
			}
		}
	}
}

int main() {
	ll i,j,t,n,q,k;
	string s;
	cin >> s;
	n = s.length();
	build_suffix_array(s);
	build_lcp_array(n);
	vector<ll> cumulative(n);
	cumulative[0] = n - sa[0];
	FOR(i,1,n) {
		cumulative[i] = cumulative[i-1] + (n - sa[i] - lcp[i]);
	}
	q = read_ll();
	while (q--) {
		k = read_ll();
		if (k > cumulative[n-1]) {
			cout << "" << endl;
			continue;
		}
		ll pos = lower_bound(all(cumulative), k) - cumulative.begin();
		cout << s.substr(sa[pos], k - (pos > 0 ? cumulative[pos-1] : 0) + lcp[pos]) << endl;
	}
	return 0;
}
