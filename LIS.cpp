#include <bits/stdc++.h>
#define ll long long
using namespace std;

void printLIS(vector<ll> &a, vector<ll> &prev, int pos) {
    if(pos<0)
        return;
    printLIS(a, prev, prev[pos]);
    cout<<a[pos]<<" ";
}

void LIS(vector<ll> &a) {
    int i,j,maxim = 0,n = a.size();
    vector<ll> LIS(n,1);
    vector<ll> prev(n,-1);
    for(i=0; i<n; i++) {
        for(j=0; j<i; j++) {
            if(a[i] > a[j] && LIS[i] < LIS[j]+1) {
                LIS[i] = LIS[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    for(i=0; i<n; i++) {
        if(LIS[i] > maxim) {
            maxim = LIS[i];
            pos = i;
        }
    }
    cout<<"Length of LIS = "<<maxim<<endl;
    printLIS(a,prev,pos);
    cout<<endl;
}

int main() {
    ll i,n;
    cin>>n;
    vector<ll> a(n);
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    LIS(a);
    return 0;
}
