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

int main() {
	ll i,j,t,n;
	ll goals[4];
	t = read_ll();
	string s;
	while(t--) {
		FOR(i,0,4) {
			cin >> s;
			if(s[0] == 'B') {
				cin >> goals[0];
			}
			else if(s[0] == 'E') {
				cin >> goals[1];
			}
			else if(s[0] == 'R') {
				cin >> goals[2];
			}
			else {
				cin >> goals[3];
			}
		}
		if (goals[0] > goals[1] && goals[2] < goals[3]) {
			cout << "Barcelona\n";
		}
		else {
			cout << "RealMadrid\n";
		}
	}
	return 0;
}