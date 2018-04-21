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

char s[100][100];
char ss[110];
bool valid(ll i, ll j, ll n, ll m) {
	return (i >= 0 and i < n and j >= 0 and j < m and s[i][j] != '#');
}

int main() {
	ll i,j,t,n,m,si,sj,ei,ej;
	ll cnt = 0;
	S(n);S(m);
	FOR(i,0,n) {
		// FOR(j,0,m) {
		// 	printf("i=%lld j=%lld\n", i,j);
		// 	scanf("%c", &s[i][j]);
		// 	if (s[i][j] == 'S') {
		// 		si = i, sj = j;
		// 	}
		// 	else if (s[i][j] == 'E') {
		// 		ei = i, ej = j;
		// 	}
		// }
		scanf("%s", s[i]);
	}
	FOR(i,0,n) {
		FOR(j,0,m) {
			if (s[i][j] == 'S') {
				si = i, sj = j;
			}
			else if (s[i][j] == 'E') {
				ei = i, ej = j;
			}	
		}
	}
	// printf("ei = %lld ej = %lld\n", ei,ej);
	// printf("si = %lld sj = %lld\n", si,sj);
	scanf("%s", ss);
	t =strlen(ss);
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	vi d = {0,1,2,3};
	do {
		ll nxi = si, nxj = sj;
		// cout << d[0] << d[1] << d[2] << d[3] << endl;
		FOR(i,0,t) {
			nxi = nxi + dx[d[int(ss[i] - '0')]];
			nxj = nxj + dy[d[int(ss[i] - '0')]];
			if (!valid(nxi,nxj,n,m)) {
				break;
			}
			else if(s[nxi][nxj] == 'E') {
				cnt++;
				break;
			}
		}
	}while(next_permutation(all(d)));
	printf("%lld\n", cnt);
	return 0;
}