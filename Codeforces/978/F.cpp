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

struct prog {
	ll index;
	ll skill;
};

bool comp(prog a, prog b) {
	return a.skill < b.skill;
}

int main() {
	ll i,j,t,n,k,u,v;
	sll(n);sll(k);
	vector<prog> programmers(n);
	vi skills(n);
	FOR(i,0,n) {
		programmers[i].index = i;
		sll(programmers[i].skill);
		skills[i] = programmers[i].skill;
	}
	sort(all(programmers),comp);
	vi res(n);
	res[programmers[0].index] = 0;
	FOR(i,1,n) {
		if (programmers[i].skill > programmers[i-1].skill) {
			res[programmers[i].index] = i;
		}
		else {
			res[programmers[i].index] = res[programmers[i-1].index];
		}
	}
	FOR(i,0,k) {
		sll(u);sll(v);
		u--;v--;
		if (skills[u] > skills[v]) {
			res[u]--;
		}
		else if (skills[v] > skills[u]) {
			res[v]--;
		}
	}
	FOR(i,0,n) {
		printf("%lld ", res[i]);
	}
	return 0;
}