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

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,res;
	t = read_ll();
	string s;
	while (t--) {
		res = 0;
		cin >> s;
		n = s.length();
		for(i=0;i<n and s[i] != '<';i++);
		while (i < n) {
			j = 0;
			while (s[i] == '<' or s[i] == '=') {
				if (s[i] == '<')
					j++;
				i++;
			}
			if (j > res)
				res = j;
			while (i < n and s[i] != '<')
				i++;
		}

		for(i=0;i<n and s[i] != '>';i++);
		while (i < n) {
			j = 0;
			while (s[i] == '>' or s[i] == '=') {
				if (s[i] == '>')
					j++;
				i++;
			}
			if (j > res)
				res = j;
			while (i < n and s[i] != '>')
				i++;
		}

		cout << res + 1 << "\n";
	}
	return 0;
}