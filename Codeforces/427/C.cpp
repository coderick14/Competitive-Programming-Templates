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

struct star {
	ll x,y,b;
};

vector<star> stars;

int main() {
	ll i,j,t,n,q,c,x1,y1,x2,y2,x,y,k,b;
	S(n);S(q);S(c);
	ll sky[c+1][105][105];
	stars.resize(n);

	FOR(k,0,c+1) {
		FOR(i,0,105) {
			FOR(j,0,105) {
				sky[k][i][j] = 0;
			}
		}
	}

	FOR(i,0,n) {
		S(stars[i].x);S(stars[i].y);S(stars[i].b);

		sky[0][stars[i].x][stars[i].y] += stars[i].b;
	}

	FOR(k,1,c+1) {
		FOR(i,0,n) {
			sky[k][stars[i].x][stars[i].y] = sky[k-1][stars[i].x][stars[i].y];
		}
		FOR(i,0,n) {
			if (stars[i].b == c) {
				sky[k][stars[i].x][stars[i].y] = sky[k][stars[i].x][stars[i].y] - c;
				stars[i].b = 0;
			}
			else {
				sky[k][stars[i].x][stars[i].y] = sky[k][stars[i].x][stars[i].y] + 1;
				stars[i].b += 1;
			}
		}		
	}

	FOR(k,0,c+1) {
		FOR(i,1,105) {
			FOR(j,1,105) {
				sky[k][i][j] += sky[k][i][j-1] + sky[k][i-1][j] - sky[k][i-1][j-1];
			}
		}
	}

	FOR(k,0,q) {
		S(t);S(x1);S(y1);S(x2);S(y2);
		t = t%(c+1);
		
		ll res = sky[t][x2][y2] - sky[t][x1-1][y2] - sky[t][x2][y1-1] + sky[t][x1-1][y1-1];
		printf("%lld\n", res);
	}
	
	return 0;
}