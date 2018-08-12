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
	ll i,j,k,t,n,res = INF;
	sll(n);
	vi a(n);
	READ(a,i,n);
	if (n == 1 or n == 2) {
		printf("0\n");
		return 0;
	}
	vector<int> diff {0,-1,1};
	FOR(i,0,3) {
		FOR(j,0,3) {
			ll a0 = a[0] + diff[i];
			ll a1 = a[1] + diff[j];
			ll curdiff = a1 - a0;
			ll expected = a1 + curdiff;
			ll cur_res = abs(a[0] - a0) + abs(a[1] - a1);
			FOR(k,2,n) {
				if (abs(expected - a[k]) > 1) {
					break;
				}
				else if (expected != a[k]) {
					cur_res++;
				}
				expected += curdiff;
			}
			if (k >= n) {
				// cout << a0 << " " << a1 << " " << cur_res << " " << res << endl;
				res = min(res,cur_res);
			}
		}
	}
	if (res == INF)
		res = -1;
	printf("%lld\n", res);
	return 0;
}