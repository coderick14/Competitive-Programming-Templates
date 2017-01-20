//Program to generate all primes in the range[m,n]
//seg_sieve[i] indicates whether i+m is prime or not
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll m,n;
    cin>>m>>n;
    ll rt = ceil(sqrt(n)) + 1;
    vector<bool> primes(rt + 1), seg_sieve(n - m + 1);
    for (ll i = 2; i <= rt; ++i) {
        if (primes[i]) continue;
        for (ll j = i + i; j <= rt; j += i)
            primes[j] = true;
        for (ll j = max(2LL, (m + i - 1) / i) * i; j <= n; j += i)
            seg_sieve[j - m] = true;
    }
    return 0;
}
