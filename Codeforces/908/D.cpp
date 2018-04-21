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
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { sll(a[i]);}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define INF 1e18
#define MOD 1000000007

using namespace std;

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

ll dp[1003][1003];
ll k,p1,p2,inv,mean;

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

// Multiplicative modular inverse using Extended Euclid's Algorithm
ll find_inverse(ll n, ll mod) {
	ll x,y;
	xGCD(n,mod,x,y);

	if (x < 0) {
		x = x + mod;
	}

	return x;
}

ll solve(ll i, ll j) {
	if (j >= k) {
		return j;
	}
	if (i == k) {
		return ((j+k) % MOD + mean) % MOD;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	return (dp[i][j] = ((p1 * solve(i+1,j)) % MOD + (p2 * solve(i,i+j)) % MOD) % MOD);
}

int main() {
	ll i,j,t,n;
	sll(k);sll(p1);sll(p2);
	inv = find_inverse(p1+p2, MOD);
	p1 = (p1 * inv) % MOD;
	p2 = (p2 * inv) % MOD;
	mean = (((1 + (MOD - p2)) % MOD) * find_inverse(p2, MOD)) % MOD;

	FOR(i,0,k+1) {
		FOR(j,0,k+1) {
			dp[i][j] = -1;
		}
	}

	printf("%lld\n", solve(1,0));
	return 0;
}