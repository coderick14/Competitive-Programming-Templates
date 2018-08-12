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

int main() {
	ll i,j,t,n,w,res;
	sll(n);
	sll(w);
	vi a(n);
	READ(a,i,n);
	ll minim = a[0], maxim = a[0];
	FOR(i,1,n) {
		a[i] += a[i-1];
		minim = min(minim, a[i]);
		maxim = max(maxim, a[i]);
	}
	if (maxim > w or (minim < 0 and abs(minim) > w)) {
		res = 0;
	}
	else {
		res = w - max(maxim,0LL) + 1;
		if (minim < 0) {
			res = res - abs(minim);
		}
	}
	res = max(res,0LL);
	printf("%lld\n", res);
	return 0;
}