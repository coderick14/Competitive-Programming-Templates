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
	ll i,j,t,n,streak[2];
	string s;
	t = read_ll();
	while(t--) {
		cin >> s;
		streak[0] = read_ll();
		streak[1] = read_ll();
		n = s.length();

		vi count(2,0);

		FOR(i,0,n) {
			count[s[i] - 'a']++;
		}
		
		ll min_a = ceil(float(count[0]) / streak[0]);
		ll max_a = count[0];

		ll min_b = ceil(float(count[1]) / streak[1]);
		ll max_b = count[1];

		if (max_a < min_b or max_b < min_a) {
			int turn = (max_a < min_b) ? 1 : 0;
			while(count[0] > 0 or count[1] > 0) {
				FOR(i,0,min(streak[turn],count[turn])) {
					printf("%c", 'a' + turn);
				}
				count[turn] -= min(streak[turn] ,count[turn]);
				if (count[1-turn] > 0) {
					printf("%c", 'b' - turn);
					count[1-turn]--;
				}
				else if (count[turn] > 0) {
					printf("*");
				}
			}
		}
		else {
			ll num, rem;
			int turn;
			if (max_a >= max_b) {
				num = count[0] / max_b;
				rem = count[0] % max_b;
				turn = 0; 
			}
			else {
				num = count[1] / max_a;
				rem = count[1] % max_a;
				turn = 1;
			}

			while(count[0] > 0 or count[1] > 0) {
				FOR(i,0,min(num,count[turn])) {
					printf("%c", 'a' + turn);
				}
				count[turn] -= min(num, count[turn]);
				if (rem > 0) {
					printf("%c", 'a' + turn);
					count[turn] -= 1;
					rem--;
				}
				if (count[1-turn] > 0) {
					printf("%c", 'b' - turn);
					count[1-turn]--;
				} 
			}
		}
		printf("\n");

	}
	return 0;
}