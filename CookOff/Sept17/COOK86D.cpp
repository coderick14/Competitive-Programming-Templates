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
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
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

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,m,idx,c;
	n = read_ll();
	m = read_ll();
	set<ll> rr,rc,gr,gc,rd,gd;
	FOR(i,0,m) {
		S(t);S(idx);S(c);
		if (c == 0) {
			if (t == 1) {
				rr.insert(idx);
			}
			else if (t == 2) {
				rc.insert(idx);
			}
			else {
				rd.insert(idx);
			}
		}
		else {
			if (t == 1) {
				gr.insert(idx);
			}
			else if (t == 2) {
				gc.insert(idx);
			}
			else {
				gd.insert(idx);
			}
		}
	}
	ll redcells = n * rr.size() + (n-rr.size()) * rc.size();
	ll greencells = 0, yellowcells = 0;
	for(it = gr.begin(); it != gr.end(); it++) {
		if (rr.find(*it) != rr.end()) {
			redcells -= n;
			yellowcells += n;
			rr.erase(rr.find(*it));
		}
		else {
			redcells -= rc.size();
			yellowcells += rc.size();
		}
	}
	return 0;
}