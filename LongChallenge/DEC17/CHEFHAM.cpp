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

struct singlet {
	ll val, index;
};

struct doublet {
	ll val, index1, index2;
};

int main() {
	ll i,j,t,n,index,index1,index2;
	t = read_ll();
	while (t--) {
		n = read_ll();
		vi a(n), b(n);
		vector<int> freq(100005, 0);
		vector<pp > indices(100005);
		vector<singlet> singlets;
		vector<doublet> doublets;
		FOR(i,0,n) {
			a[i] = read_ll();
			freq[a[i]] += 1;
			if (freq[a[i]] == 1) {
				indices[a[i]].first = i;
			}
			else {
				indices[a[i]].second = i;
			}
		}
		FOR(i,0,freq.size()) {
			if (freq[i] == 1) {
				singlets.pb(singlet{i, indices[i].first});
			}
			else if (freq[i] == 2) {
				doublets.pb(doublet{i, indices[i].first, indices[i].second});
			}
		}
		if (doublets.size() > 1 and singlets.size() > 1) {
			printf("%lld\n", n);
			FOR(i,0,doublets.size()) {
				b[doublets[i].index1] = b[doublets[i].index2] = doublets[(i+1) % doublets.size()].val;
			}
			FOR(i,0,singlets.size()) {
				b[singlets[i].index] = singlets[(i+1) % singlets.size()].val;
			}
		}
		else if (doublets.size() > 1) {
			printf("%lld\n", n);
			FOR(i,0,doublets.size()) {
				b[doublets[i].index1] = b[doublets[i].index2] = doublets[(i+1) % doublets.size()].val;
			}
			if (singlets.size() > 0) {
				b[singlets[0].index] = b[doublets[0].index1];
				b[doublets[0].index1] = singlets[0].val;
			}
		}
		else if (singlets.size() > 1) {
			printf("%lld\n", n);
			FOR(i,0,singlets.size()) {
				b[singlets[i].index] = singlets[(i+1) % singlets.size()].val;
			}
			if (doublets.size() > 0) {
				b[doublets[0].index1] = b[singlets[0].index];
				b[doublets[0].index2] = b[singlets[1].index];
				b[singlets[0].index] = b[singlets[1].index] = doublets[0].val;
			}
		}
		else {
			if (doublets.size() == 1 and singlets.size() == 1) {
				printf("2\n");
				b[doublets[0].index1] = b[singlets[0].index] = doublets[0].val;
				b[doublets[0].index2] = singlets[0].val;
			}
			else if (doublets.size() == 1) {
				printf("0\n");
				b[0] = b[1] = a[0];
			}
			else {
				printf("0\n");
				b[0] = a[0];
			}
		}

		FOR(i,0,n) {
			printf("%lld ", b[i]);
		}

		printf("\n");
	}
	return 0;
}