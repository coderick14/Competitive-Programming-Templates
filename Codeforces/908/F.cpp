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

struct point {
	char color;
	ll x;
};

int main() {
	ll i,j,k,g,t,n,x,fg,lg,lastr,lastb,bigr,bigb,ans=0;
	char col;
	sll(n);
	vector<point> points(n);
	vi greens;
	FOR(i,0,n) {
		sll(points[i].x);
		cin >> points[i].color;
		if (points[i].color == 'G') {
			greens.pb(i);
		}
	}
	if (greens.size() > 1) {
		i = 0;
		while(i < greens.size()-1) {
			fg = greens[i], lg = greens[i+1];
			i += 1;
			bigb = 0, bigr = 0, lastb = points[fg].x, lastr = points[fg].x;
			FOR(j,fg+1,lg) {
				if (points[j].color == 'B') {
					//cout << points[j].x << " " << lastb << endl; 
					bigb = max(bigb, points[j].x - lastb);
					lastb = points[j].x;
				}
				if (points[j].color == 'R') {
					bigr = max(bigr, points[j].x - lastr);
					lastr = points[j].x;
				}
			}
			bigb = max(bigb, points[lg].x - lastb);
			bigr = max(bigr, points[lg].x - lastr);
			// DEBUG(bigb); DEBUG(bigr);
			ans += min(2*(points[lg].x-points[fg].x), 3*(points[lg].x-points[fg].x) - bigb - bigr);
		}
	}
	if (greens.size() > 0) {
		fg = greens[0], lg = greens.back();
		lastr = points[fg].x, lastb = points[fg].x;
		FREV(i,fg-1,0) {
			if (points[i].color == 'R') {
				ans += (lastr - points[i].x);
				lastr = points[i].x;
			}
			if (points[i].color == 'B') {
				ans += (lastb - points[i].x);
				lastb = points[i].x;
			}
		}
		lastr = lastb = points[lg].x;
		FOR(i,lg+1,points.size()) {
			if (points[i].color == 'R') {
				ans += (points[i].x - lastr);
				lastr = points[i].x;
			}
			if (points[i].color == 'B') {
				ans += (points[i].x - lastb);
				lastb = points[i].x;
			}
		}
	}
	else {
		lastr = lastb = -1;
		FOR(i,0,n) {
			if (points[i].color == 'B') {
				if (lastb != -1) {
					ans += (points[i].x - lastb);
				}
				lastb = points[i].x;
			}
			if (points[i].color == 'R') {
				if (lastr != -1) {
					ans += (points[i].x - lastr);
				}
				lastr = points[i].x;
			}
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}