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
	ll i,j,t,n;
	sll(n);
	vi a(n);
	map<ll,ll> m;
	map<ll,bool> mb;
	FOR(i,0,n) {
		sll(j);
		a[i] = j;
		m[j]++;
		mb[j]=false;
	}
	FOR(i,0,n) {
		if ((a[i] & (a[i]-1)) == 0) {
			if (m[a[i]] > 1) {
				mb[a[i]] = true;
			}
		}
		else {
			FOR(j,0,32) {
				if ((1 << j) > a[i]) {
					if (m.find((1 << j) - a[i]) != m.end()) {
						mb[a[i]] = mb[(1 << j) - a[i]] = true;
					}
				}
			}
		}
	}
	ll res = 0;
	for (auto it = mb.begin(); it != mb.end(); it++) {
		if (it->second == true) {
			res += m[it->first];
		}
	}
	cout << n - res;
	return 0;
}