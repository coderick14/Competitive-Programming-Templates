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

ll n;
vi c,ec;

ll solve(ll k) {
	if (k <= 0) {
		return 0LL;
	}
	ll i = n-1, single_cost = INF, curr_cost = INF;
	while (i >= 0 and (1 << i) >= k) {
		single_cost = min(single_cost, c[i]);
		i--;
	}
	if (i < 0) {
		return single_cost;
	}
	curr_cost = (k / (1 << i)) * ec[i];
	return min(single_cost, curr_cost + solve(k % (1 << i)));
}

int main() {
	ll i,j,t,k;
	sll(n);sll(k);
	c.resize(n);
	ec.resize(n);
	READ(c,i,n);
	ec[0] = c[0];
	FOR(i,1,n) {
		ec[i] = min(c[i], 2*ec[i-1]);
	}
	printf("%lld", solve(k));
	return 0;
}
