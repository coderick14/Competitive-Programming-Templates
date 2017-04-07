#include <bits/stdc++.h>
using namespace std;

void matrixMult(int dimensions[], int n) {
    int dp[n][n];
    int i,j,k,l;

    for(i=1; i<n; i++) {
        dp[i][i] = 0;
    }
    for(l=2; l<n; l++) {
        for(i=1; i<n-l+1; i++) {
            j = i+l-1;
            dp[i][j] = INT_MAX;
            for(k=i; k<=j-1; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dimensions[i-1]*dimensions[k]*dimensions[j];
                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    cout<<"Min cost : "<<dp[1][n-1]<<endl;
}

int main() {
    int i,n;
    cin>>n;
    int dimensions[n+1];
    for(i=0; i<=n; i++) {
        cin>>dimensions[i];
    }
    matrixMult(dimensions, n+1);
    return 0;
}
