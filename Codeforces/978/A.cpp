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
	ll i,j,t,n;
	sll(n);
	vi a(n);
	list<ll> res;
	vector<bool> is(1005,false);
	READ(a,i,n);
	FREV(i,n-1,0) {
		if (is[a[i]] == false) {
			is[a[i]] = true;
			res.push_front(a[i]);
		}
	}
	printf("%u\n", res.size());
	for(auto elem : res) {
		printf("%lld ", elem);
	}
	return 0;
}