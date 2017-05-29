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

vi arr;
ll n,l,a,b;

ll abs_sum(ll position) {
	ll i,sum = 0;
	FOR(i,0,n) {
		sum += abs(arr[i]-(position + i * l));
	}
	return sum;
}

void ternary_search() {
	ll low = a, high = b - n*l,mid_l,mid_r;
	ll val_l, val_r, res = INF;
	// cout << "low = " << low << " high = " << high << endl;

	while(low <= high) {
		// cout << "low = " << low << " high = " << high << endl;
		mid_l = low + (high - low)/3;
		mid_r = high - (high - low)/3;

		val_l = abs_sum(mid_l);
		val_r = abs_sum(mid_r);

		if(val_l < val_r) {
			high = mid_r - 1;
		}
		else {
			low = mid_l + 1;
		}
		// cout << "val_l = " << val_l << " val_r = " << val_r << endl;
		res = min(res,min(val_l,val_r));
	}

	printf("%lld\n", res);
}

int main() {
	ll i,j,t;
	t = read_ll();
	while (t--) {
		n = read_ll();
		l = read_ll();
		a = read_ll();
		b = read_ll();

		arr.resize(n);

		FOR(i,0,n) {
			arr[i] = read_ll();
		}
		sort(all(arr));
		ternary_search();
	}
	return 0;
}