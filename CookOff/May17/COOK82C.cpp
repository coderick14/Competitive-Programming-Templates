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

stack<ll> stk;
queue<ll> q;
vi a;

void solve(ll n, ll m) {
	ll i,cur,ans,prev = 1;
	sort(all(a));
	FOR(i,0,n) {
		stk.push(a[i]);
	}
	// ans = stk.top();
	FOR(i,0,m) {
		cur = read_ll();
		while (prev <= cur) {
			if (q.empty() && !stk.empty()) {
				ans = stk.top();
				stk.pop();
			}
			else if (!q.empty() && !stk.empty()) {
				if (stk.top() > q.front()) {
					ans = stk.top();
					stk.pop();				
				}
				else {
					ans = q.front();
					q.pop();					
				}
			}
			else if (stk.empty() && !q.empty()) {
				ans = q.front();
				q.pop();				
			}
			if (ans / 2 > 0) {
				q.push(ans / 2);
			}
			prev++;
		}
		printf("%lld\n", ans);
	}
}

int main() {
	ll i,j,t,n,m;
	n = read_ll();
	m = read_ll();
	a.resize(n);
	FOR(i,0,n) {
		a[i] = read_ll();
	}
	solve(n,m);
	return 0;
}