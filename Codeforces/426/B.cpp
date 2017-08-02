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

// #ifndef ONLINE_JUDGE
// #define gc getchar
// #define pc putchar
// #else
// #define gc getchar_unlocked
// #define pc putchar_unlocked
// #endif

using namespace std;

// int read_int() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     int ret = 0, neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

// ll read_ll() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     ll ret = 0;
//     int neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,k;
	string s;
	cin >> n >> k;

	cin >> s;
	vector<ll> start(26), end(26);
	FOR(i,0,26) {
		start[i] = end[i] = -1;
	}
	FOR(i,0,n) {
		if (start[s[i] - 'A'] == -1)
			start[s[i] - 'A'] = i;
		end[s[i] - 'A'] = i;
	}
	sort(all(start));
	sort(all(end));
	i = 0, j = 0;
	while (start[i] == -1) {
		i++; j++;
	}
	ll maxim = 0, counter = 0;
	while (i < 26 && j < 26) {
		if (start[i] <= end[j]) {
			if (start[i] != -1) {
				counter++;
				maxim = max(maxim, counter);
			}
			i++;
		}
		else {
			if (end[j] != -1)
				counter--;
			j++;
		}
	}
	if (maxim > k)
		cout <<"YES";
	else
		cout <<"NO";

	return 0;
}