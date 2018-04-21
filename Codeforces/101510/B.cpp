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

ll nCr(ll n, ll r) {
	ll i, ans = 1;
	r = min(r,n-r);
	FOR(i,0,r) {
		ans *= (n-i)/(i+1);
	}
	return ans;
}

int main() {
	ll i,j,t,n,A,B,r1,s1,r2,s2;
	S(A);S(B);
	S(r1);S(s1);S(r2);S(r2);
	vi res(10,0);

	// Straight flush
	if (s1 != s2 or abs(r1-r2) > 4) {
		res[1] = 0
	}
	else {
		ll done = abs(r1-r2) + 1;
		res[1] = 5 - done + 1;
	}

	// Four of a kind
	if (r1 != r2) {
		res[2] = 2 * nCr(B-1,3);
	}
	else {
		res[2] = nCr(B-1,2) * ((A-1)*B);
	}

	// Full House
	if (r1 != r2) {
		res[3] = nCr(B-1,2) * nCr(B-1,1) * 2;
	}
	else {
		res[3] = nCr(B-2,1) * nCr(B,2) * (A-1) + nCr(B,3) * (A-1);
	}

	// Flush
	if (s1 != s2) {
		res[4] = 0;
	}
	else {
		res[4] = nCr(A-2,3) - res[1];
	}

	// Straight
	if(abs(r1-r2) > 4 or r1 == r2) {
		res[5] = 0;
	}
	else {
		ll middle = pow(B,(abs(r1-r2) - 1));
		ll rem = 5 - abs(r1-r2) - 1;
		ll sides = (rem+1) * pow(B,rem);
		res[5] = middle * sides;
	}
	return 0;
}