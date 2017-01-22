//Given N, find all primes less than N in O(N) time
#include <bits/stdc++.h>
#define ll long long
#define MAX_SIZE 100001
using namespace std;

vector<ll> prime;   //to store the primes
vector<bool> isPrime(MAX_SIZE, true);
vector<ll> SPF(MAX_SIZE);   //SPF[i] stores smallest prime factor of i

void improvedSieve(ll n) {
    ll i,j;
    isPrime[0] = isPrime[1] = false;
    for(i=2;i<n;i++) {
        if(isPrime[i]) {
            prime.push_back(i);
            SPF[i] = i; //since smallest prime factor of a prime is the prime itself
        }
        for(j=0;j<prime.size() && i*prime[j]<n && prime[j]<=SPF[i]; j++) {
            isPrime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

int main() {
    ll n;
    cin>>n;
    improvedSieve(n);
    for(ll i=0;i<prime.size();i++ ) {
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    return 0;
}
