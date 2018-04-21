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
	ll i,j,t,n,m,k;
	sll(n);sll(m);sll(k);

	char mat[2005][2005];
	FOR(i,0,n) {
		scanf("%s",mat[i]);
	}
	ll ans = 0;
	if (k == 1) {
		FOR(i,0,n) {
			FOR(j,0,m) {
				if (mat[i][j] == '.') {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	// FOR(i,0,n) {
	// 	FOR(j,0,m) {
	// 		cout<<mat[i][j];
	// 	}
	// 	cout<<endl;
	// }
	FOR(i,0,n) {
		ll cnt = 0;
		FOR(j,0,m) {
			if (mat[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= k) {
					ans += (cnt-k+1);
				}
				cnt = 0;
			}
		}
		if (cnt >= k) {
			ans += (cnt-k+1);
		}
	}
	FOR(j,0,m) {
		ll cnt = 0;
		FOR(i,0,n) {
			if (mat[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= k) {
					ans += (cnt-k+1);
				}
				cnt = 0;
			}
		}
		if (cnt >= k) {
			ans += (cnt-k+1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}