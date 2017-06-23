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

ll X[100005], Y[100005], Z[100005], prefixX[100005], prefixY[100005], prefixZ[100005];

int main() {
	ll i,j,t,p,q,r;
	t = read_ll();
	while(t--) {
		p = read_ll();
		q = read_ll();
		r = read_ll();

		FOR(i,0,p) {
			X[i] = read_ll();
		}
		FOR(i,0,q) {
			Y[i] = read_ll();
		}
		FOR(i,0,r) {
			Z[i] = read_ll();
		}

		sort(X,X+p);
		sort(Y,Y+q);
		sort(Z,Z+r);

		prefixX[0] = X[0], prefixY[0] = Y[0], prefixZ[0] = Z[0];

		FOR(i,1,p) {
			prefixX[i] = (prefixX[i-1] + X[i]) % MOD;
		}
		FOR(i,1,q) {
			prefixY[i] = (prefixY[i-1] + Y[i]) % MOD;
		}
		FOR(i,1,r) {
			prefixZ[i] = (prefixZ[i-1] + Z[i]) % MOD;
		}

		ll x_pointer = 0, z_pointer = 0, sum = 0;
		FOR(i,0,q) {
			while (x_pointer < p && X[x_pointer] <= Y[i])
				x_pointer++;
			while (z_pointer < r && Z[z_pointer] <= Y[i])
				z_pointer++;

			// cout << Y[i] << " x-> "<<x_pointer<<" z-> "<<z_pointer<<endl;
			x_pointer--;
			z_pointer--;

			sum = ((sum + (((z_pointer+1) * (prefixX[x_pointer]) % MOD)*Y[i])%MOD)%MOD + ((((x_pointer+1) * (prefixZ[z_pointer]) % MOD)*Y[i])%MOD + (prefixX[x_pointer] * prefixZ[z_pointer])%MOD)%MOD + (((((x_pointer+1)*(z_pointer+1))%MOD)*Y[i])%MOD * Y[i])%MOD)%MOD;
		}
		printf("%lld\n", sum);
	}	
	return 0;
}