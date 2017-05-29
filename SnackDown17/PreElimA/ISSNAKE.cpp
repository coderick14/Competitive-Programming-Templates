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
char grid[2][505];
int main() {
	ll i,j,t,n;
	t = read_ll();
	while(t--) {
		n = read_ll();
		bool flag = true;

		FOR(i,0,n) {
			cin >> grid[0][i];
		}
		FOR(i,0,n) {
			cin >> grid[1][i];
		}

		i = 0;

		while(grid[0][i] == '.' && grid[1][i] == '.') {
			i++;
		}

		int prev_hash_row = -1;
		int double_hash_count = 0;

		while(i<n) {
			if(grid[0][i] == '#' && grid[1][i] == '#') {
				i++;
				double_hash_count++;
			}
			else if(grid[0][i] == '.' && grid[1][i] == '#') {
				if(prev_hash_row != -1) {
					if((double_hash_count%2 == 0 && prev_hash_row == 0) || (double_hash_count%2 == 1 && prev_hash_row == 1)) {
						flag = false;
						break;
					}
					else {
						prev_hash_row = 1;
					}
				}
				else {
					prev_hash_row = 1;
				}
				double_hash_count = 0;
				i++;
			}
			else if(grid[0][i] == '#' && grid[1][i] == '.') {
				if(prev_hash_row != -1) {
					if((double_hash_count%2 == 0 && prev_hash_row == 1) || (double_hash_count%2 == 1 && prev_hash_row == 0)) {
						flag = false;
						break;
					}
					else {
						prev_hash_row = 0;
					}
				}
				else {
					prev_hash_row = 0;
				}
				double_hash_count = 0;
				i++;
			}
			else {
				i++;
				break;
			}
			// cout << "prev_hash_row = "<<prev_hash_row<<" double_hash_count = "<<double_hash_count<<endl;
		}
		if(flag) {
			while(i<n) {
				if(grid[0][i] != '.' || grid[1][i] != '.') {
					printf("no\n");
					break;
				}
				i++;
			}
			if(i >= n)
				printf("yes\n");
		}
		else {
			printf("no\n");
		}

	}
	return 0;
}