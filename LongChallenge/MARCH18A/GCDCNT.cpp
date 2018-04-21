/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
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

typedef __gnu_pbds::tree<
ll,
__gnu_pbds::null_type,
less<ll>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>
ordered_set;

ll MAXN = 100005;
ordered_set cnt[100006];
vi lpf(MAXN+1,0);
// vi primes;
vi a;

void sieve() {
	ll i,p;
	for(p=2; p*p <= MAXN; p++) {
		if (lpf[p] == 0) {
			for(i=2*p; i <= MAXN; i += p) {
				lpf[i] = p;
			}
		}
	}

	for(p=2; p <= MAXN; p++) {
		if (lpf[p] == 0) {
			// primes.pb(p);
			lpf[p] = p;
		}
	}
}

void apply_mask(vi &distinct_primes, ll idx) {
	// cout << "combinations for " << a[idx] << "\n";
	ll prod, i, j, sz = distinct_primes.size();
	for(i=1; i < (1 << sz) ; i++) {
		prod = 1;
		for (j = 0; j < sz; j++) {
			if ((1 << j) & i) {
				prod *= distinct_primes[j];
			}
		}
		// cout << prod << " ";
		cnt[prod].insert(idx);
	}
	// cout << "\n";
}

void remove_mask(vi &distinct_primes, ll idx) {
	ll prod, i, j, sz = distinct_primes.size();
	for(i=1; i < (1 << sz) ; i++) {
		prod = 1;
		for (j = 0; j < sz; j++) {
			if ((1 << j) & i) {
				prod *= distinct_primes[j];
			}
		}
		cnt[prod].erase(idx);
	}
}

ll query(vi &distinct_primes, ll ql, ll qr) {
	ll diff, prime_count, prod, i, j, sz = distinct_primes.size(), ans = 0;
	for(i=1; i < (1 << sz) ; i++) {
		prod = 1;
		prime_count = 0;
		for (j = 0; j < sz; j++) {
			if ((1 << j) & i) {
				prime_count++;
				prod *= distinct_primes[j];
			}
		}

		ll diff = cnt[prod].order_of_key(qr+1) - cnt[prod].order_of_key(ql);
		// printf("prod  = %lld lessThanEqualToR = %lld lessThanL = %lld\n", prod, ltr, ltl);
		if (prime_count & 1) {
			ans = ans + diff;	
		}
		else {
			ans = ans - diff;
		}
	}
	return ans;
}

vi factorize(ll n) {
	ll i;
	vi distinct_primes;
	while (n > 1) {
		i = lpf[n];
		while (n % i == 0) {
			n /= i;
		}
		distinct_primes.pb(i);
	}
	return distinct_primes;
}

void prnvec(vi &v, ll num) {
	cout << "distinct_primes of " << num << "\n";
	ll i;
	FOR(i,0,v.size()) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main() {
	ll i,j,t,n,q,ch,idx,newval,ql,qr,g,ans;
	vi distinct_primes;
	sieve();
	n = read_ll();
	a.resize(n);
	FOR(i,0,n) {
		a[i] = read_ll();
		distinct_primes = factorize(a[i]);
		// prnvec(distinct_primes, a[i]);
		apply_mask(distinct_primes, i);
	}

	q = read_ll();
	FOR(i,0,q) {
		ch = read_ll();
		if (ch == 1) {
			idx = read_ll();
			newval = read_ll();
			idx -= 1;
			distinct_primes = factorize(a[idx]);
			remove_mask(distinct_primes, idx);
			distinct_primes = factorize(newval);
			// prnvec(distinct_primes, newval);
			apply_mask(distinct_primes, idx);
			a[idx] = newval;
		}
		else {
			ql = read_ll();
			qr = read_ll();
			g = read_ll();
			ql -= 1; qr -= 1;

			distinct_primes = factorize(g);
			// prnvec(distinct_primes, g);
			ans = (qr-ql+1) - query(distinct_primes, ql, qr);
			printf("%lld\n", ans);
		}
	}
	return 0;
}