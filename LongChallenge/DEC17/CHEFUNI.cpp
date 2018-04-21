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
ll x,y,z,a,b,c;
ll energyABC() {
	return (x + y + z) * a;
}

ll energyBAC() {
	ll cost;
	if (x + y - z >= 0) {
		cost = ((x + y + z) / 2) * b + ((x + y + z) % 2) * a;
	}
	else {
		cost = (x + y) * b + (z - x - y) * a;
	}
	return cost;
}

ll energyCAB() {
	return (x * c + (y + z - 2*x) * a);
}

ll energyBCA() {
	ll cost;
	if (x + y - z >= 0) {
		cost = c + ((x + y + z - 3) / 2) * b + ((x + y + z - 3) % 2) * a;
	}
	else {
		cost = c + (x + y - 2) * b + (z - x - y + 1) * a;
	}
	return cost;
}

ll energyCBA() {
	// ll i, k, nx, ny, nz, cost = INF;
	// vi end_points = {x, x-1};
	// if (x + y - z > 0) {
	// 	end_points.insert(end_points.end(), {x+y-z-1, x+y-z, x+y-z+1});
	// }
	// for(i=0; i < end_points.size(); i++) {
	// 	k = end_points[i];
	// 	nx = x - k, ny = y - k, nz = z - k;
	// 	if (nx + ny -  nz >= 0) {
	// 		cost = min(cost, c * k + ((nx + ny + nz) / 2) * b + ((nx + ny + nz) % 2) * a);
	// 	}
	// 	else {
	// 		cost = min(cost, c * k + (nx + ny) * b + (nz - nx - ny) * a);
	// 	}
	// }
	// return cost;
	ll cost = c * x + (y - x) * b + (z - y) * a;
	if (a + c > 2 * b) {
		cost = cost + min(z-y, x) * 2 * b - min(z-y, x) * (a + c);
	}
	return cost;
}

int main() {
	ll i,j,t,n,cost,coords[3];
	t = read_ll();
	while (t--) {
		coords[0] = read_ll();
		coords[1] = read_ll();
		coords[2] = read_ll();
		a = read_ll();
		b = read_ll();
		c = read_ll();
		sort(coords, coords+3);
		x = coords[0];
		y = coords[1];
		z = coords[2];

		printf("%lld\n", min(energyABC(), min(energyBAC(), min(energyCAB(), min(energyBCA(), energyCBA())))));		
	}
	return 0;
}