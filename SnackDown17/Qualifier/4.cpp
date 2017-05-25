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

struct point {
	ll x,y;
};

bool check(point a, point b) {
	return (a.x == b.x && a.y == b.y);
}

int main() {
	ll i,j,t,n;
	vector<pair<point,point> > snakes(2);
	t = read_ll();
	while(t--) {
		snakes[0].first.x = read_ll();
		snakes[0].first.y = read_ll();
		snakes[0].second.x = read_ll();
		snakes[0].second.y = read_ll();

		snakes[1].first.x = read_ll();
		snakes[1].first.y = read_ll();
		snakes[1].second.x = read_ll();
		snakes[1].second.y = read_ll();

		// both horizontal
		if (snakes[0].first.y == snakes[0].second.y && snakes[1].first.y == snakes[1].second.y) {
			// cout<<"horizontal\n";
			if (snakes[0].first.y != snakes[1].first.y) {
				printf("no\n");
				continue;
			}

			// first snake is on the left
			if (min(snakes[0].first.x, snakes[0].second.x) <= min(snakes[1].first.x, snakes[1].second.x)) {
				if (max(snakes[0].first.x, snakes[0].second.x) >= min(snakes[1].first.x, snakes[1].second.x)) {
					printf("yes\n");
				}
				else {
					printf("no\n");
				}
			}
			// second snake is on the left
			else {	
				if (max(snakes[1].first.x, snakes[1].second.x) >= min(snakes[0].first.x, snakes[0].second.x)) {
					printf("yes\n");
				}
				else {
					printf("no\n");
				}
			}
		}
		// both vertical
		else if (snakes[0].first.x == snakes[0].second.x && snakes[1].first.x == snakes[1].second.x) {
			// cout<<"vertical\n";
			if (snakes[0].first.x != snakes[1].first.x) {
				printf("no\n");
				continue;
			}
			// first snake is on top
			if (max(snakes[0].first.y, snakes[0].second.y) >= max(snakes[1].first.y, snakes[1].second.y)) {
				if (max(snakes[1].first.y, snakes[1].second.y) >= min(snakes[0].first.y, snakes[0].second.y)) {
					printf("yes\n");
				}
				else {
					printf("no\n");
				}
			}
			// second snake is on top
			else {	
				if (max(snakes[0].first.y, snakes[0].second.y) >= min(snakes[1].first.y, snakes[1].second.y)) {
					printf("yes\n");
				}
				else {
					printf("no\n");
				}
			}
		}
		// one horizontal and one vertical
		else {
			// cout<<"horiver\n";
			bool is_same = check(snakes[0].first, snakes[1].first) || check(snakes[0].first, snakes[1].second) || check(snakes[0].second, snakes[1].first) || check(snakes[0].second, snakes[1].second);
			if (is_same) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
	return 0;
}