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

// Extended Euclid's Algorithm
ll xGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
	ll i,j,t,n,x,y,a,b,d;
	S(n);S(a);S(b);
	ll gcd = xGCD(a,b,x,y);
	d = gcd;
	if (n % gcd != 0) {
		printf("NO");
		return 0;
	}
	ll factor = n / gcd;
	x *= factor;
	y *= factor;
	if (x >= 0 and y >= 0) {
		printf("YES\n%lld %lld\n", x, y);
	}
	else if (x < 0) {
		t = (abs(x) * d) / b;
		x = x + (t * b) / d;
		if (x < 0) {
			x = x + b / d;
			t++;
		}
		y = y - (t * a) / d;
		if (y >= 0) {
			printf("YES\n%lld %lld\n", x, y);
		}
		else {
			printf("NO\n");
		}
	}
	else if (y < 0) {
		t = (abs(y) * d) / a;
		y = y + (t * a) / d;
		if (y < 0) {
			y = y + a / d;
			t++;
		}
		x = x - (t * b) / d;
		if (x >= 0) {
			printf("YES\n%lld %lld\n", x, y);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}