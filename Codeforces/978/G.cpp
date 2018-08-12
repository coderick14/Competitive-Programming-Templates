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
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { sll(a[i]);}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define INF 1e18
#define MOD 1000000007

using namespace std;

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct exam {
	ll idx, qp, date, prep;
};

int main() {
	ll i,j,t,n,m;
	auto comp = [](exam a, exam b) { return a.date > b.date; };
	priority_queue<exam, vector<exam>, decltype(comp)> pq(comp);
	sll(n);sll(m);
	vector<exam> exams(m);
	vi a(n+1,-1);
	FOR(i,0,m) {
		sll(exams[i].qp);
		sll(exams[i].date);
		sll(exams[i].prep);
		exams[i].idx = i+1;
		a[exams[i].date] = m+1;
	}
	sort(all(exams), [](exam a, exam b) { return a.qp < b.qp; });
	j = 0;
	FOR(i,1,n+1) {
		while(j < m && exams[j].qp <= i) {
			pq.push(exams[j]);
			j++;
		}
		if (a[i] == -1) {
			if (pq.empty()) {
				a[i] = 0;
			}
			else {
				if (pq.top().date < i) {
					break;
				}
				exam ex = pq.top();
				pq.pop();
				a[i] = ex.idx;
				ex.prep--;
				if (ex.prep > 0) {
					pq.push(ex);
				}
			}
		}
	}
	if (!pq.empty() ) {
		printf("-1\n");
	}
	else {
		FOR(i,1,n+1) {
			printf("%lld ", a[i]);
		}
	}
	return 0;
}