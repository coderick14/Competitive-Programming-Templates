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

// struct point {
// 	ll i,j;
// };

// struct snake {
// 	point start;
// 	point end;
// };

// vector<snake> snakes;
vector<pp > row_attax, col_attax;
ll n,k,m,low,high;

class Prioritize {
public:
	int operator() (pp a, pp b) {
		return a.second < b.second;
	}
};

ll handle_row_attax() {
	ll taken_count = 0;
	ll last_covered = -INF, current_point = low, current_interval_index = 0;
	priority_queue<pp, vector<pp >, Prioritize> active_intervals;
	active_intervals.push(mp(-INF,-INF));

	while (current_point <= high && current_interval_index < m) {
		if (current_point < row_attax[current_interval_index].first) {
			pp interval = active_intervals.top();
			active_intervals.pop();
			if (current_point > interval.second) {
				return -1;
			}
			taken_count += 1;
			current_point = interval.second + 1;
		}
		else {
			active_intervals.push(row_attax[current_interval_index]);
			current_interval_index++;
		}
	}
	while (current_point <= high) {
		pp interval = active_intervals.top();
		active_intervals.pop();
		if (current_point > interval.second) {
			return -1;
		}
		taken_count += 1;
		current_point = interval.second + 1;
	}
	return taken_count;
}

ll handle_col_attax() {
	ll taken_count = 0;
	ll last_covered = -INF, current_point = low, current_interval_index = 0;
	priority_queue<pp, vector<pp >, Prioritize> active_intervals;
	active_intervals.push(mp(-INF,-INF));

	while (current_point <= high && current_interval_index < m) {
		if (current_point < col_attax[current_interval_index].first) {
			pp interval = active_intervals.top();
			active_intervals.pop();
			if (current_point > interval.second) {
				return -1;
			}
			taken_count += 1;
			current_point = interval.second + 1;
		}
		else {
			active_intervals.push(col_attax[current_interval_index]);
			current_interval_index++;
		}
	}
	while (current_point <= high) {
		pp interval = active_intervals.top();
		active_intervals.pop();
		if (current_point > interval.second) {
			return -1;
		}
		taken_count += 1;
		current_point = interval.second + 1;
	}
	return taken_count;
}

int main() {
	ll i,j,t,x1,y1,x2,y2;
	t = read_ll();
	while(t--) {
		n = read_ll();
		k = read_ll();
		m = read_ll();

		// snakes.resize(m);
		row_attax.resize(m);
		col_attax.resize(m);

		low = (n-k)/2 + 1;
		high = (n-k)/2 + k;

		FOR(i,0,m) {
			x1 = read_ll();
			y1 = read_ll();
			x2 = read_ll();
			y2 = read_ll();
	
			// snakes[i].start.i = (x1 < x2) ? x1 : x2;
			// snakes[i].start.j = (y1 < y2) ? y1 : y2;
			// snakes[i].end.i = (x1 < x2) ? x2 : x1;
			// snakes[i].end.j = (y1 < y2) ? y2 : y1;

			row_attax[i] = mp((x1 < x2) ? x1 : x2, (x1 < x2) ? x2 : x1);
			col_attax[i] = mp((y1 < y2) ? y1 : y2, (y1 < y2) ? y2 : y1);	
		}

		sort(all(row_attax));
		sort(all(col_attax));
		// cout << "low = "<<low<<" high = "<<high<<endl;
		// FOR(i,0,n) {
		// 	cout << row_attax[i].first <<" "<< row_attax[i].second<<endl;
		// }
		// cout<<"======================================================================\n";
		// FOR(i,0,n) {
		// 	cout << col_attax[i].first <<" "<< col_attax[i].second<<endl;
		// }
		ll val1 = handle_row_attax();
		ll val2 = handle_col_attax();
		if (val1 == -1 || val2 == -1) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", val1 + val2);
		}
	}
	return 0;
}