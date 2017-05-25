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

int main() {
	ll i,j,t,n;
	t = read_ll();
	vi a(105);
	while (t--) {
		n = read_ll();
		FOR(i,0,n) {
			a[i] = read_ll();
		}
		if (n%2==0) {
			cout<<"no\n";
			continue;
		}
		bool flag = true;
		FOR(i,0,n/2) {
			if (a[i] != i+1 || a[n-i-1] != i+1) {
				flag = false;
				break;
			}
		}
		if (flag && a[n/2] == (n+1)/2) {
			cout<<"yes\n";
		}
		else {
			cout<<"no\n";
		}

	}
	return 0;
}