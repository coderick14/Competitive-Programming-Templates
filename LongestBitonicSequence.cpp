#include <bits/stdc++.h>
using namespace std;

void printLIS(vector<int> &a, vector<int> &prev, int pos) {
    if(pos<0)
        return;
    printLIS(a, prev, prev[pos]);
    cout<<a[pos]<<" ";
}

void printLDS(vector<int> &a, vector<int> &next, int pos, int n) {
    if(pos>=n)
        return;
    cout<<a[pos]<<" ";
    printLDS(a, next, next[pos],n);
}

int main() {
    int i,j,n,pos;
    cin>>n;
    vector<int> a(n), LIS(n), LDS(n);
    vector<int> prev(n,-1), next(n,n);
    for(i=0; i<n; i++) {
        cin>>a[i];
        LIS[i] = LDS[i] = 1;
    }

    for(i=1; i<n; i++) {
        for(j=0; j<i; j++) {
            if(a[j]<a[i] && LIS[i]<LIS[j]+1) {
                LIS[i] = LIS[j] + 1;
                prev[i] = j;
            }
        }
    }

    for(i=n-2; i>=0; i--) {
        for(j=n-1; j>i; j--) {
            if(a[i]>a[j] && LDS[i]<LDS[j]+1) {
                LDS[i] = LDS[j] + 1;
                next[i] = j;
            }
        }
    }

    int maxim = LIS[0] + LDS[0] - 1;
    pos = 0;
    for(i=1; i<n; i++) {
        if(LIS[i] + LDS[i] - 1 > maxim) {
            maxim = LIS[i] + LDS[i] - 1;
            pos = i;
        }
    }
    cout<<maxim<<"\n";
    printLIS(a,prev,pos);
    printLDS(a,next,next[pos],n);
    cout<<endl;
    return 0;
}
