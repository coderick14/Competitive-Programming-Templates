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

struct trainer {
	ll arrival_day;
	ll lectures;
	ll sadness;
};

bool comp(trainer a, trainer b) {
	return a.arrival_day < b.arrival_day;
}

class Prioritize {
	public:
		int operator() (pp a, pp b) {
			return a.first < b.first;
		}
};

vector<trainer> trainers;

int main() {
	ll i,j,t,n,d;
	t = read_ll();
	while (t--) {
		n = read_ll();
		d = read_ll();
		priority_queue<pp, vector<pp >, Prioritize> pq;
		trainers.resize(n);
		FOR(i,0,n) {
			trainers[i].arrival_day = read_ll();
			trainers[i].lectures = read_ll();
			trainers[i].sadness = read_ll();
		}
		sort(all(trainers), comp);
		j = 0;
		FOR(i,1,d+1) {
			while (j < n and trainers[j].arrival_day == i) {
				pq.push(mp(trainers[j].sadness, trainers[j].lectures));
				j++;
			}

			if (!pq.empty()) {
				pp saddest = pq.top();
				pq.pop();
				if (saddest.second > 1) {
					saddest.second -= 1;
					pq.push(saddest);
				}
			}
		}

		ll res = 0;
		while (!pq.empty()) {
			pp left = pq.top();
			pq.pop();
			res += left.first * left.second;
		}
		cout << res << "\n";
	}
	return 0;
}