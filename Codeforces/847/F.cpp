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

struct entry {
	ll cand_id;
	ll last_time;
	ll votes;
};

bool comp(entry a, entry b) {
	if (a.votes == b.votes) {
		return a.last_time < b.last_time;
	}
	return a.votes > b.votes;
}

int main() {
	ll i,j,t,n,k,m,a;
	S(n);S(k);S(m);S(a);
	vector<entry> ranklist(n);
	// vi votes(n,0);
	vector<int> ans(n,0);
	FOR(i,0,n) {
		ranklist[i].cand_id = i;
		ranklist[i].last_time = 10000;
		ranklist[i].votes = 0;
	}

	FOR(i,0,a) {
		S(j);
		// votes[j-1]++;
		ranklist[j-1].votes++;
		ranklist[j-1].last_time = i;
	}
	sort(all(ranklist), comp);

	// if all votes have been cast
	if (m == a) {

		// select the top k candidates with non-zero votes
		FOR(i,0,k) {
			if (ranklist[i].votes > 0) {
				ans[ranklist[i].cand_id] = 1;
			}
			else {
				ans[ranklist[i].cand_id] = 3;
			}
		}

		// assign 3 to all remaining candidates
		FOR(i,k,n) {
			ans[ranklist[i].cand_id] = 3;
		}

		FOR(i,0,n) {
			printf("%d ", ans[i]);
		}
		return 0;
	}

	FOR(i,0,n) {
		ll cand_id = ranklist[i].cand_id;
		ll max_votes = ranklist[i].votes + (m-a);

		j = 0;
		while (j < n && ranklist[j].votes >= max_votes) {
			j++;
		}
		
		if (j >= k) {
			ans[cand_id] = 3;
			continue;
		}
		ll diff, remaining = m-a, slide = 0;
		j = i+1;
		while (j < n && remaining > 0) {
			diff = (ranklist[i].votes - ranklist[j].votes + 1);
			if (remaining >= diff) {
				remaining -= diff;
				slide++;
			}
			else {
				break;
			}
			j++;
		}
		
		if (i + slide < k) {
			ans[cand_id] = (ranklist[i].votes == 0) ? 2 : 1;
		}
		else {
			ans[cand_id] = 2;
		}
	}

	FOR(i,0,n) {
		printf("%d ", ans[i]);
	}
	return 0;
}