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

int main() {
    ll i,j,t,n,d,maxim,last_pop;
    t = read_ll();
    while (t--) {
        n = read_ll();
        d = read_ll();
        vi a(n+1,0), P(n+1,0);
        maxim = -INF;
        FOR(i,1,n+1) {
            a[i] = read_ll();
            P[i] = P[i-1] + a[i];
            maxim = max(maxim, a[i]);
        }
        if (d <= 0) {
            if (maxim >= d) {
                printf("1\n");
            }
            else {
                printf("-1\n");
            }
            continue;
        }
        deque<ll> q;
        q.push_back(0);
        ll ans = INF;
        FOR(i,1,n+1) {
            while (!q.empty() and (P[i] - P[q.front()]) >= d) {
                last_pop = q.front();
                // printf("Popping %lld\n", P[last_pop]);
                q.pop_front();
                ans = min(ans, i - last_pop);
            }
            while(!q.empty() and P[q.back()] >= P[i]) {
                // printf("Popping %lld\n", P[q.back()]);
                q.pop_back();
            }
            // printf("Pushing %lld\n", P[i]);
            q.push_back(i);
        }
        if (ans > n) {
            printf("-1\n");
        }
        else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}