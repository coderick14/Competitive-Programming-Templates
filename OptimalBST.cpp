#include <bits/stdc++.h>
#define N 10
using namespace std;

int cost[N][N], obst[N][N], prefix[N];

/*
 * function to find optimal binary search tree (with minimum cost)
 * time complexity : O(n^3)
 * space complexity : O(n^2)
 */
void findOptimalBST(int keys[], int freq[], int n) {
    int i,j,l,r;
    /*precompute prefix sums*/
    prefix[0] = freq[0];
    for(i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + freq[i];
    }

    /*
     * If key[i] is the only node in the tree, cost will be the freq[i]*1
     * since key[i] will be the root(with depth = 0) and it'll be visited freq[i] times
    */
    for(i=0; i<n; i++) {
        cost[i][i] = freq[i];
        obst[i][i] = i;   
    }
    for(l=2; l<=n; l++) {
        for(i=0; i<n-l+1; i++) {
            j = i+l-1;
            cost[i][j] = INT_MAX;
            /*Calculate cost for each element in [i,j] as the root and take the minimum*/
            for(r=i; r<=j; r++) {
                int c = ((r>i)?cost[i][r-1]:0) +
                        ((r<j)?cost[r+1][j]:0) +
                        (prefix[j] - (i-1>=0?prefix[i-1]:0));
                if(c < cost[i][j]) {
                    cost[i][j] = c;
                    obst[i][j] = r;
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    int i,n;
    cin>>n; //number of nodes in the tree
    int keys[n], freq[n];
    for(i=0; i<n; i++) {
        cin>>keys[i]>>freq[i];
    }
    findOptimalBST(keys, freq, n);
    cout<<"Optimal cost = "<<cost[0][n-1]<<endl;
    return 0;
}
