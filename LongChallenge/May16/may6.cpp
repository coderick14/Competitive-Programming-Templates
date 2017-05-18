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
#define INF 1e18

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

vector<ull> a;
map<pair<int,ull> ,ll> dp;
map<pair<int,ull> ,bool> is_memoized;

bool comp(ull a, ull b) {
	return a > b;
}

ll fun(int n, ull k) {	
	if (n == 1) 
		return a[0]<=k;

	if (a[n-1] > k)
		return 0;
	
	if (is_memoized[mp(n,k)] == true) 
		return dp[mp(n,k)];
	 
	dp[mp(n,k)] = fun(n-1,k) + fun(n-1,k/a[n-1]) + 1;
	
	is_memoized[mp(n,k)] = true;
	return dp[mp(n,k)];
}

int main() {
	ll i,j,t;
	int n;
	ull k;
	n = read_int();
	cin>>k;
	a.resize(n);
	FOR(i,0,n) {
		cin>>a[i];
	}
	sort(all(a), comp);
	cout<<fun(n,k)<<"\n";
	return 0;
}