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
	ll i,j,t,n,q,k,index,start_index,end_index,block_size,blocks,block_num,lazy_diff,new_val,type,ans;
	n = read_ll();
	q = read_ll();
	vi a(n,0), as(n,0);
	FOR(i,0,n) {
		a[i] = read_ll();
		as[i] = a[i];
	}
	FOR(i,1,n) {
		a[i] ^= a[i-1];
	}
	block_size = blocks = ceil(sqrt(n));
	vi buckets[blocks];
	vi lazy(blocks,0);
	FOR(i,0,blocks) {
		FOR(j, i * block_size, min(n, (i+1) * block_size)) {
			// printf("Pushing a[%lld] into bucket[%lld]\n", j, i);
			buckets[i].pb(a[j]);
		}
		sort(all(buckets[i]));
	}
	// FOR(i,0,blocks) {
	// 	FOR(j,0,buckets[i].size()) {
	// 		printf("%lld ", buckets[i][j]);
	// 	}
	// 	printf("\n");
	// }
	while (q--) {
		type = read_ll();

		/*
		 * type = 1 ==> update the value at index to new_val
		 * type = 2 ==> number of prefixes ending at <= index with xor = k 
		 */

		if (type == 1) {
			index = read_ll();
			new_val = read_ll();
			index -= 1;
			lazy_diff = as[index] ^ new_val;
			as[index] = new_val;

			block_num = index / block_size;
			start_index = index % block_size;

			if (start_index > 0) {
				FOR(i,block_num * block_size + start_index, min(n, (block_num+1) * block_size)) {
					a[i] ^= lazy_diff;
				}
				FOR(j,0,buckets[block_num].size()) {
					buckets[block_num][j] = a[block_num * block_size + j];
				}
				sort(all(buckets[block_num]));
			}
			else {
				lazy[block_num] ^= lazy_diff;
			}

			FOR(i,block_num+1,blocks) {
				lazy[i] ^= lazy_diff;
			}
			// FOR(i,0,blocks) {
			// 	printf("Bucket[%lld] Lazy = %lld\n", i, lazy[i]);
			// 	FOR(j,0,buckets[i].size()) {
			// 		printf("%lld ", buckets[i][j]);
			// 	}
			// 	printf("\n");
			// }
		}
		else {
			index = read_ll();
			k = read_ll();
			index -= 1;
			block_num = index / block_size;
			end_index = index % block_size;
			ans = 0;
			FOR(j,0,end_index+1) {
				// printf("a[%lld] = %lld  | k^lazy = %lld\n", block_num * block_size + j, a[block_num * block_size + j], k ^ lazy[block_num]);
				if (a[block_num * block_size + j] == (k ^ lazy[block_num])) {
					ans++;
				}
			}
			// printf("ans = %lld after searching for %lld in block %lld\n", ans, k^lazy[block_num], block_num);
			FOR(i,0,block_num) {
				ll first_occurence = lower_bound(all(buckets[i]), (k ^ lazy[i])) - buckets[i].begin();
				ll last_occurence = upper_bound(all(buckets[i]), (k ^ lazy[i])) - buckets[i].begin();
				ans += (last_occurence - first_occurence);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}