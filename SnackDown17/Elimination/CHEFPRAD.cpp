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
ll A[300], B[300], temp[300];

ll check(ll A[], ll B[], ll n, ll m, ll y) {
	ll i = 0;
	ll j = 0;
	ll count = 0;
	while(i < n) {
		while(j < m) {
			if(abs(A[i]-B[j]) <= y) {
				count++;
				j++;
				break;
			}
			j++;
		}
		i++;
	}
	return count;
}

int main() {
	ll i,j,t,n,m,y,k;
	t = read_ll();
	while(t--) {
		n = read_ll();
		m = read_ll();
		y = read_ll();
		FOR(i,0,n) {
			A[i] = read_ll();
		}
		FOR(i,0,m) {
			B[i] = read_ll();
		}
		sort(A,A+n);
		sort(B,B+m);

		ll res = check(A,B,n,m,y);
		if (res == min(n,m)) {
			printf("%lld\n", res);
			continue;
		}
		FOR(k,0,n) {
			FOR(i,0,m) {
				ll diff = B[i] + y - A[k];
				FOR(j,0,n) {
					temp[j] = A[j] + diff;
				}
				res = max(res, check(temp,B,n,m,y));
				if (res == min(n,m)) {
					break;
				}
				diff = B[i] - y - A[k];
				FOR(j,0,n) {
					temp[j] = A[j] + diff;
				}
				res = max(res, check(temp,B,n,m,y));
				if (res == min(n,m)) {
					break;
				}

				diff = B[i] - A[k];
				FOR(j,0,n) {
					temp[j] = A[j] + diff;
				}
				res = max(res, check(temp,B,n,m,y));
				if (res == min(n,m)) {
					break;
				}
			}
			if(res == min(n,m))
				break;
		}
		printf("%lld\n", res);
	}
	return 0;
}