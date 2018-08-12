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
#define sc(n) scanf("%c", &n)
#define INF 1000000000000007
#define MOD 1000000007

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/
string s1, s2;

ll changes(ll i, ll j) {
	if (s1[i] == s1[j] && s2[i] == s2[j]) {
		return 0;
	}
	if (s1[i] == s2[i] && s1[j] == s2[j]) {
		return 0;
	}
	if (s1[i] == s2[j] && s1[j] == s2[i]) {
		return 0;
	}
	if (s1[i] == s2[i] && s1[j] != s2[j]) {
		return 1;
	}
	if (s1[i] != s2[i] && s1[j] == s2[j]) {
		return 1;
	}
	if (s1[i] == s2[j] && s1[j] != s2[i]) {
		return 1;
	}
	if (s1[i] != s2[j] && s1[j] == s2[i]) {
		return 1;
	}
	if (s1[i] != s1[j] && s2[i] == s2[j]) {
		return 1;
	}
	return 2;
}

int main() {
	ll i,j,t,n;
	sll(n);
	cin >> s1;
	cin >> s2;
	i = 0, j = n-1;
	ll res = 0;
	while(i <= j) {
		if (i == j) {
			if (s1[i] != s2[i]) {
				res += 1;
			}
		}
		else {
			res += changes(i,j);
		}
		i++;
		j--;
	}
	printf("%lld\n", res);
	return 0;
}