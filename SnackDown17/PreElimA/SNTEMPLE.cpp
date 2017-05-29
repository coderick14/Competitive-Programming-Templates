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

vi a(100005),inc(100005),decreasing(100005);

int main() {
	ll i,j,t,n,maxim;
	ull sum;
	t = read_ll();
	while (t--) {
		n = read_ll();
		sum = 0;
		FOR(i,1,n+1) {
			a[i] = read_ll();
			sum += a[i];
		}
		// if (n == 1) {
		// 	cout << a[1] - 1<<"\n";
		// }
		inc[0] = 0;
		decreasing[n+1] = 0;
		FOR(i,1,n+1) {
			if (a[i] >= i) {
				inc[i] = inc[i-1] + 1;
			}
			else {
				inc[i] = min(a[i], inc[i-1]+1);
			}
			// inc[i] = (inc[i] > inc[i-1]) ? (inc[i-1] + 1) : 1;
		}

		FREV(i,n,1) {
			if (a[i] >= n-i+1) {
				decreasing[i] = decreasing[i+1] + 1;
			}
			else {
				decreasing[i] = min(a[i],decreasing[i+1]+1);
			}
			// decreasing[i] = (decreasing[i] > decreasing[i+1]) ? (decreasing[i+1] + 1) : 1;
		}
		// FOR(i,0,n) {
		// 	cout<<"i = "<<i<<" inc = "<<inc[i]<<" dec = "<<decreasing[i]<<endl;
		// }
		maxim = inc[1] + decreasing[1] - 1;
		FOR(i,2,n+1) {
			if(inc[i] + decreasing[i] - 1 > maxim) {
				maxim = inc[i] + decreasing[i] - 1;
			}
		}
		// cout<<"max = "<<maxim<<endl;

		if(maxim%2 == 0) {
			maxim -= 1;
		}
		maxim = (maxim-1)/2;
		maxim += 1;
		sum = sum - (maxim * maxim);
		printf("%llu\n", sum);
	}

	return 0;
}