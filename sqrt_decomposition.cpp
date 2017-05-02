// Solution to codeforces.com/problemset/problem/86/D using sqrt decomposition

#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001L
using namespace std;

ll block_size;

struct query {
	ll index;
	ll start;
	ll end;
    ll ans;
};

bool comp(query a, query b) {
	if(a.start/block_size != b.start/block_size) {
		return a.start/block_size < b.start/block_size;
	}
	return a.end < b.end;
}

bool compIndex(query a, query b) {
    return a.index < b.index;
}

int main() {
	ll i,n,t;
    cin>>n>>t;
	ll a[n+1];
    vector<long> freq(MAX);
    for(i=0; i<MAX; i++)
    	freq[i] = 0;
	vector<query> queries(t);
	block_size = int(sqrt(n)) + 1;
	for(i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(i=0; i<t; i++) {
		cin>>queries[i].start>>queries[i].end;
		queries[i].index = i;
        queries[i].ans = 0;
	}
	sort(queries.begin(), queries.end(), comp);
    ll currentL = queries[0].start, currentR = queries[0].end;
    for(i=currentL; i<=currentR; i++) {
        queries[0].ans += (2*freq[a[i]] + 1)*a[i];
        freq[a[i]]++;
    }

    for(i=1; i<t; i++) {
        queries[i].ans = queries[i-1].ans;

        // invrease window first
        while(currentL > queries[i].start) {
            currentL--;
            queries[i].ans += (2*freq[a[currentL]] + 1)*a[currentL];
            freq[a[currentL]]++;
        }
        while(currentR < queries[i].end) {
            currentR++;
            queries[i].ans += (2*freq[a[currentR]] + 1)*a[currentR];
            freq[a[currentR]]++;
        }

        // decrease window
        while(currentL < queries[i].start) {
            freq[a[currentL]]--;
            queries[i].ans -= (2*freq[a[currentL]] + 1)*a[currentL];
            currentL++;
        }
        while(currentR > queries[i].end) {
            freq[a[currentR]]--;
            queries[i].ans -= (2*freq[a[currentR]] + 1)*a[currentR];
            currentR--;
        }
    }
    sort(queries.begin(), queries.end(), compIndex);
    for(i=0; i<t; i++) {
        cout<<queries[i].ans<<"\n";
    }
	return 0;
}
