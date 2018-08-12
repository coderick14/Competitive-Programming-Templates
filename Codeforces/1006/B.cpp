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
#define sc(n) scanf("%c", &n)
#define INF 1000000000000007
#define MOD 1000000007

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,k;
	sll(n);sll(k);
	vector<pp> a(n);
	FOR(i,0,n) {
		sll(a[i].second);
		a[i].first = i;
	}
	sort(all(a), [](pp x, pp  y) { return x.second > y.second;});
	vi indices;
	ll res = 0;
	FOR(i,0,k) {
		res += a[i].second;
		indices.pb(a[i].first);
	}
	sort(all(indices));
	// for (auto idx : indices) {
	// 	cout << idx << endl;
	// }
	printf("%lld\n", res);
	if (k == 1) {
		printf("%lld", n);
		return 0;
	}
	printf("%lld ", indices[0]+1);
	FOR(i,1,k-1) {
		printf("%lld ", indices[i] - indices[i-1]);
	}
	if (k == 2)
	printf("%lld", n - indices[0] - 1);
	else if (k > 2) {
		printf("%lld", n - indices[k-2] - 1);
	}
	return 0;
}